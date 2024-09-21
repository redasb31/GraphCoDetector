#include <stdio.h>
#include <stdlib.h>
int a[200000], b[200000];
int *tree[200000], *tree_d[200000], cnt[200000], cnts[200000];
int n;
int DFS(int x, int y){//xが今いる頂点，yが前にいた頂点
    //2つの値を求める，tree[x][x_cnt] = y, tree[y][y_cnt] = xとなる
    //x_cnt, y_cnt
    int i;
    int x_cnt, y_cnt;
    for(i = 0; i < cnt[x]; i++){
        if(tree[x][i] == y){
            x_cnt = i;
            break;
        }
    }
    
    for(i = 0; i < cnt[y]; i++){
        if(tree[y][i] == x){
            y_cnt = i;
            break;
        }
    }
    
    tree_d[x][x_cnt] = 1;
    for(i = 0; i < cnt[x]; i++){
        if(tree[x][i] == y){
            continue;
        }
        tree_d[x][x_cnt] += DFS(tree[x][i], x);
    }

    tree_d[y][y_cnt] = n - tree_d[x][x_cnt];
    return tree_d[x][x_cnt];
}

int main(void){
    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        cnt[i] = 0;
        cnts[i] = 0;
    }

    for(i = 0; i < n - 1; i++){
        scanf("%d%d", &a[i], &b[i]);
        a[i]--;
        b[i]--;
        cnt[a[i]]++;
        cnt[b[i]]++;
    }

    for(i = 0; i < n; i++){
        tree[i] = (int *)malloc(sizeof(int) * (cnt[i] + 1));
        if(tree[i] == NULL){
            return 0;
        }
    }
    for(i = 0; i < n; i++){
        tree_d[i] = (int *)malloc(sizeof(int) * (cnt[i] + 1));
        if(tree_d[i] == NULL){
            return 0;
        }
    }
    for(i = 0; i < n; i++){
        tree[a[i]][cnts[a[i]]] = b[i];
        tree[b[i]][cnts[b[i]]] = a[i];
        tree_d[a[i]][cnts[a[i]]] = -1;
        tree_d[b[i]][cnts[b[i]]] = -1;
        cnts[a[i]]++;
        cnts[b[i]]++;
    }

    DFS(a[0], b[0]);
    DFS(b[0], a[0]);



}