#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key, id;
} data;

typedef struct {
	data *obj;
	int size;
} max_heap;

void push(data x, max_heap* h)
{
	int i = ++(h->size), j = i >> 1;
	data tmp;
	h->obj[i] = x;
	while (j > 0) {
		if (h->obj[i].key > h->obj[j].key) {
			tmp = h->obj[j];
			h->obj[j] = h->obj[i];
			h->obj[i] = tmp;
			i = j;
			j >>= 1;
		} else break;
	}
}

data pop(max_heap* h)
{
	int i = 1, j = 2;
	data output = h->obj[1], tmp;
	h->obj[1] = h->obj[(h->size)--];
	while (j <= h->size) {
		if (j < h->size && h->obj[j^1].key > h->obj[j].key) j ^= 1;
		if (h->obj[j].key > h->obj[i].key) {
			tmp = h->obj[j];
			h->obj[j] = h->obj[i];
			h->obj[i] = tmp;
			i = j;
			j <<= 1;
		} else break;
	}
	return output;
}

typedef struct {
	int id, head, tail, flow, cap;
} edge;

typedef struct List {
	struct List *next;
	edge *e;
} list;

int push_relabel(int N, int M, list* adj[], edge e[], int s, int t)
{
	int i, u, w, *height = (int*)malloc(sizeof(int) * (N + 1)), *sur = (int*)malloc(sizeof(int) * (N + 1));
	list *p;
	data d;
	max_heap h;
	h.size = 0;
	h.obj = (data*)malloc(sizeof(data) * (N + 1));
	for (i = 1; i <= N; i++) height[i] = 0;
	for (i = 0; i < M; i++) e[i].flow = 0;
	for (p = adj[s], height[s] = N; p != NULL; p = p->next) {
		i = p->e->id;
		w = p->e->head;
		e[i].flow = e[i].cap;
		e[i^1].cap = e[i].flow;
		sur[s] -= e[i].flow;
		sur[w] += e[i].flow;
		if (sur[w] > 0) {
			d.key = height[w];
			d.id = w;
			push(d, &h);
		}
	}
	
	int min;
	while (h.size > 0) {
		d = pop(&h);
		u = d.id;
		if (u == t || sur[u] <= 0) continue;
		
		for (p = adj[u], min = N * 2; p != NULL; p = p->next) {
			w = p->e->head;
			if (p->e->flow == p->e->cap) continue;
			else if (height[w] == height[u] - 1) break;
			else if (min > height[w]) min = height[w];
		}
		
		if (p == NULL) {
			height[u] = min + 1;
			d.key = height[u];
			push(d, &h);
		} else {
			min = (sur[u] < p->e->cap - p->e->flow)? sur[u]: p->e->cap - p->e->flow;
			i = p->e->id;
			w = p->e->head;
			if (e[i^1].flow > 0) {
				e[i].cap -= min;
				e[i^1].flow -= min;
			} else {
				e[i].flow += min;
				e[i^1].cap += min;
			}
			if (sur[u] > min) push(d, &h);
			if (sur[w] == 0) {
				d.key = height[w];
				d.id = w;
				push(d, &h);
			}
			sur[u] -= min;
			sur[w] += min;
		}
	}
	
	int ans = sur[t];
	free(height);
	free(sur);
	free(h.obj);
	return ans;
}

int main()
{
	int i, N, M;
	char S[102][102] = {};
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%s", &(S[i][1]));
	
	const int sup = 1 << 30;
	int j, k, u, w;
	list *adj[10003] = {}, d[100000];
	edge e[100000];
	for (i = 1, k = 0; i <= N; i++) {
		for (j = 2 - i % 2; j <= M; j += 2) {
			if (S[i][j] == '#') continue;
			u = (i - 1) * M + j;
			if (S[i-1][j] == '.') {
				w = (i - 2) * M + j;
				e[k*2].id = k * 2;
				e[k*2].tail = u;
				e[k*2].head = w;
				e[k*2].cap = sup;
				e[k*2+1].id = k * 2 + 1;
				e[k*2+1].tail = w;
				e[k*2+1].head = u;
				e[k*2+1].cap = 0;
				d[k*2].e = &(e[k*2]);
				d[k*2+1].e = &(e[k*2+1]);
				d[k*2].next = adj[u];
				d[k*2+1].next = adj[w];
				adj[u] = &(d[k*2]);
				adj[w] = &(d[k*2+1]);
				k++;
			}
			if (S[i+1][j] == '.') {
				w = i * M + j;
				e[k*2].id = k * 2;
				e[k*2].tail = u;
				e[k*2].head = w;
				e[k*2].cap = sup;
				e[k*2+1].id = k * 2 + 1;
				e[k*2+1].tail = w;
				e[k*2+1].head = u;
				e[k*2+1].cap = 0;
				d[k*2].e = &(e[k*2]);
				d[k*2+1].e = &(e[k*2+1]);
				d[k*2].next = adj[u];
				d[k*2+1].next = adj[w];
				adj[u] = &(d[k*2]);
				adj[w] = &(d[k*2+1]);
				k++;
			}
			if (S[i][j-1] == '.') {
				w = (i - 1) * M + j - 1;
				e[k*2].id = k * 2;
				e[k*2].tail = u;
				e[k*2].head = w;
				e[k*2].cap = sup;
				e[k*2+1].id = k * 2 + 1;
				e[k*2+1].tail = w;
				e[k*2+1].head = u;
				e[k*2+1].cap = 0;
				d[k*2].e = &(e[k*2]);
				d[k*2+1].e = &(e[k*2+1]);
				d[k*2].next = adj[u];
				d[k*2+1].next = adj[w];
				adj[u] = &(d[k*2]);
				adj[w] = &(d[k*2+1]);
				k++;
			}
			if (S[i][j+1] == '.') {
				w = (i - 1) * M + j + 1;
				e[k*2].id = k * 2;
				e[k*2].tail = u;
				e[k*2].head = w;
				e[k*2].cap = sup;
				e[k*2+1].id = k * 2 + 1;
				e[k*2+1].tail = w;
				e[k*2+1].head = u;
				e[k*2+1].cap = 0;
				d[k*2].e = &(e[k*2]);
				d[k*2+1].e = &(e[k*2+1]);
				d[k*2].next = adj[u];
				d[k*2+1].next = adj[w];
				adj[u] = &(d[k*2]);
				adj[w] = &(d[k*2+1]);
				k++;
			}
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if ((i + j) % 2 == 0) {
				u = N * M + 1;
				w = (i - 1) * M + j;
			} else {
				u = (i - 1) * M + j;
				w = N * M + 2;
			}
			e[k*2].id = k * 2;
			e[k*2].tail = u;
			e[k*2].head = w;
			e[k*2].cap = 1;
			e[k*2+1].id = k * 2 + 1;
			e[k*2+1].tail = w;
			e[k*2+1].head = u;
			e[k*2+1].cap = 0;
			d[k*2].e = &(e[k*2]);
			d[k*2+1].e = &(e[k*2+1]);
			d[k*2].next = adj[u];
			d[k*2+1].next = adj[w];
			adj[u] = &(d[k*2]);
			adj[w] = &(d[k*2+1]);
			k++;
		}
	}
	
	int l;
	printf("%d\n", push_relabel(N * M + 2, k * 2, adj, e, N * M + 1, N * M + 2));
	for (l = 0; l < k; l++) {
		u = e[l*2].tail;
		w = e[l*2].head;
		if (e[l*2].flow == 1 && u <= N * M && w <= N * M) {
			i = (u - 1) / M + 1;
			j = (u - 1) % M + 1;
			if (u == w + 1) {
				S[i][j] = '<';
				S[i][j-1] = '>';
			} else if (u == w - 1) {
				S[i][j] = '>';
				S[i][j+1] = '<';
			} else if (u == w + M) {
				S[i][j] = '^';
				S[i-1][j] = 'v';
			} else {
				S[i][j] = 'v';
				S[i+1][j] = '^';
			}
		}
	}
	for (i = 1; i <= N; i++) printf("%s\n", &(S[i][1]));
	fflush(stdout);
	return 0;
}