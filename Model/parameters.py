#!/usr/bin/env python
# -*- coding: utf-8 -*-
from texttable import Texttable

class Args:
    def __init__(self):
        self.seed = 1337
        self.exp_name = 'Experiment'
        self.train_batch_size = 4
        self.test_batch_size = 4
        self.gpu_index = -1
        self.epochs = 50
        self.lr = 0.001
        self.num_layers = 3
        self.node_dim = 128
        self.edge_dim = 128
        self.num_heads = 3
        self.max_in_degree = 50
        self.max_out_degree = 50
        self.max_weight = 30
        self.max_path_distance = 6
        self.scrm_out_dim = 128

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