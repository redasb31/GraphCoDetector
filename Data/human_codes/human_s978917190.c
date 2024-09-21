#include <stdio.h>

#define MAXN 3000

long S[2][MAXN][MAXN];
int T[2][MAXN][MAXN];
int A[MAXN];

long deque ( int n, int m, int p)
{
	if ( T[p][n][m] == 1 ) return S[p][n][m];

	long tmp1,tmp2;
	if ( p == 0 ) {
		tmp1 = deque(n+1, m, 1)+A[n];
		tmp2 = deque(n,m-1,1)+A[m];
		T[p][n][m] = 1;
		return S[p][n][m] = (tmp1 > tmp2 ) ? tmp1:tmp2;
	} else {
		tmp1 = deque(n+1,m,0)-A[n];
		tmp2 = deque(n,m-1,0)-A[m];
		T[p][n][m] = 1;
		return S[p][n][m] = (tmp1 < tmp2 ) ? tmp1:tmp2;
	}
}

int main(void)
{
	int n,i,j;

	scanf("%d", &n);
	for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n; j++ ) T[0][i][j] = T[1][i][j] = 0;
	}
	for ( i = 0; i < n; i++ ) {
		S[0][i][i] = A[i], T[0][i][i] = 1;
		S[1][i][i] = -A[i], T[1][i][i] = 1;
	}

	printf("%ld\n",deque(0,n-1,0));

	return 0;
}
