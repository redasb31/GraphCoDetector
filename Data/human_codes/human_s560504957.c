// AOJ 3109 Canisar Cipher
// 2019.9.23 bal4u

#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

//// 入出力関係
#if 1
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#else
#define gc() getchar()
#define pc(x) putchar(x)
#endif

int in() {   // 非負整数の入力
	int n = 0; int c = gc();
	do n = 10 * n + (c & 0xf); while ((c = gc()) >= '0');
	return n;
}

int ins(char *s) { // 文字列の入力（特殊）
	char *p = s--; int c;
	do c = gc(), *++s = c & 0xf;
	while (c > ' ');
	return s - p;
}

#define MOD 1000000007
int M;
char C[100005]; int w;
ll p[10];
char d[12] = {0,1,2,3,4,5,6,7,8,9,10,11}; int K = 10;

void calc(void) {
	int i; ll s = 0;
	i = 10; while (i--) s += p[i] * d[i];
	if (s % MOD == M) {
		for (i = 0; i < w; i++) pc(d[C[i]]+'0');
		pc('\n');
		exit(0);
	}
}

/* algorithm of next_permutation in lexicographic order
    Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
    Find the largest index l greater than k such that a[k] < a[l].
    Swap the value of a[k] with that of a[l].
    Reverse the sequence from a[k + 1] up to and including the final element a[n].
*/
void next_permutation(void) {
	int k, l, r, t;
	
	// 右端にある最も長い降順部分列 d[k+1]... d[K-1]をみつける
	k = K-2; while (k >= 0 && d[k] > d[k+1]) k--;
	
	// 上記の降順部分列を昇順列に戻す
	l = k+1, r = K-1;
	while (l < r) t = d[l], d[l] = d[r], d[r] = t, l++, r--;
	if (k < 0) return;
	
	//d[k]より大きい要素 d[r]を見つけ、交換する
	r = k+1; while (d[k] > d[r]) r++;
	t = d[r], d[r] = d[k], d[k] = t;
}

int main()
{
	int i; ll t;
	
	M = in(), w = ins(C);
	if (M == 0 && w == 1) { puts("0"); return 0; }
	t = 1, i = w; while (i--) {
		p[C[i]] = (t + p[C[i]]) % MOD;
		t = t*10 % MOD;
	}
	i = 3628800; // 10!
	while (i--) {
		if (d[C[0]]) calc();
		next_permutation();
	}
	puts("-1");
	return 0;
}

