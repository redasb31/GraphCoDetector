import os
import json

def generate_function_level_graphs(graph_json):
    graphs = []
    functions = graph_json['functions']
    for i,function in enumerate(functions):
        start,end = int(function["idx"].split(':')[0]),int(function["idx"].split(':')[1])
        for node in function['nodes'].keys():
            node_start,node_end = int(function["nodes"][node]["idx"].split(':')[0]),int(function["nodes"][node]["idx"].split(':')[1])
            new_idx = str(node_start-start)+':'+str(node_end-start)
            function['nodes'][node]['idx'] = new_idx
        code = graph_json['code'][start:end+1]
        G = {"nodes":function['nodes'],"edges":function['edges'],"code":code,"label":graph_json['label']}
        graphs.append(G)
    return graphs
        


def generate_function_level_graphs_directory(graph_dir,outdir):
    graphs_files_list = sorted([f for f in os.listdir(graph_dir) if f.endswith('.json')]) 
    for graph_file in graphs_files_list:
        with open(os.path.join(graph_dir,graph_file)) as f:
            graph = json.load(f)
        function_level_graphs = generate_function_level_graphs(graph)
        for i,graph in enumerate(function_level_graphs):
            with open(os.path.join(outdir,graph_file.replace('.json','_'+str(i).zfill(2)+'.json')),'w') as f:
                json.dump(graph,f)


if __name__ == '__main__':
    generate_function_level_graphs_directory('graphs','function_level_graphs')
        

