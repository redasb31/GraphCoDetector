import torch
from torch_geometric.data import Data, Dataset
from torch_geometric.loader import DataLoader
from sklearn.model_selection import train_test_split
import json
import os
from .node_embedding import get_initial_embedding_cpg_node
import pickle

class GraphDataset(Dataset):
    def __init__(self, root_dir, save_dir = "pickle_data",function_level=False):
        self.l = 3000
        self.save_dir = save_dir
        self.graph_files = [os.path.join(root_dir, f) for f in os.listdir(root_dir) if f.endswith('.json')][:self.l]
        self.saved_files = [f.split("/")[-1].split('.')[0] for f in os.listdir(save_dir)]
        self.function_level = function_level

    def __len__(self):
        return len(self.graph_files)

    def __getitem__(self, idx):
        print(idx)

        fname = self.graph_files[idx].split("/")[-1].split('.')[0]
        fpath = os.path.join(self.save_dir,fname+'.pkl')

        if fname in self.saved_files:
            graph = pickle.load(open(fpath, 'rb'))
            
        else:
            self.saved_files.append(fname)
            graph_json = json.load(open(self.graph_files[idx]))
            graph = create_graph(graph_json,function_level = self.function_level)
            pickle.dump(graph, open(fpath, 'wb'))

        return graph 

def add_vnode(graph_json):
    Vnode = {"VNode":{"type":"VNode","idx":"VNode_idx"}}
    nodes_keys = graph_json["nodes"].keys()
    new_edges = [{'edge':[key,"VNode"],'type':'000'} for key in nodes_keys]
    edges = graph_json['edges'] + new_edges
    graph_json['nodes'].update(Vnode)
    graph_json['edges'] = edges

    

def merge_functions(graph_json):
    nodes_keys=[]
    nodes = {}
    edges = []
    for func in graph_json['functions']:
        keys = func['nodes'].keys()
        nodes_keys.extend(keys)
        edges.extend(func['edges'])
        nodes.update(func['nodes'])
        
    
    assert len(nodes_keys) == len(set(nodes_keys)) # Check for duplicate nodes keys
    assert len(edges) == len(set([(edge['edge'][0], edge['edge'][1]) for edge in edges]))

    return {'nodes': nodes, 'edges': edges,'label': graph_json['label'],"code":graph_json['code']}

def create_graph(graph_json,function_level = False):

    if not function_level:
        graph_json = merge_functions(graph_json)


    add_vnode(graph_json)
    
    code = graph_json['code']

    nodes, edges = graph_json['nodes'], graph_json['edges']

    # Create a mapping from node_key to an index
    node_map = {key: i for i, key in enumerate(nodes.keys())}

    # Create edge_index
    edge_index = torch.tensor([[node_map[edge['edge'][0]], node_map[edge['edge'][1]]] for edge in edges], dtype=torch.long).t().contiguous()

    tmp =[get_initial_embedding_cpg_node(nodes[node_key],code) for node_key in nodes.keys()]

    x,w = [i[0] for i in tmp],[i[1] for i in tmp]

    x = torch.stack(x)

    w = torch.tensor(w)

    # Encode edge types using one-hot encoding
    edge_types = torch.zeros(edge_index.size(1), 8)
    for i, edge in enumerate(edges):
        edge_types[i, int(edge['type'], 2)] = 1
    
    # Target label
    y = torch.tensor([graph_json['label']], dtype=torch.long).unsqueeze(-1)
    
    return Data(x=x, edge_index=edge_index, edge_attr=edge_types, y=y, w=w, code = code)

def load_graph_data(root_dir='all_data', batch_size=16, seed=16, num_workers=0,function_level=False):
    # Create the dataset
    dataset = GraphDataset(root_dir,function_level=function_level)

    # Split the dataset into training and test sets
    train_dataset, test_dataset = train_test_split(dataset, test_size=0.2, random_state=seed)

    # Create DataLoader for training and testing
    train_loader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True, num_workers=num_workers)
    test_loader = DataLoader(test_dataset, batch_size=batch_size, shuffle=False, num_workers=num_workers)

    num_node_features = dataset[0].x.size(1)
    num_edge_features = dataset[0].edge_attr.size(1)

    print('Number of node features:', num_node_features)
    print('Number of edge features:', num_edge_features)

    return train_loader, test_loader, num_node_features, num_edge_features

def load_graphs(args,root_dir='all_data'):
    return load_graph_data(batch_size=args.train_batch_size, seed=args.seed, root_dir=root_dir, function_level=args.function_level)

if __name__ == '__main__':
    train_loader, test_loader = load_graph_data('all_data', batch_size=16, seed=42)
    for batch in train_loader:
        print(batch)