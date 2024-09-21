#include <stdio.h>

#define MAX 100000000

struct NODE {
    int distance;
    int state;
} vertex[101];

int W[101][101];
int n, m;

int min(int a, int b) {
    return (a > b ? b : a);
}

int prim(int start) {
    int x, p, step, sum = 0;

    for (x = 0; x < n; x++) {
	vertex[x].distance = MAX; vertex[x].state = 0;
    }
    vertex[start].distance = 0; 
    for (step = 1; step <= n; step++) {
	int minimum = MAX;
	for (x = 0; x < n; x++)
	    if (vertex[x].state == 0 && vertex[x].distance < minimum) {
		p = x; minimum = vertex[x].distance;
	    }
	vertex[p].state = 1;
	sum += minimum;
	for (x = 0 ; x < n; x++)
		vertex[x].distance = min(vertex[x].distance, W[p][x]);
    }
    return sum;
}

int main(void) {
    int i, j;
    int from, to, cost;
     
    while (1) {
	scanf("%d", &n);
	scanf("%d", &m);
        if (n == 0) break;
         
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                W[i][j] = MAX;
         
	for (i = 0; i < m; i++) {
            scanf("%d %d %d", &from, &to, &cost);
            W[from][to] = cost;
	    W[to][from] = cost;
        }

	printf("%d\n", prim(0));
    }
    return 0;
}