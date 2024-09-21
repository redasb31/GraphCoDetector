#include <stdio.h>
#include <stdlib.h>
#define int long long

typedef struct {
	int N;
	int *u;
	int *u_rank;
}union_find;

union_find *make_union_find(int N){
	int i;
	union_find *uf = (union_find *)malloc(sizeof(union_find));
	uf->N = N;
	uf->u = (int *)malloc(sizeof(int) * N);
	uf->u_rank = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		(uf->u)[i] = i;
		(uf->u_rank)[i] = 1;
	}
	return uf;
}

int root_uf(int x, union_find *uf){
	int *u = uf->u;
	if(u[x] == x){
		return x;
	}
	else{
		u[x] = root_uf(u[x], uf);
		return u[x];
	}
}

void combine_uf(int x, int y, union_find *uf){
	int x_root = root_uf(x, uf);
	int y_root = root_uf(y, uf);
	int *u = uf->u;
	int *u_rank = uf->u_rank;
	if(x_root == y_root){
		return;
	}
	else if(u_rank[x_root] < u_rank[y_root]){
		u[x_root] = y_root;
		u_rank[y_root] += u_rank[x_root];
		u_rank[x_root] = 0;
	}
	else{
		u[y_root] = x_root;
		u_rank[x_root] += u_rank[y_root];
		u_rank[y_root] = 0;
	}
}

//xとyが同じ集合に属していれば1を,そうでなければ0を返す
int is_same_union_uf(int x, int y, union_find *uf){
	if(root_uf(x, uf) == root_uf(y, uf)){
		return 1;
	}
	else{
		return 0;
	}
}

//xが属する集合の要素数を返す
int rank_uf(int x, union_find *uf){
	return (uf->u_rank)[root_uf(x, uf)];
}

typedef struct {
	int a;
	int b;
	int w;
}edge;

signed compair_edge(const void *x, const void *y){
	return ((edge *)x)->w - ((edge *)y)->w;
}

signed main(){
	int N, M, K, i;
	scanf("%lld%lld%lld", &N, &M, &K);
	int *c = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &c[i]);
		c[i]--;
	}
	edge *es = (edge *)malloc(sizeof(edge) * M);
	for(i = 0; i < M; i++){
		scanf("%lld%lld%lld", &es[i].a, &es[i].b, &es[i].w);
		es[i].a--;
		es[i].b--;
	}
	qsort(es, M, sizeof(edge), compair_edge);
	union_find *uf = make_union_find(N);
	int *prev = (int *)malloc(sizeof(int) * K);
	for(i = 0; i < K; i++){
		prev[i] = -1;
	}
	for(i = 0; i < N; i++){
		if(c[i] >= 0){
			if(prev[c[i]] >= 0){
				combine_uf(i, prev[c[i]], uf);
			}
			prev[c[i]] = i;
		}
	}
	int ea, eb, now = 0, ans = 0;
	for(i = 0; i < M && now < K - 1; i++){
		ea = es[i].a;
		eb = es[i].b;
		if(is_same_union_uf(ea, eb, uf) == 0){
			combine_uf(ea, eb, uf);
			ans += es[i].w;
			now++;
		}
	}
	if(now == K - 1){
		printf("%lld\n", ans);
	}
	else{
		printf("-1\n");
	}
	return 0;
}