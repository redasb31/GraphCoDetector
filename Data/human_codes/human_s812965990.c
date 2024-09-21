#include <stdio.h>
#include <stdlib.h>
#define R(i,a,n)for(int i=(int)(a);i<=(int)(n);i++)
#define Ma(x,y) ((x)>(y)?(x):(y))
int up(const void* a, const void* b){return *(int*)a - *(int*)b;}

int main() {
	int n, m, q, a[5][52], A[11], ans = 0, point;
	R(i, 0, 51)R(j, 1, 4)a[j][i] = 0;
	scanf("%d %d %d", &n, &m, &q);
	R(i, 1, q)R(j, 1, 4)scanf("%d", &a[j][i]);
//とても酷い全探索
	R(Z, 1, m) {
		A[1] = Z; R(X, Z, m) {
			A[2] = X; R(C, X, m) {
				A[3] = C; R(V, C, m) {
					A[4] = V; R(B, V, m) {
						A[5] = B; R(N, B, m) {
							A[6] = N; R(M, B, m) {
								A[7] = M; R(Q, M, m) {
									A[8] = Q; R(W, Q, m) {
										A[9] = W; R(E, W, m) {
											A[10] = E;
											qsort(A, 10, sizeof(int), up);
											point = 0;
											R(j, 1, q)if (A[a[2][j]] - A[a[1][j]] == a[3][j])point += a[4][j];
											ans = Ma(ans, point);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d", ans);
}