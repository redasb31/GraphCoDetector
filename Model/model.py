
from typing import Union, Tuple, Dict, List

import torch
import networkx as nx
from torch import nn
from torch_geometric.data import Data
from torch_geometric.nn import global_mean_pool
from torch_geometric.utils.convert import to_networkx
from SCRM import SCRM

from layer import GTEncoderLayer, CentralityEncoding, WeightEncoding, SpatialEncoding
from utils.distance import *


class MLP(nn.Module):
    def __init__(self, input_size, hidden_sizes = [64, 32], output_size=1):
        super(MLP, self).__init__()
        self.layers = nn.ModuleList()
        self.layers.append(nn.Linear(input_size, hidden_sizes[0]))
        self.layers.append(nn.ReLU())
        for i in range(1, len(hidden_sizes)):
            self.layers.append(nn.Linear(hidden_sizes[i-1], hidden_sizes[i]))
            self.layers.append(nn.ReLU())  

        self.layers.append(nn.Linear(hidden_sizes[-1], output_size))
        self.sigmoid = nn.Sigmoid()

    def forward(self, x):
        for layer in self.layers:
            x = layer(x)
        x = self.sigmoid(x)
        return x


class GCRM(nn.Module):
    def __init__(self, args, num_node_features, num_edge_features):
        """
        :param num_layers: number of GT layers
        :param input_node_dim: input dimension of node features
        :param node_dim: hidden dimensions of node features
        :param input_edge_dim: input dimension of edge features
        :param edge_dim: hidden dimensions of edge features
        :param output_dim: number of output node features
        :param n_heads: number of attention heads
        :param max_in_degree: max in degree of nodes
        :param max_out_degree: max out degree of nodes
        :param max_path_distance: max pairwise distance between two nodes
        """
        super().__init__()

        self.num_layers = args.num_layers
        self.input_node_dim = num_node_features
        self.node_dim = args.node_dim
        self.input_edge_dim = num_edge_features
        self.edge_dim = args.edge_dim
        self.num_heads = args.num_heads
        self.max_in_degree = args.max_in_degree
        self.max_out_degree = args.max_out_degree
        self.max_path_distance = args.max_path_distance
        self.max_weight = args.max_weight

        self.node_in_lin = nn.Linear(self.input_node_dim, self.node_dim)
        self.edge_in_lin = nn.Linear(self.input_edge_dim, self.edge_dim)

        self.centrality_encoding = CentralityEncoding(
            max_in_degree=self.max_in_degree,
            max_out_degree=self.max_out_degree,
            node_dim=self.node_dim
        )

        self.weight_encoding = WeightEncoding(
            max_weight=self.max_weight,
            node_dim=self.node_dim
            )

        self.spatial_encoding = SpatialEncoding(
            max_path_distance=self.max_path_distance,
        )

        self.layers = nn.ModuleList([
            GTEncoderLayer(
                node_dim=self.node_dim,
                edge_dim=self.edge_dim,
                num_heads=self.num_heads,
                max_path_distance=self.max_path_distance) for _ in range(self.num_layers)
        ])


    def forward(self, data: Union[Data]) -> torch.Tensor:
        """
        :param data: input graph of batch of graphs
        :return: torch.Tensor, output node embeddings
        """
        x = data.x.float()
        weights = data.w.float()
        edge_index = data.edge_index.long()
        edge_attr = data.edge_attr.float()

        if type(data) == Data:
            ptr = None
            node_paths, edge_paths = shortest_path_distance(data)
        else:
            ptr = data.ptr
            node_paths, edge_paths = batched_shortest_path_distance(data)

        x = self.node_in_lin(x)
        edge_attr = self.edge_in_lin(edge_attr)

        x = self.centrality_encoding(x, edge_index)
        x = self.weight_encoding(x, weights)
        b = self.spatial_encoding(x, node_paths)

        for layer in self.layers:
            x = layer(x, edge_attr, b, edge_paths, ptr)


        x = x[-1].unsqueeze(0)

        return x
    
class GraphCoDetector(nn.Module):
    def __init__(self, args, num_node_features, num_edge_features):
        """
        :param num_layers: number of GT layers
        :param input_node_dim: input dimension of node features
        :param node_dim: hidden dimensions of node features
        :param input_edge_dim: input dimension of edge features
        :param edge_dim: hidden dimensions of edge features
        :param output_dim: number of output node features
        :param n_heads: number of attention heads
        :param max_in_degree: max in degree of nodes
        :param max_out_degree: max out degree of nodes
        :param max_path_distance: max pairwise distance between two nodes
        """
        super().__init__()


        self.scrm_out_dim = args.scrm_out_dim
        self.mlp_input_dimension = self.scrm_out_dim + args.node_dim
        self.GCRM = GCRM(args,num_node_features=num_node_features,num_edge_features=num_edge_features) 
        self.SCRM = SCRM
        self.SCRM_out_lin =  nn.Linear(768 * 2,self.scrm_out_dim )
        self.Classifier = MLP(input_size=self.mlp_input_dimension,output_size=1)

    def forward(self, data: Union[Data]) -> torch.Tensor:
        """
        Forward pass of the GraphCoDetector model.

        :param data: Input graph data (instance of `torch_geometric.data.Data`)
        :return: Predicted probability (tensor with shape [batch_size, 1])
        """
        # Get graph embeddings from GCRM
        x = self.GCRM(data)

        # Get sequence embeddings from SCRM
        xc = self.SCRM(data.code)

        xc = self.SCRM_out_lin(xc)

        x = torch.cat((xc,x), dim=1)
        with open('cat.txt','a') as f:
            f.write(str(x))

        # Pass combined features through the final MLP
        x = self.Classifier(x)

        return x




        
            
