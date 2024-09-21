#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key, id;
} data;

typedef struct {
	data *obj;
	int size;
} min_heap;

void push(data x, min_heap* h)
{
	int i = h->size;
	data tmp;
	h->obj[(h->size)++] = x;
	while (1) {
		if (i == 0) break;
		else if (h->obj[i].key < h->obj[(i-1)/2].key) {
			tmp = h->obj[(i-1)/2];
			h->obj[(i-1)/2] = h->obj[i];
			h->obj[i] = tmp;
			i = (i - 1) / 2;
		} else break;
	}
}

data pop(min_heap* h)
{
	int i = 0, j;
	data output = h->obj[0], tmp;
	h->obj[0] = h->obj[--(h->size)];
	while (1) {
		if (i * 2 + 1 >= h->size) break;
		else if (i * 2 + 2 >= h->size) j = i * 2 + 1;
		else if (h->obj[i*2+1].key < h->obj[i*2+2].key) j = i * 2 + 1;
		else j = i * 2 + 2;
		if (h->obj[j].key < h->obj[i].key) {
			tmp = h->obj[j];
			h->obj[j] = h->obj[i];
			h->obj[i] = tmp;
			i = j;
		} else break;
	}
	return output;
}

typedef struct {
	int t, h, cost;
} edge;

typedef struct List {
	struct List *next;
	edge *e;
} list;

typedef struct {
	int n, m;
	edge *e;
	list **inc;
} graph;

void input_graph(graph *G, int n, int m)
{
	int i;
	list *data = (list*)malloc(sizeof(list) * m * 2);
	G->n = n;
	G->m = m;
	G->e = (edge*)malloc(sizeof(edge) * m);
	G->inc = (list**)malloc(sizeof(list*) * (n + 1));
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &(G->e[i].t), &(G->e[i].h), &(G->e[i].cost));
		data[i*2].e = &(G->e[i]);
		data[i*2+1].e = &(G->e[i]);
		data[i*2].next = G->inc[G->e[i].t];
		data[i*2+1].next = G->inc[G->e[i].h];
		G->inc[G->e[i].t] = &(data[i*2]);
		G->inc[G->e[i].h] = &(data[i*2+1]);
	}
}

void redundant_edge_dijkstra(graph *G, int s, int red[])
{
	static int i, *dist = NULL, *prev = NULL;
	if (dist == NULL) {
		dist = (int*)malloc(sizeof(int) * (G->n + 1));
		prev = (int*)malloc(sizeof(int) * (G->n + 1));
	}
	for (i = 1; i <= G->n; i++) {
		dist[i] = 1 << 30;
		prev[i] = 0;
	}
	dist[s] = 0;
	prev[s] = -s;
	
	int u, w;
	list *p;
	data d;
	min_heap h;
	h.obj = (data*)malloc(sizeof(data) * (G->m * 2 + 1));
	h.size = 0;
	d.key = 0;
	d.id = s;
	push(d, &h);
	while (h.size > 0) {
		u = pop(&h).id;
		if (prev[u] > 0) continue;
		prev[u] *= -1;
		for (p = G->inc[u]; p != NULL; p = p->next) {
			w = (p->e->t == u)? p->e->h: p->e->t;
			if (dist[u] + p->e->cost < dist[w]) {
				dist[w] = dist[u] + p->e->cost;
				prev[w] = -u;
				d.key = dist[w];
				d.id = w;
				push(d, &h);
			}
		}
	}
	
	for (i = 0; i < G->m; i++) {
		u = G->e[i].t;
		w = G->e[i].h;
		if (G->e[i].cost == abs(dist[u] - dist[w])) red[i] = 0;
	}
}

int main()
{
	int N, M;
	graph G;
	scanf("%d %d", &N, &M);
	input_graph(&G, N, M);
	
	int i, red[1000], sum = 0;
	for (i = 0; i < M; i++) red[i] = 1;
	for (i = 1; i <= N; i++) redundant_edge_dijkstra(&G, i, red);
	for (i = 0; i < M; i++) sum += red[i];
	printf("%d\n", sum);
	fflush(stdout);
	return 0;
}