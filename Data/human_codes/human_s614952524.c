// AOJ 2677 Breadth-First Search by Foxpower
// 2019.4.3 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//// 非負整数の高速入力
#if 1
#define gc() getchar_unlocked()
#define pc(c) putchar_unlocked(c)
#else
#define gc() getchar()
#define pc(c) putchar(c)
#endif
int in()  // 非負整数の入力
{
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}


//// LCAを求めるモジュール
#define MAX_V 100010
#define INF 0x30303030

typedef struct { int n, d; } Q;
Q que[2 * MAX_V]; int top, end;

// セグメント木の初期化
int seg[1 << 19][2]; int sz;          // セグメント木のサイズ

void segtree(int n, int init_val)
{
	sz = 2; while (sz < n) sz <<= 1;
	n = sz << 1;
//	for (i = 0; i < n; i++) seg[i][0] = init_val;
}

// RMQのインデックス部分を一括して更新
void update()
{
	int i, k, n, p;

	n = sz;	while (n > 0) {
		for (p = n - 1, i = 0; i < n; i += 2, p += 2) {
			k = p >> 1;
			if (seg[p][0] <= seg[p + 1][0]) {
				seg[k][0] = seg[p][0], seg[k][1] = seg[p][1];
			}
			else {
				seg[k][0] = seg[p + 1][0], seg[k][1] = seg[p + 1][1];
			}
		}
		n >>= 1;
	}
}

int query(int a, int b, int k, int l, int r, int *id)
{
	int ll, rr, lid, rid;

	if (r <= a || b <= l) { *id = 0; return INF; }
	if (a <= l && r <= b) { *id = seg[k][1]; return seg[k][0]; }
	ll = query(a, b, (k << 1) + 1, l, (l + r) >> 1, &lid);
	rr = query(a, b, (k << 1) + 2, (l + r) >> 1, r, &rid);
	if (ll <= rr) { *id = lid; return ll; }
	else { *id = rid; return rr; }
}

// LCA
int hi[MAX_V], *to[MAX_V];        // 隣接リストの作成が前提
int root;
int vs[2*MAX_V];
int depth[2*MAX_V];
int id[2*MAX_V];
int no;

#if 0
void dfs(int v, int d)
{
	int i;

	id[v] = no, vs[no] = v, depth[no++] = d;
	for (i = 0; i < hi[v]; i++) {
		dfs(to[v][i], d + 1);
		vs[no] = v, depth[no++] = d;
	}
}
#else
// dfsを非再帰にする（内容は上記と同一？）
void dfs(int v, int d)
{
	int i;

	top = 1, que[0].n = v, que[0].d = d;
	while (top) {
		v = que[--top].n, d = que[top].d;
		if (v < 0) { vs[no] = -v-1, depth[no++] = d; continue; }
		id[v] = no, vs[no] = v, depth[no++] = d;
		for (i = hi[v] - 1; i >= 0; i--) {
			que[top].n = -(v + 1), que[top++].d = d;
			que[top].n = to[v][i], que[top++].d = d + 1;
		}
	}
}
#endif

// 以下のlca()を呼び出すまえに、必ず実行する部分
// nは頂点数、rootはルートの番号
void lca_preCalc(int n, int root)
{
	int j, u;
	
	no = 0;
	dfs(root, 0);

	n = (n << 1) - 1;
	segtree(n, INF);

	j = sz - 1;
	for (u = 0; u < n; u++) seg[j][0] = depth[u], seg[j++][1] = u;
	update();
}

// u, v は 0-index
int lca(int u, int v)
{
	int k;
	if (id[u] < id[v]) query(id[u], id[v] + 1, 0, 0, sz, &k);
	else               query(id[v], id[u] + 1, 0, 0, sz, &k);
	return vs[k];
}


int p[MAX_V]; int N;
int ord[MAX_V], hight[MAX_V];
// int hi[MAX], *to[MAX];

void bfs(int root)
{
	int i, no, node, deep;

	no = 0;
	top = 0, end = 1, que[0].n = root, que[0].d = 0;
	while (top != end) {
		node = que[top].n, deep = que[top++].d;
		ord[no++] = node;
		hight[node] = deep;
		for (i = 0; i < hi[node]; i++)
			que[end].n = to[node][i], que[end++].d = deep + 1;
	}
}

int main()
{
	int i, p;
	int *memo, sz;
	long long ans;

	N = in();
	memo = malloc(sizeof(int)*N*2);
	sz = 0;  for (i = 1; i < N; i++) {
		memo[sz++] = p = in() - 1;
		hi[p]++;
		memo[sz++] = i;
	}
	for (i = 0; i < N; i++) if (hi[i]) to[i] = malloc(sizeof(int)*hi[i]);
	memset(hi, 0, sizeof(int)*N);
	i = 0; while (i < sz) {
		p = memo[i++], to[p][hi[p]++] = memo[i++];
	}

#if 0
	for (i = 0; i < N; i++) {
		int j;
		printf("node=%d, hi=%d:", i, hi[i]);
		for (j = 0; j < hi[i]; j++) printf(" %d", to[i][j]);
		printf("\n");
	}
#endif

	bfs(0);

	// LCAの計算
	lca_preCalc(N, 0);

	ans = 0;
	for (i = 1; i < N; i++) {
		int a, b;
		a = ord[i - 1], b = ord[i];
		ans += hight[a] + hight[b] - (hight[lca(a, b)] << 1);
	}
	printf("%lld\n", ans);
	return 0;
}
