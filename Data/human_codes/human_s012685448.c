// AOJ 2344: Multi Ending Story
// 2017.11.23 for test

#include <stdio.h>

#define MIN(a,b) ((a)<=(b)?(a):(b))
#define MAX 500002
int L[MAX], R[MAX], D[MAX];
long long E[MAX], U[MAX], S[MAX];

char buf[20], *p;
int getint()
{
	int n = 0;
	while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
	return n;
}

int main()
{
	int n, i, l, r;

	fgets(p=buf, 10, stdin), n = getint();
	for (i = 1; i < n; i++) {
		fgets(p=buf, 20, stdin);
		L[i] = getint(), p++, R[i] = getint();
	}
	for (i = 1; i < n; i++) D[L[i]] = D[R[i]] = D[i]+1;
	E[n] = 1;
	for (i = n-1; i > 0; i--) {
		l = L[i], r = R[i];
		E[i] = E[l] + E[r];
		U[i] = E[i] + U[l] + U[r];
		S[i] = MIN(D[i]+S[l]+S[r]+2, MIN(S[l]+U[r]+E[r]+1, S[r]+U[l]+E[l]+1));
	}
	printf("%lld\n", MIN(U[1], S[1]));
	return 0;
}