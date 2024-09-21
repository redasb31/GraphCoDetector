#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os, torch, random
from tqdm import tqdm, trange
import torch.nn as nn
import torch.optim as optim
from sklearn.metrics import accuracy_score, precision_recall_fscore_support

from utils.data import load_graphs
from model import GraphCoDetector
from parameters import parse_args, IOStream, table_printer


def train(args, IO, train_loader, num_node_features, num_edge_features):
    """Train the model"""
    device = torch.device('cpu' if args.gpu_index<0  else 'cuda:{}'.format(args.gpu_index))
    if args.gpu_index < 0:
        IO.cprint('Using CPU')
    model = GraphCoDetector(args, num_node_features, num_edge_features).to(device)
    # model = torch.load('outputs/%s/model.pth' % args.exp_name).to(device)
    IO.cprint(str(model))
    total_params = sum(p.numel() for p in model.parameters() if p.requires_grad)
    IO.cprint('Model Parameter: {}'.format(total_params))

    optimizer = optim.AdamW(model.parameters(), lr=args.lr)
    IO.cprint('Using AdamW')

    # Use BCEWithLogitsLoss
    criterion = nn.BCELoss(reduction="mean")

    epochs = trange(args.epochs, leave=True, desc="Epochs")
    for epoch in epochs:
        #################
        ###   Train   ###
        #################
        model.train()
        train_loss = 0.0

        for i, data in tqdm(enumerate(train_loader), total=len(train_loader), desc="Train_Loader"):
            data = data.to(device)
            optimizer.zero_grad()
            outputs = model(data)
            loss = criterion(outputs, data.y.float())
            with open('res.txt','a') as f :
                f.write(str(outputs)+' -- '+str(data.y.float())+'\n')
            loss.backward()
            nn.utils.clip_grad_norm_(parameters=model.parameters(), max_norm=1.0)
            optimizer.step()

            train_loss += loss.item()

        IO.cprint('Epoch #{:03d}, Train_Loss: {:.6f}'.format(epoch, train_loss / len(train_loader.dataset)))

    torch.save(model, 'outputs/%s/model.pth' % args.exp_name)
    IO.cprint('The current best model is saved in: {}'.format('******** outputs/%s/model.pth *********' % args.exp_name))


def test(args, IO, test_loader):
    """Test the model"""
    device = torch.device('cpu' if args.gpu_index<0  else 'cuda:{}'.format(args.gpu_index))

    IO.cprint('')
    IO.cprint('********** TEST START **********')
    IO.cprint('Reload Best Model')
    IO.cprint('The current best model is saved in: {}'.format('******** outputs/%s/model.pth *********' % args.exp_name))

    # Load the best model
    model = torch.load('outputs/%s/model.pth' % args.exp_name).to(device)
    model.eval()

    # Initialize metrics
    all_preds = []
    all_labels = []
    test_loss = 0.0
    criterion = nn.BCELoss(reduction="mean")

    with torch.no_grad():
        for data in tqdm(test_loader, desc="Test_Loader"):
            data = data.to(device)
            outputs = model(data)
            loss = criterion(outputs, data.y.float())

            test_loss += loss.item()

            # Collect predictions and labels
            preds = outputs.cpu().numpy()
            labels = data.y.cpu().numpy()

            all_preds.extend(preds)
            all_labels.extend(labels)

    # Compute metrics
    float_preds = [p for p in all_preds]
    all_preds = [1 if p > 0.5 else 0 for p in all_preds]
    accuracy = accuracy_score(all_labels, all_preds)
    print([(all_labels[k],all_preds[k]) for k in range(len(all_preds))])
    precision, recall, f1, _ = precision_recall_fscore_support(all_labels, all_preds, average='binary')


    IO.cprint('TEST :: Test_Loss: {:.6f}'.format(test_loss / len(test_loader.dataset)))
    IO.cprint('Accuracy: {:.6f}'.format(accuracy))
    IO.cprint('Precision: {:.6f}'.format(precision))
    IO.cprint('Recall: {:.6f}'.format(recall))
    IO.cprint('F1 Score: {:.6f}'.format(f1))


def exp_init():
    if not os.path.exists('outputs'):
        os.mkdir('outputs')
    if not os.path.exists('outputs/' + args.exp_name):
        os.mkdir('outputs/' + args.exp_name)

    os.system('cp main.py outputs' + '/' + args.exp_name + '/' + 'main.py.backup')
    os.system('cp utils/data.py outputs' + '/' + args.exp_name + '/' + 'data.py.backup')
    os.system('cp layer.py outputs' + '/' + args.exp_name + '/' + 'layer.py.backup')
    os.system('cp model.py outputs' + '/' + args.exp_name + '/' + 'model.py.backup')
    os.system('cp parameters.py outputs' + '/' + args.exp_name + '/' + 'parameter.py.backup')


if __name__ == '__main__':
    args = parse_args()
    random.seed(args.seed) 
    torch.manual_seed(args.seed)  
    exp_init()

    root_dir = os.path.join("..","Data","graphs")

    IO = IOStream('outputs/' + args.exp_name + '/run.log')
    IO.cprint(str(table_printer(args))) 

    train_loader, test_loader, num_node_features, num_edge_features = load_graphs(args,root_dir=root_dir)
    train(args, IO, train_loader, num_node_features, num_edge_features)
    test(args, IO, test_loader)