#include <stdio.h>
#include <stdlib.h>
#define max_size (int)(1e5 + 1)

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

int main(){
	int L, N, l, r, i;
	char *S = (char *)malloc(sizeof(char) * max_size);
	scanf("%s", S);
	for(i = 0; S[i] != '\0'; i++){}
	L = i;
	union_find *uf = make_union_find(L + 1);
	uf->u_rank[0] = ((int)S[0] - (int)'a') % 26;
	for(i = 1; i < L; i++){
		uf->u_rank[i] = ((int)S[i] - (int)S[i - 1] + 26) % 26;
	}
	uf->u_rank[L] = ((int)'a' - (int)S[L - 1] + 26) % 26;
	for(i = 0; i <= L / 2; i++){
		combine_uf(i, L - i, uf);
	}
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d%d", &l, &r);
		combine_uf(l - 1, r, uf);
	}
	for(i = 0; i <= L; i++){
		if(rank_uf(i, uf) % 26 != 0){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}