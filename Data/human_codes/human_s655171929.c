#include <stdio.h>

typedef struct List {
	struct List *next;
	int v;
} list;

int main()
{
	int i, N, P[1001], X[1001];
	scanf("%d", &N);
	for (i = 2, P[1] = 1; i <= N; i++) scanf("%d", &(P[i]));
	for (i = 1; i <= N; i++) scanf("%d", &(X[i]));
	
	list *adj[1001] = {}, e[1003];
	for (i = 2; i <= N; i++) {
		e[i].v = i;
		e[i].next = adj[P[i]];
		adj[P[i]] = &(e[i]);
	}
	
	int q[1001], head, tail;
	list *p;
	q[0] = 1;
	for (head = 0, tail = 1; head < tail; head++) {
		for (p = adj[q[head]]; p != NULL; p = p->next) q[tail++] = p->v;
	}
	
	int u, w, min[1001] = {}, sum;
	char dp[5001];
	for (head--; head >= 0; head--) {
		u = q[head];
		for (i = 1, dp[0] = 1; i <= 5000; i++) dp[i] = 0;
		for (p = adj[u], sum = 0; p != NULL; p = p->next) {
			w = p->v;
			sum += X[w] + min[w];
			for (i = X[u]; i >= 0; i--) {
				if (dp[i] == 1) {
					dp[i] = 0;
					if (i + X[w] <= X[u]) dp[i+X[w]] = 1;
					if (i + min[w] <= X[u]) dp[i+min[w]] = 1;
				}
			}
		}
		for (i = X[u]; i >= 0; i--) if (dp[i] == 1) break;
		if (i < 0) break;
		
		min[u] = sum - i;
	}
	
	if (head >= 0) printf("IMPOSSIBLE\n");
	else printf("POSSIBLE\n");
	fflush(stdout);
	return 0;
}