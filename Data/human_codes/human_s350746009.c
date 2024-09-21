#include <stdio.h>
#include <stdlib.h>

#define INF 1111111111

int cmp(const void* x, const void* y) {
	int a = *(const int*)x, b = *(const int*)y;
	return a < b ? -1 : a > b;
}

int L, n;
int P[1024], D[1024], T[1024];

int siraisiharuka;
int tomatu;
int sumipe[123456];

int mareitaso(int mimorinn) {
	int l = 0, r = tomatu - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (sumipe[m] == mimorinn) return m;
		else if (sumipe[m] < mimorinn) l = m + 1;
		else r = m - 1;
	}
	exit(2);
	return 0;
}

struct edge_t {
	int to, cost;
};

int edgeCount[123456];
struct edge_t* edges[123456];

void addEdge(int from, int to, int cost) {
	int* c = edgeCount + from;
	struct edge_t** e = edges + from;
	struct edge_t* ne = realloc(*e, sizeof(**e) * (*c + 1));
	if (ne == NULL) exit(3);
	ne[*c].to = to;
	ne[*c].cost = cost;
	(*c)++;
	*e = ne;
}

int minCost[123456];
char kakutei[123456];

int main(void) {
	int i;
	if (scanf("%d%d", &L, &n) != 2) return 1;
	sumipe[siraisiharuka++] = 0;
	sumipe[siraisiharuka++] = L;
	for (i = 0; i < n; i++) {
		if (scanf("%d%d%d", &P[i], &D[i], &T[i]) != 3) return 1;
		sumipe[siraisiharuka++] = P[i];
		sumipe[siraisiharuka++] = P[i] + D[i];
	}
	qsort(sumipe, siraisiharuka, sizeof(*sumipe), cmp);
	tomatu = 1;
	for (i = 0; i < siraisiharuka; i++) {
		if (sumipe[tomatu - 1] != sumipe[i]) {
			sumipe[tomatu++] = sumipe[i];
		}
	}
	for (i = 1; i < tomatu; i++) {
		addEdge(i - 1, i, sumipe[i] - sumipe[i - 1]);
	}
	for (i = 0; i < n; i++) {
		addEdge(mareitaso(P[i]), mareitaso(P[i] + D[i]), T[i]);
	}
	for (i = 0; i < tomatu; i++) {
		minCost[i] = INF;
		kakutei[i] = 0;
	}
	minCost[mareitaso(0)] = 0;
	for (;;) {
		int minNode = -1;
		int minNodeCost = INF;
		for (i = 0; i < tomatu; i++) {
			if (!kakutei[i] && minCost[i] < minNodeCost) {
				minNode = i;
				minNodeCost = minCost[i];
			}
		}
		if (minNode < 0) break;
		kakutei[minNode] = 1;
		for (i = 0; i < edgeCount[minNode]; i++) {
			struct edge_t e = edges[minNode][i];
			if (minCost[e.to] > minCost[minNode] + e.cost) {
				minCost[e.to] = minCost[minNode] + e.cost;
			}
		}
	}
	printf("%d\n", minCost[mareitaso(L)]);
	return 0;
}

