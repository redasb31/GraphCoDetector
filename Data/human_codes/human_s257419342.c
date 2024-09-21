#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key, u, w;
} data;
 
typedef struct {
	data obj[100001];
	int size;
} min_heap;
 
void push(data x, min_heap* h)
{
	int i = ++(h->size), j = i >> 1;
	data tmp;
	h->obj[i] = x;
	while (j > 0) {
		if (h->obj[i].key < h->obj[j].key) {
			tmp = h->obj[j];
			h->obj[j] = h->obj[i];
			h->obj[i] = tmp;
			i = j;
			j >>= 1;
		} else break;
	}
}

data pop(min_heap* h)
{
	int i = 1, j = 2;
	data output = h->obj[1], tmp;
	h->obj[1] = h->obj[(h->size)--];
	while (j <= h->size) {
		if (j < h->size && h->obj[j^1].key < h->obj[j].key) j ^= 1;
		if (h->obj[j].key < h->obj[i].key) {
			tmp = h->obj[j];
			h->obj[j] = h->obj[i];
			h->obj[i] = tmp;
			i = j;
			j = i << 1;
		} else break;
	}
	return output;
}

typedef struct {
	int *par, *size, *height;
} UF_forest;

void UF_initialize(UF_forest *F, int n)
{
	int i;
	F->par = (int*)malloc(sizeof(int) * (n + 1));
	F->size = (int*)malloc(sizeof(int) * (n + 1));
	F->height = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 1; i <= n; i++) {
		F->par[i] = i;
		F->size[i] = 1;
		F->height[i] = 1;
	}
}

int UF_merge(UF_forest *F, int u, int v)
{
	for (; F->par[u] != u; u = F->par[u]);
	for (; F->par[v] != v; v = F->par[v]);
	if (u == v) return u;
	else if (F->height[u] > F->height[v]) {
		F->par[v] = u;
		F->size[u] += F->size[v];
		return u;
	} else {
		F->par[u] = v;
		F->size[v] += F->size[u];
		if (F->height[u] == F->height[v]) F->height[v]++;
		return v;
	}
}

int UF_root(UF_forest *F, int v)
{
	for (; F->par[v] != v; v = F->par[v]);
	return v;
}

int main()
{
	int i, N, M, X[100001];
	data d;
	min_heap h;
	h.size = 0;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%d", &(X[i]));
	for (i = 1; i <= M; i++) {
		scanf("%d %d %d", &(d.u), &(d.w), &(d.key));
		push(d, &h);
	}
	
	int ans = 0, r[3], vio[100001] = {};
	long long sum[100001];
	UF_forest F;
	UF_initialize(&F, N);
	for (i = 1; i <= N; i++) sum[i] = X[i];
	while (h.size > 0) {
		d = pop(&h);
		r[0] = UF_root(&F, d.u);
		r[1] = UF_root(&F, d.w);
		if (r[0] == r[1]) {
			if ((long long)d.key > sum[r[0]]) {
				vio[r[0]]++;
				ans++;
			}
		} else {
			r[2] = UF_merge(&F, r[0], r[1]);
			sum[r[2]] = sum[r[0]] + sum[r[1]];
			if ((long long)d.key > sum[r[2]]) {
				vio[r[2]] = vio[r[0]] + vio[r[1]] + 1;
				ans++;
			} else {
				ans -= vio[r[0]] + vio[r[1]];
				vio[r[2]] = 0;
			}
		}
	}
	
	printf("%d\n", ans);
	fflush(stdout);
	return 0;
}