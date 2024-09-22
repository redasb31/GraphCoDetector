from transformers import RobertaTokenizer, RobertaModel
import torch
import re

# Load pretrained CodeBERT model and tokenizer
tokenizer = RobertaTokenizer.from_pretrained("microsoft/codebert-base")
model = RobertaModel.from_pretrained("microsoft/codebert-base")
embedding_size = model.config.hidden_size

def get_embedding(code):
    
    inputs = tokenizer(code, return_tensors="pt")
    input_ids = inputs["input_ids"].squeeze(0)
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
    return embedding

def extract_comments(c_code):
  """Extracts comments from C code.

  Args:
    c_code: The C code string.

  Returns:
    A list of extracted comments.
  """

  # Regular expressions for different types of comments
  single_line_comment_pattern = r"//.*"
  multi_line_comment_pattern = r"/\*(.*?)\*/"

  # Find all comments using the regular expressions
  single_line_comments = re.findall(single_line_comment_pattern, c_code)
  multi_line_comments = re.findall(multi_line_comment_pattern, c_code, re.DOTALL)

  # Combine both types of comments into a single list
  comments = single_line_comments + multi_line_comments

  code_without_comments = re.sub(r"//.*|/\*(.|\n)*?\*/", "", c_code)

  return ''.join(comments) , code_without_comments

def SCRM(code_list):
  """
  Extracts and processes code and comment embeddings for a batch of code.

  Args:
      code_list: A list of strings containing the C code snippets.

  Returns:
      A torch.Tensor of shape (batch_size, embedding_dim) containing the concatenated 
      code and comment embeddings for each code snippet in the batch.
  """

  embeddings = []
  for code in code_list:
        comments, code_without_comments = extract_comments(code)
        code_embedding = get_embedding(code_without_comments)
        if len(comments.strip()) == 0:
            comments_embedding = torch.zeros(embedding_size)
        else:
            comments_embedding = get_embedding(comments)
        embedding = torch.cat([code_embedding, comments_embedding])
        embeddings.append(embedding)

  return torch.stack(embeddings)

if __name__ == "__main__":
    code = open('utils/example.c').read()
    scrm = SCRM(code)
    # print(scrm)

    
