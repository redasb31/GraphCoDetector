#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int t, h;
} edge;

typedef struct List {
	struct List *next;
	edge *e;
} list;

typedef struct {
	edge *e;
	list **inc;
} graph;

long long div_mod(long long x, long long y, long long z)
{
	if (x % y == 0) return x / y;
	else return (div_mod((1 + x / y) * y - x, (z % y), y) * z + x) / y;
}

int main()
{
	int i, N, P[5001];
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &(P[i]));
	
	graph G;
	list *data = (list*)malloc(sizeof(list) * N * 2);
	G.e = (edge*)malloc(sizeof(edge) * N);
	G.inc = (list**)malloc(sizeof(list*) * (N + 1));
	for (i = 0; i < N; i++) {
		if (P[i+1] == -1) continue;
		G.e[i].t = P[i+1];
		G.e[i].h = i + 1;
		data[i*2].e = &(G.e[i]);
		data[i*2+1].e = &(G.e[i]);
		data[i*2].next = G.inc[G.e[i].t];
		data[i*2+1].next = G.inc[G.e[i].h];
		G.inc[G.e[i].t] = &(data[i*2]);
		G.inc[G.e[i].h] = &(data[i*2+1]);
	}
	
	list *p;
	int j, k, K, v, comp[5001] = {}, q[5001], head, tail, size[5001] = {};
	for (i = 1, k = 1; i <= N; i++) {
		if (P[i] != -1) continue;
		comp[i] = k;
		q[0] = i;
		for (head = 0, tail = 1; head < tail; head++) {
			for (p = G.inc[q[head]]; p != NULL; p = p->next) {
				v = p->e->h;
				if (comp[v] == 0) {
					comp[v] = k;
					q[tail++] = v;
				}
			}
		}
		size[k++] = tail;
	}
	for (i = 1, K = k - 1; i <= N; i++) {
		if (comp[i] != 0) continue;
		comp[i] = k;
		q[0] = i;
		for (head = 0, tail = 1; head < tail; head++) {
			for (p = G.inc[q[head]]; p != NULL; p = p->next) {
				v = (p->e->t == q[head])? p->e->h: p->e->t;
				if (comp[v] == 0) {
					comp[v] = k;
					q[tail++] = v;
				}
			}
		}
		k++;
	}
	
	long long ans = N - k + 1 + K, sym[5001] = {1}, pow[5001][5001] = {}, N_pow[5001] = {1}, tmp;
	for (i = 1; i <= K; i++) {
		ans = ans * (N - 1) % 1000000007;
		N_pow[i] = N_pow[i-1] * (N - 1) % 1000000007;
		sym[1] += size[i];
		for (j = 2, pow[i][1] = size[i]; j <= K; j++) pow[i][j] = pow[i][j-1] * size[i] % 1000000007;
	}
	ans = ((ans + 1000000007) - ((sym[1] - K) * N_pow[K-1] % 1000000007)) % 1000000007;
	pow[0][0] = 1;
	for (i = 1; i <= K; i++) {
		for (j = 1; j <= K; j++) pow[0][i] = (pow[0][i] + pow[j][i]) % 1000000007;
	}
	for (i = 2, tmp = 1; i <= K; i++, tmp = tmp * (i - 1) % 1000000007) {
		sym[i] = sym[i-1] * pow[0][1];
		for (j = 2; j <= i; j++) {
			if (j % 2 == 1) sym[i] = (sym[i] + sym[i-j] * pow[0][j]) % 1000000007;
			else sym[i] = (sym[i] + 1000000007 - (sym[i-j] * pow[0][j]) % 1000000007) % 1000000007;
		}
		sym[i] = div_mod(sym[i], i, 1000000007);
		ans = ((ans + 1000000007) - ((sym[i] * tmp % 1000000007) * N_pow[K-i] % 1000000007)) % 1000000007;
	}
	
	printf("%lld\n", ans);
	fflush(stdout);
	return 0;
}