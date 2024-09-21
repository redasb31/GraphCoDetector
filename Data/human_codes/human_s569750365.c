#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define int long long
#define inf (int)(1e18)
#define AVL_keytype tuple
#define AVL_valtype int

typedef struct {
	int C;
	int num;
	int V;
}tuple;


//static int malloc_cont;
//static int free_cont;

typedef struct AVL_node_sub{
	AVL_keytype key; //添え字
	AVL_valtype val; //値
	int ele_num; //木に含まれる要素数
	int height; //木の高さ
	struct AVL_node_sub *left; //左の子へのポインタ
	struct AVL_node_sub *right; //右の子へのポインタ
}AVL_node;

typedef struct {
	AVL_node *root;
}AVL_tree;

int max(int a, int b){
	return a >= b ? a : b;
}

//比較関数
//a < b なら負の値
//a = b なら0
//a > b なら正の値
int compare_AVL(AVL_keytype a, AVL_keytype b){
	if(a.V != b.V){
		return a.V - b.V;
	}
	else if(a.C != b.C){
		return a.C - b.C;
	}
	else{
		return a.num - b.num;
	}
}

int ele_num(AVL_node *r){
	if(r == NULL){
		return 0;
	}
	else{
		return r->ele_num;
	}
}

int height(AVL_node *r){
	if(r == NULL){
		return 0;
	}
	else{
		return r->height;
	}
}

//tの指すノードを開放する
//AVL_valtypeなどがポインタ型の時はそれもfreeする
void release_AVL_node(AVL_node *r){
	free(r);
//	free_cont++;
}

AVL_node *build_AVL_node(AVL_keytype key, AVL_valtype val, AVL_node *left, AVL_node *right){
	AVL_node *newr;
	int left_h = height(left);
	int right_h = height(right);
	if(left_h > right_h + 1){
		AVL_node *ll = left->left;
		AVL_node *lr = left->right;
		if(height(ll) < height(lr)){
			newr = build_AVL_node(lr->key, lr->val, build_AVL_node(left->key, left->val, ll, lr->left), build_AVL_node(key, val, lr->right, right));
			release_AVL_node(lr);
		}
		else{
			newr = build_AVL_node(left->key, left->val, ll, build_AVL_node(key, val, lr, right));
		}
		release_AVL_node(left);
	}
	else if(right_h > left_h + 1){
		AVL_node *rr = right->right;
		AVL_node *rl = right->left;
		if(height(rr) < height(rl)){
			newr = build_AVL_node(rl->key, rl->val, build_AVL_node(key, val, left, rl->left), build_AVL_node(right->key, right->val, rl->right, rr));
			release_AVL_node(rl);
		}
		else{
			newr = build_AVL_node(right->key, right->val, build_AVL_node(key, val, left, rl), rr);
		}
		release_AVL_node(right);
	}
	else{
//		malloc_cont++;
		newr = (AVL_node *)malloc(sizeof(AVL_node));
		newr->key = key;
		newr->val = val;
		newr->ele_num = ele_num(left) + ele_num(right) + 1;
		newr->height = max(left_h, right_h) + 1;
		newr->left = left;
		newr->right = right;
	}
	return newr;
}

AVL_node *find_AVL_sub(AVL_keytype key, AVL_node *r){
	if(r == NULL){
		return NULL;
	}
	int comp = compare_AVL(key, r->key);
	if(comp == 0){
		return r;
	}
	else if(comp < 0){
		return find_AVL_sub(key, r->left);
	}
	else{
		return find_AVL_sub(key, r->right);
	}
}

AVL_node *kth_smallest_AVL_sub(int k, AVL_node *r){
	if(r == NULL || k < 1){
		printf("In function 'kth_smallest_AVL_sub':\nargument 'k' is out of range\n");
		return NULL;
	}
	else if(r->ele_num < k){
		printf("In function 'kth_smallest_AVL_sub':\nargument 'k' is out of range\n");
		return NULL;
	}
	else if(ele_num(r->left) == k - 1){
		return r;
	}
	else if(ele_num(r->left) > k - 1){
		return kth_smallest_AVL_sub(k, r->left);
	}
	else{
		return kth_smallest_AVL_sub(k - ele_num(r->left) - 1, r->right);
	}
}

int num_less_than_AVL_sub(AVL_keytype key, AVL_node *r){
	if(r == NULL){
		return 0;
	}
	else if(compare_AVL(key, r->key) < 0){
		return num_less_than_AVL_sub(key, r->left);
	}
	else{
		return ele_num(r->left) + num_less_than_AVL_sub(key, r->right) + 1;
	}
}

AVL_node *next_largest_AVL_sub(AVL_keytype key, AVL_node *r){
	if(r == NULL){
		return NULL;
	}
	else if(compare_AVL(key, r->key) <= 0){
		return next_largest_AVL_sub(key, r->left);
	}
	else{
		AVL_node *candidate = next_largest_AVL_sub(key, r->right);
		if(candidate == NULL){
			return r;
		}
		else{
			return candidate;
		}
	}
}

AVL_node *next_smallest_AVL_sub(AVL_keytype key, AVL_node *r){
	if(r == NULL){
		return NULL;
	}
	else if(compare_AVL(key, r->key) >= 0){
		return next_smallest_AVL_sub(key, r->right);
	}
	else{
		AVL_node *candidate = next_smallest_AVL_sub(key, r->left);
		if(candidate == NULL){
			return r;
		}
		else{
			return candidate;
		}
	}
}

AVL_node *insert_AVL_sub(AVL_keytype key, AVL_valtype val, AVL_node *r){
	AVL_node *newr;
	if(r == NULL){
		newr = build_AVL_node(key, val, NULL, NULL);
	}
	else{
		int comp = compare_AVL(key, r->key);
		if(comp == 0){
			printf("In function 'insert_AVL_sub':\nkey '%d' already exists\n", key);
			newr = build_AVL_node(r->key, val, r->left, r->right);
		}
		else if(comp < 0){
			newr = build_AVL_node(r->key, r->val, insert_AVL_sub(key, val, r->left), r->right);
		}
		else{
			newr = build_AVL_node(r->key, r->val, r->left, insert_AVL_sub(key, val, r->right));
		}
		release_AVL_node(r);
	}
	return newr;
}

AVL_node *erase_AVL_sub_sub(AVL_node *r){
	if(r->left == NULL){
		return r->right;
	}
	else{
		return build_AVL_node(r->key, r->val, erase_AVL_sub_sub(r->left), r->right);
	}
}

AVL_node *erase_AVL_sub(AVL_keytype key, AVL_node *r, AVL_node **ans){
	AVL_node *newr;
	if(r == NULL){
		newr = NULL;
	}
	else{
		int comp = compare_AVL(key, r->key);
		if(comp == 0){
			*ans = r;
			if(r->left == NULL && r->right == NULL){
				newr = NULL;
			}
			else if(r->right == NULL){
				newr = r->left;
			}
			else if(r->left == NULL){
				newr = r->right;
			}
			else{
				AVL_node *next_larger = kth_smallest_AVL_sub(1, r->right);
				newr = build_AVL_node(next_larger->key, next_larger->val, r->left, erase_AVL_sub_sub(r->right));
				release_AVL_node(next_larger);
			}
		}
		else{
			if(comp < 0){
				newr = build_AVL_node(r->key, r->val, erase_AVL_sub(key, r->left, ans), r->right);
			}
			else{
				newr = build_AVL_node(r->key, r->val, r->left, erase_AVL_sub(key, r->right, ans));
			}
			release_AVL_node(r);
		}
	}
	return newr;
}

void storeall_AVL_sub(AVL_keytype *array, int k, AVL_node *r){
	if(r != NULL){
		storeall_AVL_sub(array, k, r->left);
		array[k + ele_num(r->left)] = r->key;
		storeall_AVL_sub(array, k + ele_num(r->left) + 1, r->right);
	}
}

void outall_AVL_sub(AVL_node *r){
	if(r != NULL){
		outall_AVL_sub(r->left);
		printf("(key, val, ele_num, height) = (%d, %d, %d, %d)\n", r->key, r->val, r->ele_num, r->height);
		outall_AVL_sub(r->right);
	}
}

//AVL_treeを生成する
AVL_tree *make_AVL_tree(){
	AVL_tree *t = (AVL_tree *)malloc(sizeof(AVL_tree));
	t->root = NULL;
	return t;
}

//tに含まれるノードの数を返す
int element_num_AVL(AVL_tree *t){
	return ele_num(t->root);
}

//添え字がkeyのノードへのポインタを返す
//なければNULLを返す
AVL_node *find_AVL(AVL_keytype key, AVL_tree *t){
	return find_AVL_sub(key, t->root);
}

//小さい順にk番目のkeyのノードへのポインタを返す
//1 ≦ k ≦ ele_num(t->root) を満たさない場合はNULLを返す(メッセージが出る)
AVL_node *kth_smallest_AVL(int k, AVL_tree *t){
	return kth_smallest_AVL_sub(k, t->root);
}

//添え字がkey以下のノードの数を返す
int num_less_than_AVL(AVL_keytype key, AVL_tree *t){
	return num_less_than_AVL_sub(key, t->root);
}

//keyよりも小さい中で最大の添え字のノードへのポインタを返す
//なければNULLを返す
AVL_node *next_largest_AVL(AVL_keytype key, AVL_tree *t){
	return next_largest_AVL_sub(key, t->root);
}

//keyよりも大きい中で最小の添え字のノードへのポインタを返す
//なければNULLを返す
AVL_node *next_smallest_AVL(AVL_keytype key, AVL_tree *t){
	return next_smallest_AVL_sub(key, t->root);
}

//添え字key, 値valのノードを挿入する
//既に存在する場合は値が上書きされる(メッセージが出る)
void insert_AVL(AVL_keytype key, AVL_valtype val, AVL_tree *t){
	t->root = insert_AVL_sub(key, val, t->root);
}

//添え字keyのノードを削除しそれを返す
//存在しない場合はNULLを返す
AVL_node *erase_AVL(AVL_keytype key, AVL_tree *t){
	AVL_node *ans = NULL;
	t->root = erase_AVL_sub(key, t->root, &ans);
	return ans;
}

//全ノードのkeyを小さい順に格納した配列を返す
AVL_keytype *storeall_AVL(AVL_tree *t){
	AVL_keytype *array = (AVL_keytype *)malloc(sizeof(AVL_keytype) * element_num_AVL(t));
	storeall_AVL_sub(array, 0, t->root);
	return array;
}

//全ノードの中身をkeyの小さい順に出力する
void outall_AVL(AVL_tree *t){
	outall_AVL_sub(t->root);
}


signed compare_int_rev(const void *a, const void *b){
	int sub = *(int *)b - *(int *)a;
	if(sub < 0){
		return -1;
	}
	else if(sub == 0){
		return 0;
	}
	else{
		return 1;
	}
}

signed compare_tuple(const void *_a, const void *_b){
	tuple a = *(tuple *)_a, b = *(tuple *)_b;
	int sub;
	if(a.V != b.V){
		sub = b.V - a.V;
	}
	else if(a.C != b.C){
		sub = a.C - b.C;
	}
	else{
		sub = a.num - b.num;
	}
	if(sub < 0){
		return -1;
	}
	else if(sub == 0){
		return 0;
	}
	else{
		return 1;
	}
}

typedef struct {
	int C_num;
	int *CV;
}pair_CV;

signed compare_pair_CV(const void *_a, const void *_b){
	pair_CV a = *(pair_CV *)_a, b = *(pair_CV *)_b;
	int sub = (b.CV)[0] - (a.CV)[0];
	if(sub < 0){
		return -1;
	}
	else if(sub == 0){
		return 0;
	}
	else{
		return 1;
	}
}

signed main(){
	int N, K, i, j, k;
	scanf("%lld%lld", &N, &K);
	int *C = (int *)malloc(sizeof(int) * N);
	int *V = (int *)malloc(sizeof(int) * N);
	int *C_num = (int *)malloc(sizeof(int) * K);
	for(i = 0; i < K; i++){
		C_num[i] = 0;
	}
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &C[i], &V[i]);
		C[i]--;
		V[i] *= 2;
		C_num[C[i]]++;
	}
	int **CV = (int **)malloc(sizeof(int *) * K);
	for(i = 0; i < K; i++){
		CV[i] = (int *)malloc(sizeof(int) * C_num[i]);
		C_num[i] = 0;
	}
	for(i = 0; i < N; i++){
		CV[C[i]][C_num[C[i]]] = V[i];
		C_num[C[i]]++;
	}
	for(i = 0; i < K; i++){
		qsort(CV[i], C_num[i], sizeof(int), compare_int_rev);
		CV[i][0] += CV[i][1];
		CV[i][0] /= 2;
		CV[i][1] = CV[i][0];
	}
	pair_CV *pCVs = (pair_CV *)malloc(sizeof(pair_CV) * K);
	for(i = 0; i < K; i++){
		pCVs[i] = (pair_CV){C_num[i], CV[i]};
	}
/*	printf("before sort\n");
	for(i = 0; i < K; i++){
		printf("%lld ", pCVs[i].C_num);
	}
	printf("\n");
*/	qsort(pCVs, K, sizeof(pair_CV), compare_pair_CV);
/*	printf("after sort\n");
	for(i = 0; i < K; i++){
		printf("%lld ", pCVs[i].C_num);
	}
	printf("\n");
*/	for(i = 0; i < K; i++){
		C_num[i] = pCVs[i].C_num;
		CV[i] = pCVs[i].CV;
	}
/*	for(i = 0; i < K; i++){
		printf("C_num[%lld] = %lld\n", i, C_num[i]);
		for(j = 0; j < C_num[i]; j++){
			printf("%lld ", CV[i][j]);
		}
		printf("\n");
	}
*/	int *top_three = (int *)malloc(sizeof(int) * K);
	for(i = 0; i < K; i++){
		if(C_num[i] < 3){
			top_three[i] = -inf;
		}
		else{
			top_three[i] = CV[i][0] + CV[i][1] + CV[i][2];
		}
	}
	int *top_three_max = (int *)malloc(sizeof(int) * (K + 1));
	top_three_max[K] = -inf;
	for(i = K - 1; i >= 0; i--){
		top_three_max[i] = max(top_three_max[i + 1], top_three[i]);
	}
/*	printf("top_three_max:\n");
	for(i = 0; i < K; i++){
		printf("%lld ", top_three_max[i]);
	}
	printf("\n");
*/	tuple *tps = (tuple *)malloc(sizeof(tuple) * N);
	for(i = 0, k = 0; i < K; i++){
		for(j = 0; j < C_num[i]; j++){
			tps[k] = (tuple){i, j, CV[i][j]};
			k++;
		}
	}
	qsort(tps, N, sizeof(tuple), compare_tuple);
	AVL_tree *t_top = make_AVL_tree();
	AVL_tree *t_no_two = make_AVL_tree();
	AVL_tree *t_no_select = make_AVL_tree();
	AVL_node *r;
	int sum = 0, ans;
	for(i = 0; i < N; i++){
		insert_AVL(tps[i], 1, t_top);
		sum += tps[i].V;
		if(tps[i].num >= 2){
			insert_AVL(tps[i], 1, t_no_two);
		}
		AVL_node *res = erase_AVL(tps[i], t_no_select);
		if(tps[i].num == 1){
			for(j = 2; j < C_num[tps[i].C]; j++){
				insert_AVL((tuple){tps[i].C, j, CV[tps[i].C][j]}, 1, t_no_select);
			}
		}
		ans = -inf;
		if(tps[i].num > 0){
			ans = sum;
		}
		else{
			if(element_num_AVL(t_no_two) > 0){
				r = kth_smallest_AVL(1, t_no_two);
				ans = max(ans, sum + tps[i].V - (r->key).V);
			}
			if(element_num_AVL(t_no_select) > 0){
				r = kth_smallest_AVL(element_num_AVL(t_no_select), t_no_select);
				ans = max(ans, sum + (r->key).V - tps[i].V);
			}
			if(i >= 2){
				int minus = 0;
				r = kth_smallest_AVL(1, t_top);
				minus += (r->key).V;
				r = kth_smallest_AVL(2, t_top);
				minus += (r->key).V;
				r = kth_smallest_AVL(3, t_top);
				minus += (r->key).V;
				ans = max(ans, sum + top_three_max[tps[i].C] - minus);
			}
		}
		if(ans < 0){
			printf("-1\n");
		}
		else{
			printf("%lld\n", ans / 2);
		}
	}
	return 0;
}