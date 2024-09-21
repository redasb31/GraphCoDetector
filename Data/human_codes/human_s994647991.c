// 420 Digits K
// 2019.12.26 bal4u

#include <stdio.h>

#if 1
#define gc() getchar_unlocked()
#define pc(c) putchar_unlocked(c)
#else
#define gc() getchar()
#define pc(c) putchar(c)
#endif

int in() {   // 非負整数の入力
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf); while ((c = gc()) >= '0');
	return n;
}

char A[200005];
typedef struct { char a; int i; } T;
T a[200005], b[200005];
int f[128];

void distsort(T *ain, T *aout, int sz) {
	int i, x;

	for (i = 0; i < sz; ++i) ++f[ain[i].a];
	for (i = '9'; i > '0'; i--) f[i-1] += f[i];
	for (i = sz-1; i >= 0; i--) {
		x = ain[i].a, aout[--f[x]].a = x, aout[f[x]].i = ain[i].i;
	}
}

int main()
{
	int i, k, K, N;
	
    N = in(), K = in();
    if (K == 0) {
        while (N--) pc(gc()), gc();
    } else {
        for (i = 0; i < N; ++i) {
			A[i] = gc(), gc();
			b[i].i = i, b[i].a = A[i];
		}
		distsort(b, a, N);
		
		k = -1;
		for (i = 0; K < N; ++i) {
			if (a[i].a < A[K]) break;
			if (k < a[i].i && a[i].i < K) {
				pc(a[i].a), k = a[i].i, ++K;
			}
		}
		while (K < N) pc(A[K++]);
	}
	pc('\n');
	return 0;
}
