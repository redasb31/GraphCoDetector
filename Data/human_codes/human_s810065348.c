#include <stdio.h>
#include <stdlib.h>

#define dag_valtype int
#define graph_valtype int

typedef struct graph_edge_sub graph_edge;

typedef struct {
	int num;
	int next_num;
	graph_edge *next;
	int prev_num;
}graph_vertex_sub;

struct graph_edge_sub{
	graph_vertex_sub *v;
	int w;
	graph_edge *next;
};

typedef struct graph_v_sub graph_vertex;

struct graph_v_sub{
	int num;
	graph_valtype val;
	int next_num;
	graph_vertex **next;
	int *next_weight;
	int prev_num;
	graph_vertex **prev;
	int *prev_weight;
};

typedef struct {
	int N;
	graph_vertex_sub **v_s;
	graph_vertex **v;
}graph;

//頂点数N, 各頂点の初期値ini_valのグラフを作る
graph *make_graph(int N, graph_valtype ini_val){
	int i;
	graph *g = (graph *)malloc(sizeof(graph));
	g->N = N;
	g->v_s = (graph_vertex_sub **)malloc(sizeof(graph_vertex_sub *) * N);
	g->v = (graph_vertex **)malloc(sizeof(graph_vertex *) * N);
	for(i = 0; i < N; i++){
		(g->v_s)[i] = (graph_vertex_sub *)malloc(sizeof(graph_vertex_sub));
		(g->v_s)[i]->num = i;
		(g->v_s)[i]->next_num = 0;
		(g->v_s)[i]->next = NULL;
		(g->v_s)[i]->prev_num = 0;
		(g->v)[i] = (graph_vertex *)malloc(sizeof(graph_vertex));
		(g->v)[i]->num = i;
		(g->v)[i]->val = ini_val;
		(g->v)[i]->next_num = 0;
		(g->v)[i]->next = NULL;
		(g->v)[i]->next_weight = NULL;
		(g->v)[i]->prev_num = 0;
		(g->v)[i]->prev = NULL;
		(g->v)[i]->prev_weight = NULL;
	}
	return g;
}

//グラフgの頂点aから頂点bに重みwの有向辺を張る (0 <= a, b <= N - 1)
void set_edge_graph(int a, int b, int w, graph *g){
	graph_edge *new1 = (graph_edge *)malloc(sizeof(graph_edge));
	new1->v = (g->v_s)[b];
	new1->w = w;
	new1->next = (g->v_s)[a]->next;
	(g->v_s)[a]->next = new1;
	(g->v_s)[a]->next_num++;
	(g->v_s)[b]->prev_num++;
}

//set_edge_graph後に呼び出す
void build_graph(graph *g){
	int i;
	graph_vertex_sub **v_s = g->v_s;
	graph_vertex **v = g->v;
	graph_vertex *nowv;
	graph_edge *nowe;
	for(i = 0; i < g->N; i++){
		v[i]->next = (graph_vertex **)malloc(sizeof(graph_vertex *) * v_s[i]->next_num);
		v[i]->next_weight = (int *)malloc(sizeof(int) * v_s[i]->next_num);
		v[i]->prev = (graph_vertex **)malloc(sizeof(graph_vertex *) * v_s[i]->prev_num);
		v[i]->prev_weight = (int *)malloc(sizeof(int) * v_s[i]->prev_num);
	}
	for(i = 0; i < g->N; i++){
		nowv = v[i];
		for(nowe = v_s[i]->next; nowe != NULL; nowe = nowe->next){
			(nowv->next)[nowv->next_num] = v[nowe->v->num];
			(nowv->next_weight)[nowv->next_num] = nowe->w;
			nowv->next_num++;
			(v[nowe->v->num]->prev)[v[nowe->v->num]->prev_num] = nowv;
			(v[nowe->v->num]->prev_weight)[v[nowe->v->num]->prev_num] = nowe->w;
			v[nowe->v->num]->prev_num++;
		}
	}
}

typedef struct SCC_sub{
	int num; //強連結成分番号
	int vertex_num; //強連結成分に含まれる頂点の個数
	int *vertexs; //強連結成分に含まれる元のグラフでの頂点番号
	dag_valtype val;
	int next_num;
	struct SCC_sub **next;
	int *next_weight;
	int prev_num;
	struct SCC_sub **prev;
	int *prev_weight;
}SCC; //強連結成分(Strongly Connected Components)

typedef struct {
	int N;
	SCC **sorted_SCC; //topological sort済み
}DAG; //非閉路有向グラフ(Directed Acyclic Graph)

int dfs(int next_bt, int *used, int *bt, int *bt_inv, graph_vertex *v){
	if(used[v->num] == 1){
		return next_bt;
	}
	else{
		int i;
		used[v->num] = 1;
		for(i = 0; i < v->next_num; i++){
			next_bt = dfs(next_bt, used, bt, bt_inv, v->next[i]);
		}
		bt[v->num] = next_bt;
		bt_inv[next_bt] = v->num;
		return next_bt + 1;
	}
}

void dfs_rev1(int next_SCC_num, int *used, int *SCC_num, int *next_num, int *prev_num, graph_vertex *v){
	if(used[v->num] == 1){
		int i;
		used[v->num] = 2;
		for(i = 0; i < v->prev_num; i++){
			dfs_rev1(next_SCC_num, used, SCC_num, next_num, prev_num, v->prev[i]);
		}
		SCC_num[v->num] = next_SCC_num;
		for(i = 0; i < v->next_num; i++){
			if(used[v->next[i]->num] == 1){
				next_num[v->num]++;
				prev_num[v->next[i]->num]++; //ここで自己ループを数えてしまう可能性がある
			}
		}
	}
}

void dfs_rev2(SCC *now_SCC, int *used, int *SCC_num, graph_vertex *v, DAG *dag){
	if(used[v->num] == 2){
		int i;
		SCC *next_SCC;
		used[v->num] = 3;
		for(i = 0; i < v->prev_num; i++){
			dfs_rev2(now_SCC, used, SCC_num, v->prev[i], dag);
		}
		now_SCC->vertexs[now_SCC->vertex_num] = v->num;
		now_SCC->vertex_num++;
		for(i = 0; i < v->next_num; i++){
			if(used[v->next[i]->num] == 2){
				next_SCC = dag->sorted_SCC[SCC_num[v->next[i]->num]];
				if(now_SCC->num != next_SCC->num){ //自己ループがないようにしている
					now_SCC->next[now_SCC->next_num] = next_SCC;
					now_SCC->next_weight[now_SCC->next_num] = v->next_weight[i];
					now_SCC->next_num++;
					next_SCC->prev[next_SCC->prev_num] = now_SCC;
					next_SCC->prev_weight[next_SCC->prev_num] = v->next_weight[i];
					next_SCC->prev_num++;
				}
			}
		}
	}
}

DAG *build_DAG(graph *g, dag_valtype ini_val){
	int N = g->N, i;
	int *used = (int *)malloc(sizeof(int) * N);

	int *bt = (int *)malloc(sizeof(int) * N);
	int *bt_inv = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		used[i] = 0;
		bt[i] = -1;
		bt_inv[i] = -1;
	}
	int next_bt;
	for(i = 0, next_bt = 0; i < N; i++){
		next_bt = dfs(next_bt, used, bt, bt_inv, g->v[i]);
	}

	int *SCC_num = (int *)malloc(sizeof(int) * N);
	int *next_num = (int *)malloc(sizeof(int) * N);
	int *prev_num = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		SCC_num[i] = 0;
		next_num[i] = 0;
		prev_num[i] = 0;
	}
	int next_SCC_num;
	for(i = N - 1, next_SCC_num = 0; i >= 0; i--){
		if(used[bt_inv[i]] == 1){
			dfs_rev1(next_SCC_num, used, SCC_num, next_num, prev_num, g->v[bt_inv[i]]);
			next_SCC_num++;
		}
	}

	DAG *dag = (DAG *)malloc(sizeof(DAG));
	SCC *now_SCC;
	dag->N = next_SCC_num;
	dag->sorted_SCC = (SCC **)malloc(sizeof(SCC *) * dag->N);
	for(i = 0; i < dag->N; i++){
		dag->sorted_SCC[i] = (SCC *)malloc(sizeof(SCC));
		now_SCC = dag->sorted_SCC[i];
		now_SCC->num = i;
		now_SCC->vertex_num = 0;
		now_SCC->vertexs = NULL;
		now_SCC->val = ini_val;
		now_SCC->next_num = 0;
		now_SCC->next = NULL;
		now_SCC->next_weight = NULL;
		now_SCC->prev_num = 0;
		now_SCC->prev = NULL;
		now_SCC->prev_weight = NULL;
	}
	for(i = 0; i < N; i++){
		now_SCC = dag->sorted_SCC[SCC_num[i]];
		now_SCC->vertex_num++;
		now_SCC->next_num += next_num[i];
		now_SCC->prev_num += prev_num[i];
	}
	for(i = 0; i < dag->N; i++){
		now_SCC = dag->sorted_SCC[i];
		now_SCC->vertexs = (int *)malloc(sizeof(int) * now_SCC->vertex_num);
		now_SCC->next = (SCC **)malloc(sizeof(SCC *) * now_SCC->next_num);
		now_SCC->next_weight = (int *)malloc(sizeof(int) * now_SCC->next_num);
		now_SCC->prev = (SCC **)malloc(sizeof(SCC *) * now_SCC->prev_num);
		now_SCC->prev_weight = (int *)malloc(sizeof(int) * now_SCC->prev_num);
		now_SCC->vertex_num = 0;
		now_SCC->next_num = 0;
		now_SCC->prev_num = 0;
	}

	for(i = N - 1, next_SCC_num = 0; i >= 0; i--){
		if(used[bt_inv[i]] == 2){
			dfs_rev2(dag->sorted_SCC[next_SCC_num], used, SCC_num, g->v[bt_inv[i]], dag);
			next_SCC_num++;
		}
	}

	return dag;
}

typedef struct {
	int i;
	int v;
}pair;

typedef struct {
	int x;
	int y;
}pos;

int pos_to_int(int x, int y, int N){
	return N * x + y;
}

pos int_to_pos(int num, int N){
	return (pos){num / N, num % N};
}

//v降順
signed compair(const void *a, const void *b){
	return ((pair *)b)->v - ((pair *)a)->v;
}

int search(int num, int SCC_num, int N, int **B2, graph *g, int **visited){
	pos p = int_to_pos(num, N);
	if(B2[p.x][p.y] != SCC_num || visited[p.x][p.y] == 2 || visited[p.x][p.y] == -1){
		return 0;
	}
	else if(visited[p.x][p.y] == 1){
		visited[p.x][p.y] = 2;
		return 1;
	}
	else{
		visited[p.x][p.y] = 1;
		graph_vertex *nowv = g->v[num];
		int i;
		for(i = 0; i < nowv->next_num; i++){
			if(search(nowv->next[i]->num, SCC_num, N, B2, g, visited) == 1){
				if(visited[p.x][p.y] == 2){
					return 0;
				}
				else{
					visited[p.x][p.y] = 2;
					return 1;
				}
			}
		}
		visited[p.x][p.y] = -1;
		return 0;
	}
}

int main(){
	int N, i, j, k;
	scanf("%d", &N);
	int *U = (int *)malloc(sizeof(int) * N);
	int *D = (int *)malloc(sizeof(int) * N);
	int *L = (int *)malloc(sizeof(int) * N);
	int *R = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &U[i]);
	}
	for(i = 0; i < N; i++){
		scanf("%d", &D[i]);
	}
	for(i = 0; i < N; i++){
		scanf("%d", &L[i]);
	}
	for(i = 0; i < N; i++){
		scanf("%d", &R[i]);
	}
	pair *UD = (pair *)malloc(sizeof(pair) * N);
	pair *LR = (pair *)malloc(sizeof(pair) * N);
	for(i = 0; i < N; i++){
		UD[i].i = i;
		UD[i].v = U[i] + D[i];
		LR[i].i = i;
		LR[i].v = N - (L[i] + R[i]);
	}
	qsort(UD, N, sizeof(pair), compair);
	qsort(LR, N, sizeof(pair), compair);
	int **B0 = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		B0[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++){
			B0[i][j] = 0;
		}
	}
/*	printf("test0\n");
	for(i = 0; i < N; i++){
		printf("LR[%d] = (%d, %d)\n", i, LR[i].i, LR[i].v);
	}
	for(i = 0; i < N; i++){
		printf("UD[%d] = (%d, %d)\n", i, UD[i].i, UD[i].v);
	}
*/	int lastv, l, r, tmp;
	for(i = 0; i < N; i++){
//		printf("i = %d\n", i);
		if(LR[i].v == 0){
			break;
		}
		for(j = 0; j < LR[i].v; j++){
			B0[i][j] = 1;
		}
		lastv = UD[j - 1].v;
		for(l = 0; UD[l].v != lastv; l++);
		for(r = N - 1; UD[r].v != lastv; r--);
		for(k = 0; k <= (r - l) / 2; k++){
			tmp = B0[i][l + k];
			B0[i][l + k] = B0[i][r - k];
			B0[i][r - k] = tmp;
		}
		for(j = 0; j < N; j++){
			UD[j].v -= B0[i][j];
			if(UD[j].v < 0){
				printf("NO\n");
				return 0;
			}
		}
	}
/*	printf("B0\n");
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%d", B0[i][j]);
		}
		printf("\n");
	}
*/	int **B1 = (int **)malloc(sizeof(int *) * N);
	int **B2 = (int **)malloc(sizeof(int *) * N);
	char **A = (char **)malloc(sizeof(char *) * N);
	int **visited = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		B1[i] = (int *)malloc(sizeof(int) * N);
		B2[i] = (int *)malloc(sizeof(int) * N);
		A[i] = (char *)malloc(sizeof(char) * N);
		visited[i] = (int *)malloc(sizeof(int) * N);
	}
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			B1[LR[i].i][UD[j].i] = B0[i][j];
		}
	}
	graph *g;
	DAG *dag;
	pos p;
	while(1){
/*		printf("B1:\n");
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				printf("%d", B1[i][j]);
			}
			printf("\n");
		}
*/		for(i = 0; i < N; i++){
			for(j = 0, k = 0; k < L[i]; j++){
				if(B1[i][j] == 0){
					A[i][j] = 'L';
					k++;
				}
			}
			for(j = N - 1, k = 0; k < R[i]; j--){
				if(B1[i][j] == 0){
					A[i][j] = 'R';
					k++;
				}
			}
		}
		for(j = 0; j < N; j++){
			for(i = 0, k = 0; k < U[j]; i++){
				if(B1[i][j] == 1){
					A[i][j] = 'U';
					k++;
				}
			}
			for(i = N - 1, k = 0; k < D[j]; i--){
				if(B1[i][j] == 1){
					A[i][j] = 'D';
					k++;
				}
			}
		}
		g = make_graph(N * N, 0);
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				if(B1[i][j] == 1){
					for(k = j + 1; k < N; k++){
						if(A[i][k] == 'L'){
							set_edge_graph(pos_to_int(i, j, N), pos_to_int(i, k, N), 1, g);
						}
					}
				}
			}
			for(j = N - 1; j >= 0; j--){
				if(B1[i][j] == 1){
					for(k = j - 1; k >= 0; k--){
						if(A[i][k] == 'R'){
							set_edge_graph(pos_to_int(i, j, N), pos_to_int(i, k, N), 1, g);
						}
					}
				}
			}
		}
		for(j = 0; j < N; j++){
			for(i = 0; i < N; i++){
				if(B1[i][j] == 0){
					for(k = i + 1; k < N; k++){
						if(A[k][j] == 'U'){
							set_edge_graph(pos_to_int(i, j, N), pos_to_int(k, j, N), 1, g);
						}
					}
				}
			}
			for(i = N - 1; i >= 0; i--){
				if(B1[i][j] == 0){
					for(k = i - 1; k >= 0; k--){
						if(A[k][j] == 'D'){
							set_edge_graph(pos_to_int(i, j, N), pos_to_int(k, j, N), 1, g);
						}
					}
				}
			}
		}
		build_graph(g);
/*		for(i = 0; i < g->N; i++){
			printf("i = %d: ", i);
			graph_vertex *nowv = g->v[i];
			for(j = 0; j < nowv->next_num; j++){
				printf("%d ", nowv->next[j]->num);
			}
			printf("\n");
		}
*/		dag = build_DAG(g, 0);
//		printf("dag->N = %d\n", dag->N);
		if(dag->N == N * N){
			break;
		}
		SCC *now_SCC;
		for(i = 0; i < dag->N; i++){
			now_SCC = dag->sorted_SCC[i];
			for(j = 0; j < now_SCC->vertex_num; j++){
				p = int_to_pos(now_SCC->vertexs[j], N);
				B2[p.x][p.y] = now_SCC->num;
			}
		}
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				visited[i][j] = 0;
			}
		}
		for(i = 0; i < dag->N; i++){
			now_SCC = dag->sorted_SCC[i];
			if(now_SCC->vertex_num == 1){
				continue;
			}
			for(j = 0; j < now_SCC->vertex_num; j++){
				search(now_SCC->vertexs[j], now_SCC->num, N, B2, g, visited);
			}
		}
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				if(visited[i][j] == 2){
					B1[i][j] ^= 1;
				}
			}
		}
	}
//	printf("break\n");
/*	printf("A:\n");
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%c", A[i][j]);
		}
		printf("\n");
	}
*/	g = make_graph(N * N, 0);
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			for(k = j + 1; k < N; k++){
				if(A[i][k] == 'L'){
					set_edge_graph(pos_to_int(i, j, N), pos_to_int(i, k, N), 1, g);
				}
			}
		}
		for(j = N - 1; j >= 0; j--){
			for(k = j - 1; k >= 0; k--){
				if(A[i][k] == 'R'){
					set_edge_graph(pos_to_int(i, j, N), pos_to_int(i, k, N), 1, g);
				}
			}
		}
	}
	for(j = 0; j < N; j++){
		for(i = 0; i < N; i++){
			for(k = i + 1; k < N; k++){
				if(A[k][j] == 'U'){
					set_edge_graph(pos_to_int(i, j, N), pos_to_int(k, j, N), 1, g);
				}
			}
		}
		for(i = N - 1; i >= 0; i--){
			for(k = i - 1; k >= 0; k--){
				if(A[k][j] == 'D'){
					set_edge_graph(pos_to_int(i, j, N), pos_to_int(k, j, N), 1, g);
				}
			}
		}
	}
	build_graph(g);
/*	for(i = 0; i < g->N; i++){
		printf("i = %d: ", i);
		graph_vertex *nowv = g->v[i];
		for(j = 0; j < nowv->next_num; j++){
			printf("%d ", nowv->next[j]->num);
		}
		printf("\n");
	}
*/	dag = build_DAG(g, 0);
//	printf("dag->N = %d\n", dag->N);
	char *ansc = (char *)malloc(sizeof(char) * N * N);
	int *ansd = (int *)malloc(sizeof(int) * N * N);
	for(i = 0; i < dag->N; i++){
		p = int_to_pos(dag->sorted_SCC[i]->vertexs[0], N);
		ansc[i] = A[p.x][p.y];
		if(B1[p.x][p.y] == 0){
			ansd[i] = p.x;
		}
		else{
			ansd[i] = p.y;
		}
	}
	//deback
/*	int **B3 = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		B3[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++){
			B3[i][j] = -1;
		}
	}
	for(i = 0; i < N * N; i++){
		if(ansc[i] == 'L'){
			for(j = 0; j < N; j++){
				if(B3[ansd[i]][j] == -1){
					B3[ansd[i]][j] = i;
					break;
				}
			}
			if(j == N){
				printf("doubt!\n");
				return 0;
			}
		}
		if(ansc[i] == 'R'){
			for(j = N - 1; j >= 0; j--){
				if(B3[ansd[i]][j] == -1){
					B3[ansd[i]][j] = i;
					break;
				}
			}
			if(j == -1){
				printf("doubt!\n");
				return 0;
			}
		}
		if(ansc[i] == 'U'){
			for(j = 0; j < N; j++){
				if(B3[j][ansd[i]] == -1){
					B3[j][ansd[i]] = i;
					break;
				}
			}
			if(j == N){
				printf("doubt!\n");
				return 0;
			}
		}
		if(ansc[i] == 'D'){
			for(j = N - 1; j >= 0; j--){
				if(B3[j][ansd[i]] == -1){
					B3[j][ansd[i]] = i;
					break;
				}
			}
			if(j == -1){
				printf("doubt!\n");
				return 0;
			}
		}
	}
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%2d", B3[i][j]);
		}
		printf("\n");
	}
*/	for(i = 0; i < N * N; i++){
		printf("%c%d\n", ansc[i], ansd[i] + 1);
	}
	return 0;
}