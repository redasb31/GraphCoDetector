#!/usr/bin/env python
# -*- coding: utf-8 -*-
from texttable import Texttable

class Args:
    def __init__(self):
        self.seed = 2025
        self.exp_name = 'Func_level'
        self.train_batch_size = 1
        self.test_batch_size = 1
        self.gpu_index = -1
        self.epochs = 10
        self.lr = 0.001
        self.num_layers = 3
        self.node_dim = 128
        self.edge_dim = 32
        self.num_heads = 3
        self.max_in_degree = 25
        self.max_out_degree = 25
        self.max_weight = 30
        self.max_path_distance = 6
        self.scrm_out_dim = 128
        self.function_level=True

def parse_args():
    args = Args()
    return args


class IOStream():
    def __init__(self, path):
        self.file = open(path, 'a')

    def cprint(self, text):
        print(text)
        self.file.write(text + '\n')
        self.file.flush() 

    def close(self):
        self.file.close()


def table_printer(args):
    args = vars(args)
    keys = sorted(args.keys()) 
    table = Texttable()
    table.set_cols_dtype(['t', 't']) 
    rows = [["Parameter", "Value"]]
    for k in keys:
        rows.append([k.replace("_", " ").capitalize(), str(args[k])]) 
    table.add_rows(rows)
    return table.draw()