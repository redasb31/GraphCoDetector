#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int compare0(int **a, int **b) {
    return *(*a) - *(*b);
}

int compare1(int **a, int **b) {
    return *(*a+1) - *(*b+1);
}

typedef struct node {
    bool checked;
    int num;
    struct node **next;
    int num_next;
} Node;

Node *init_node(int n, int i) {
    Node *a = (Node *)malloc(sizeof(Node));
    a->checked = false;
    a->num = i;
    a->num_next = 0;
    a->next = (Node **)malloc(sizeof(Node *)*n);
    return a;
}

void run_tree(Node *start, int **c, int *count) {
    if (start->checked) return;
    start->checked = true;
    c[*count][1] = start->num;
    *count -= 1;
    for (int i=0; i<start->num_next; i++) {
        run_tree(start->next[i], c, count);
    }
}

int main() {
    int n = 0;
    scanf("%d\n", &n);
    Node *tree[n];
    for (int i=0; i<n; i++) {
        tree[i] = init_node(n, i);
    }
    int a = 0, b = 0;
    for (int i=0; i<n-1; i++) {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        tree[a]->next[tree[a]->num_next] = tree[b];
        tree[b]->next[tree[b]->num_next] = tree[a];
        tree[a]->num_next++;
        tree[b]->num_next++;
    }
    int *c_giving = (int *)malloc(sizeof(int)*n*2);
    int **c = (int **)malloc(sizeof(int *)*n);
    for (int i=0; i<n; i++) {
        c[i] = c_giving+2*i;
        scanf("%d", c[i]);
    }
    int start = 0;
    int mem_max = 0;
    for (int i=0; i<n; i++) {
        if (tree[start]->num_next > mem_max) {
            start = i;
            mem_max = tree[i]->num_next;
        }
    }
    qsort(c, n, sizeof(int *), compare0);
    long int max = 0;
    for (int i=0; i<n-1; i++) {
        max += *(c[i]);
    }
    printf("%ld\n", max);
    int count = n-1;
    run_tree(tree[start], c, &count);
    qsort(c, n, sizeof(int *), compare1);
    for (int i=0; i<n; i++) {
        printf("%d ", *(c[i]));
    }
    putchar('\n');
    return 0;
}
