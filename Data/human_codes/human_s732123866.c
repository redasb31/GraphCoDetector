#include <stdio.h>
#include <stdlib.h>

int COMPARE(const void *a, const void *b){ return *(int*)b - *(int*)a; }  /* 降順 */

/*
	正六面体のサイコロにおいて、下の面に 0 、上の面に 5 、
	東北南西を向くの面にそれぞれ 1 2 3 4 の番号をつける。
*/
int dice[6];  /* サイコロの面に書かれた数字 */
char code[4] = {'E', 'N', 'S', 'W'};  /* 方向を表す文字 */
/*
	サイコロを90度回転させたときに、各面に回転前のどの面が来るかを配列で定義する。
	next[ 回転方向 ][ 面番号 ] として用いる。
*/
int next[4][6] = {{1, 5, 2, 3, 0, 4}, {2, 1, 5, 0, 4, 3}, {3, 1, 0, 5, 4, 2}, {4, 0, 2, 3, 5, 1}};

char process[5000*6];  /* 操作列 */
int limit;  /* 操作数の上限 */

int t[720][6];  /* 目標の数字の順列 */
int t_num;  /* 順列の個数 */
int p, q;


/* 指定された方向へサイコロを90度回転させる */
void rotate(int d){
	int buffer[6];
	int i;
	for (i = 0; i < 6; i++) buffer[i] = dice[i];
	for (i = 0; i < 6; i++) dice[i] = buffer[next[d][i]];
}

/* 入力する */
int input(){
	int i;
	for (i = 0; i < 6; i++) if (scanf("%d", &t[0][i]) != 1) t[0][i] = 0;  /* t1, ..., t6 を入力する */
	for (i = 0; i < 6; i++) if (t[0][i] != 0) break;  /* 入力終了を判定する */
	if (!(i < 6)) return 0;
	if (scanf("%d%d", &p, &q) != 2) return 0;  /* p, q を入力する */
}

/* 目標となるサイコロの面の数字列を生成する */
int generated[6];
int used[6];
void generatePermutation(int n){
	int i;
	if (n == 6){
		/* t_num 番目の数字列の生成を完了する */
		i = 0;
		if (t_num > 0){
			/* 重複を排除する */
			for (; i < 6; i++){
				if (generated[i] != t[t_num-1][i]) break;
			}
		}
		if (i < 6){
			for (i = 0; i < 6; i++) t[t_num][i] = generated[i];
			t_num++;
		}
		return;
	}

	/* n 番目の数字を決定する */
	for (i = 0; i < 6; i++){
		if (used[i]) continue;
		used[i] = 1;
		generated[n] = t[0][i];
		generatePermutation(n + 1);  /* n + 1 番目の数字を決定する */
		used[i] = 0;
	}
}

/* 初期化する */
void init(){
	int i, j[6];
	limit = 0;
	for (i = 0; i < 6; i++){
		dice[i] = 0;
		limit += t[0][i];
	}

	qsort(t[0], 6, sizeof(int), COMPARE);  /* 降順にソートする */

	/* 目標となるサイコロの数字の順列を生成する */
	/* t[0] がソート済みなので、ここで生成される順列の配列もソートされている */
	t_num = 0;
	for (i = 0; i < 6; i++) used[i] = 0;
	generatePermutation(0);
}

/* サイコロの完成を判定する */
/* 完成なら 1 、未完成なら 0 、完成不可能なら -1 を返す */
int judge1(int i){
	int d[6], j, r;
	r = 1;
	for (j = 0; j < 6; j++){
		d[j] = t[i][j] - dice[j];
		if (d[j] < 0) return -1;
		if (d[j] > 0) r = 0;
	}
	if (r == 1) return 1;

	/* 互いに裏となる面の組  0 と 5 、 1 と 4 、 2 と 3 について考える */
	/* 組となる面の数字の和を増やすには、必ずそれ以外の面を通らねばならない */
	if (d[0] + d[5] > d[1] + d[2] + d[3] + d[4] ||
		d[1] + d[4] > d[0] + d[2] + d[3] + d[5] + 1 ||
		d[2] + d[3] > d[0] + d[1] + d[4] + d[5] + 1) return -1;
	return r;
}
int judge(){
	int i, r0, r1;

	r0 = -1;
	for (i = 0; i < t_num; i++){
		r1 = judge1(i);
		if (r1 == 1) return 1;
		if (r1 == 0) r0 = 0;
	}

	return r0;
}

/* サイコロを作る操作列を深さ優先探索で探す */
/* サイコロを作ることが可能なら 1 を、不可能なら 0 を返す */
int try(int step){
	int i, j;
	if (step > limit) return 0;

	/* 完成を判定する */
	j = judge();
	if (j == 1) return 1;
	if (j == -1) return 0;

	for (i = 0; i < 4; i++){
		rotate(i);  /* 回転させる */
		dice[0]++;

		if (step >= p - 1 && step < q) process[step] = code[i];  /* 操作を記録する */
		if (try(step + 1)) return 1;

		dice[0]--;
		rotate(3 - i);  /* 元に戻す */
	}
	return 0;
}

int main(void){
	int i;

	while (input()){
		init();
		/* 試行し結果を出力する */
		if (try(0)){
			for (i = p - 1; i < q; i++) printf("%c", process[i]);
			printf("\n");
		}else{
			printf("impossible\n");
		}
	}

    return 0;
}