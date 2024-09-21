#include <stdio.h>
#include <stdlib.h>

static unsigned int x=675666;
static unsigned int y=46465752;
static unsigned int z=824557;
static unsigned int w=42856522;

void seed(unsigned int a,unsigned int b,unsigned int c,unsigned int d) {
	if((a|b|c|d)==0)return;
	x=a;y=b;z=c;w=d;
}

unsigned int randint(void) {
	unsigned int t;
	t=(x^(x<<11));
	x=y;y=z;z=w;
	w=(w^(w>>19))^(t^(t>>8));
	return w;
}

#define MAX 200000

int N, M;
int A[MAX];
int B[MAX];

int count[MAX];

int kisuCount = 0;
int kisu[MAX];

char kisuFlag[MAX];
int kRinsetuCount[MAX];
int* kRinsetu[MAX];
int* kRinsetuIdx[MAX];
int* kTryCount[MAX];

int main(void) {
	int i, j, r;
	int ok;
	for (r = 0; r < 100; r++) randint();
	if (scanf("%d%d", &N, &M) != 2) return 1;
	for (i = 0; i < M; i++) {
		if (scanf("%d%d", &A[i], &B[i]) != 2) return 1;
	}
	for (r = 0; r < 50; r++) {
		/* ランダムにひっくり返す */
		for (i = 0; i < M; i++) {
			if (randint() % 32 == 0) {
				int t = A[i];
				A[i] = B[i];
				B[i] = t;
			}
		}

		for (i = 0; i < M; i++) {
			count[A[i] - 1]++;
		}
		for (i = 0; i < N; i++) {
			if (count[i] % 2 != 0) {
				kisu[kisuCount++] = i;
			}
		}
		for (i = 0; i < kisuCount; i++) {
			kisuFlag[kisu[i]] = 1;
		}
		for (i = 0; i < M; i++) {
			if (kisuFlag[A[i]]) {
				int idx = A[i] - 1;
				int c = ++kRinsetuCount[idx];
				kRinsetu[idx] = realloc(kRinsetu[idx], sizeof(int) * c);
				if (kRinsetu[idx] == NULL) return 1;
				kRinsetu[idx][c - 1] = B[i] - 1;
				kRinsetuIdx[idx] = realloc(kRinsetuIdx[idx], sizeof(int) * c);
				if (kRinsetuIdx[idx] == NULL) return 1;
				kRinsetuIdx[idx][c - 1] = i;
			}
		}
		for (i = 0; i < N; i++) {
			kTryCount[i] = calloc(kRinsetuCount[i], sizeof(int));
			if (kTryCount[i] == NULL) return 1;
		}
		/* 貪欲 */
		for (i = 0; i < N; i++) {
			if (kisuFlag[i] && kRinsetuCount[i] > 0) {
				for (j = 0; j < kRinsetuCount[i]; j++) {
					if (kisuFlag[kRinsetu[i][j]] && kTryCount[i][j] < 2) {
						kisuFlag[i] = 0;
						kisuFlag[kRinsetu[i][j]] = 0;
						kTryCount[i][j]++;
						{
							int idx = kRinsetuIdx[i][j], t;
							t = A[idx];
							A[idx] = B[idx];
							B[idx] = t;
						}
						break;
					}
				}
#if 0
				if (kisuFlag[i]) {
					/* 奇数となるペアが見つからなかった */
					int hoge = -1, fuga = -1;
					for (j = 0; j < kRinsetuCount[i]; j++) {
						if (kTryCount[i][j] < 2) {
							if (hoge < 0 && kRinsetu[i][j] > i) {
								hoge = j;
							}
							if (fuga < 0) {
								fuga = j;
							}
						}
					}
					if (hoge < 0) hoge = fuga;
					if (hoge >= 0) {
						kisuFlag[i] = 0;
						kisuFlag[kRinsetu[i][hoge]] = 1;
						kTryCount[i][hoge]++;
						{
							int idx = kRinsetuIdx[i][hoge], t;
							t = A[idx];
							A[idx] = B[idx];
							B[idx] = t;
						}
						if (kRinsetu[i][hoge] < i) i = kRinsetu[i][hoge] - 1;
					}
				}
#endif
            }
		}
		ok = 1;
		for (i = 0; i < N; i++) {
			if (kisuFlag[i]) {
				ok = 0;
				break;
			}
		}
		if (!ok) {
			for (i = 0; i < N; i++) {
				free(kRinsetu[i]);
				free(kRinsetuIdx[i]);
				free(kTryCount[i]);
				kRinsetuCount[i] = 0;
				kRinsetu[i] = NULL;
				kRinsetuIdx[i] = NULL;
				kTryCount[i] = NULL;
				count[i] = 0;
				kisuFlag[i] = 0;
			}
			kisuCount = 0;
			continue;
		}
		for (i = 0; i < M; i++) {
			printf("%d %d\n", A[i], B[i]);
		}
		return 0;
	}
	puts("-1");
	return 0;
}

/*

Aをカウント→奇数な頂点が奇数個ならできない
奇数な頂点が偶数個のとき…
奇数な頂点だけを選んでできるか？
何も考えず貪欲できるか？

4 4
1 2
2 3
2 4
4 1

一般マッチング？

ケース例1

5 6
1 2
5 1
5 2
5 3
5 4
3 4

出力例1

1 2
1 5
5 2
3 5
5 4
3 4


*/
