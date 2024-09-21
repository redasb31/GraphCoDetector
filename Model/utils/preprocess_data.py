from node_embedding import get_initial_embedding_cpg_node
from data import create_graph
import json
import os


def preprocess_dir(from_dir = "all_data", to_dir = "preprocessed_data"):
    files_list =  os.listdir(from_dir)
    for i,fname in enumerate(files_list):
        print(f'Processing {i+1}/{len(files_list)}')
        
        #check if os.path.join(to_dir, fname) exists:
        if os.path.exists(os.path.join(to_dir, fname)):
            continue

        if fname.endswith('.json'):
            graph_json = json.load(open(os.path.join(from_dir, fname)))
            for node in graph_json['nodes'].keys():
                graph_json['nodes'][node]['node_code'] = get_initial_embedding_cpg_node(graph_json['nodes'][node]).tolist()
            with open(os.path.join(to_dir, fname), 'w') as f:
                json.dump(graph_json, f)

if __name__ == "__main__":
    preprocess_dir()


