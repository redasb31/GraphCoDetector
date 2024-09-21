import sys 
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__),'cpg/')))
from cpg.ccpg.cpg.cpg_api import *
import json

def generate_cpg_for_file(c_fname:str,label = 0) -> list:
    """
    Generate CPG for a single file.

    Args:
        c_fname: the path of C source file.

    Returns:
        graph: dictionary containing the CPG graph.
    """
    funcions_cpgs = cpg4singlefile(c_fname)
    fun_graphs = []
    for i,function in enumerate(funcions_cpgs):
        function_graph ,start,end = function
        nodes = {}
        edges = []
        for node in function_graph.nodes:
            start_idx = function_graph.nodes[node]['cpg_node'].start_idx
            end_idx = function_graph.nodes[node]['cpg_node'].end_idx
            node_type = function_graph.nodes[node]['cpg_node'].node_type
            node_dict = {'type':node_type, "idx" : f"{start_idx}:{end_idx}"}
            nodes[str(node)] = node_dict
        for edge in function_graph.edges:

            edge_type = function_graph[edge[0]][edge[1]]['edge_type']
            edge_dict = {'edge':(edge[0],edge[1]), 'type':edge_type}
            edges.append(edge_dict)
        fun_graph = {'nodes':nodes, 'edges':edges, "idx" : f"{start}:{end}"}
        fun_graphs.append(fun_graph)

    graph = {'functions':fun_graphs, 'code':open(c_fname).read(), 'label':label}
    return graph
    
def generate_json(c_fname:str,c_out:str=None,label = 0):
    """
    Generate CPG for a single file and save it as a json file.

    Args:
        c_fname: the path of C source file.

    Returns:
        graph: dictionary containing the CPG graph.
    """
    graph = generate_cpg_for_file(c_fname,label=label)

    if c_out==None:
        c_out = c_fname.split('.')[0]+'.json'
    with open(c_out, 'w') as f:
        json.dump(graph, f)
    return graph

def generate_json_from_code(code:str,c_out:str=None):
    """
    Generate CPG for a code snippet and save it as a json file.

    Args:
        code: the code snippet.
        c_out: the path of the json file to save the CPG.

    Returns:
        graph: the CPG graph.
    """
    with open('temp.c', 'w') as f:
        f.write(code)
    graph = generate_json('temp.c',c_out)
    os.remove('temp.c')
    return graph

def generate_cpg_for_dir(directory:str,out_dir:str,label = 0):
    """
    Generate CPG for all files in a directory and save them as json files.

    Args:
        dir: the path of the directory containing C source files.
        out_dir: the path of the directory to save the json files.

    Returns:
        None
    """
    for file in os.listdir(directory):
        if file.endswith('.c'):
            c_fname = os.path.join(directory, file)
            generate_json(c_fname,os.path.join(out_dir, file.split('.')[0]+'.json'),label)
    return True



if __name__ == '__main__':
    
    generate_json_from_code('int main(){int a = 1; return 0;}')



