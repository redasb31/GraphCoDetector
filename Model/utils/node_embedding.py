from transformers import RobertaTokenizer, RobertaModel
import torch

# Load pre-trained CodeBERT model and tokenizer
model_name = "microsoft/codebert-base"
tokenizer = RobertaTokenizer.from_pretrained(model_name)
model = RobertaModel.from_pretrained(model_name)

node_types= ['function_definition', 'function_declarator', 'compound_statement', 'ret_type', 'identifier', 'parameter_list', 'declaration', 'while_statement', 'parameter_declaration', 'primitive_type', 'init_declarator', 'while', 'parenthesized_expression', 'array_declarator', 'pointer_declarator', '=', 'binary_expression', 'if_statement', 'number_literal', '*', '<', 'if', 'else', 'expression_statement', 'for_statement', 'switch_statement', 'subscript_expression', '==', 'char_literal', 'call_expression', 'update_expression', 'for', 'assignment_expression', 'switch', 'argument_list', '++', 'case_statement', '+', '!=', '&&', 'case', 'break_statement', '-', '>=', '<=', 'break', '--', 'return_statement', 'return', 'string_literal', 'pointer_expression', '&', 'type_identifier', 'field_expression', 'field_identifier', 'sizeof_expression', 'conditional_expression', 'sizeof', 'type_descriptor', '+=', '>', 'sized_type_specifier', 'struct_specifier', '/', '%', 'long', 'struct', 'null', '||', 'type_qualifier', 'cast_expression', 'const', 'abstract_pointer_declarator', 'true', 'false', 'comma_expression', '%=', '^', '&=', 'unary_expression', '!', 'initializer_list', '/=', '<<', '-=', 'continue_statement', 'continue', '*=', 'default', 'compound_literal_expression', 'unsigned', '~', 'labeled_statement', 'statement_identifier', 'goto_statement', 'goto', '>>', '^=', 'abstract_function_declarator', 'abstract_parenthesized_declarator', '|', '>>=', 'initializer_pair', 'field_designator', 'do_statement', 'do', '|=', 'storage_class_specifier', 'static','unknown','VNode']


def get_embedding(code):
    
    inputs = tokenizer(code, return_tensors="pt")
    input_ids = inputs["input_ids"].squeeze(0)
    weight = len(inputs["input_ids"].squeeze(0)) // 6
    attention_mask = inputs["attention_mask"].squeeze(0)

    chunk_size = 512
    stride = 256

    embeddings = []
    with torch.no_grad():
        for i in range(0, len(input_ids), stride):
            
            chunk_input_ids = input_ids[i:i+chunk_size]
            chunk_attention_mask = attention_mask[i:i+chunk_size]

            if chunk_input_ids.size(0) == 0:
                break

            chunk_inputs = {
                "input_ids": chunk_input_ids.unsqueeze(0),
                "attention_mask": chunk_attention_mask.unsqueeze(0)
            }
            outputs = model(**chunk_inputs,output_hidden_states=True)
            last_hidden_states = outputs.hidden_states[-1]
            chunk_embeddings = last_hidden_states[0,0,:].unsqueeze(0)
            embeddings.append(chunk_embeddings)

    # Aggregate embeddings (e.g., by averaging)
    embedding = torch.mean(torch.cat(embeddings), 0)

    return embedding,weight

def get_initial_embedding_cpg_node(cpg_node,source_code):
    code = "None"
    if isinstance(cpg_node, dict):
        start,end = [int(i) for i in cpg_node.get('idx', "0:0").split(':')]
        code = source_code[start:end]

        if code == "" or code ==" ":
            code = "None"
        node_type = cpg_node['type']
    else:
        raise ValueError

    code_embedding,weight = get_embedding(code)
    if node_type in node_types:
        node_type_index = node_types.index(node_type)
    else:
        node_type_index = node_types.index('unknown')

    node_type_embedding = torch.zeros(len(node_types))
    node_type_embedding[node_type_index] = 1
    embedding = torch.cat((code_embedding, node_type_embedding))

    return embedding , weight


if __name__ == '__main__':
    node = {"type": "function_definition", "idx": "20:121"}
    code = "#include <stdio.h>\n\nint main() {\n  // Print \"Hello World\" to standard output.\n  printf(\"Hello World\\n\"); \n\n  return 0; \n}"

    x, weight = get_initial_embedding_cpg_node(node,code)
    print(x)
    print(weight)
