// AOJ 2644 Longest Match
// 2018.5.13 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 1
#define gc() getchar_unlocked()
#define pc(c) putchar_unlocked(c)
#else
#define gc() getchar()
#define pc(c) putchar(c)
#endif

int in()
{
	int n = 0, c = gc();
	do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

void out(int n)
{
	int i;
	char ob[20];

	if (!n) pc('0');
	else {
		i = 0; while (n) ob[i++] = n%10 + '0', n/=10;
		while (i--) pc(ob[i]);
	}
}

int str(char *s)
{
	char *p = s, c;
	while ((c = gc()) > ' ') *p++ = c;
	*p = 0;
	return p-s;
}

#define INF   0x10101010
#define MAX_L 200005

char text[MAX_L]; int len;
char pa[20005], pb[20005]; int wa, wb;
int  sa[MAX_L], rank[MAX_L<<1];

/* 接尾辞配列 */
// rank[i]～[i+k] と rank[j]～[j+k] を比較
int k; // comstruct_sa()内で設定
int compare_sa(int i, int j)
{
	if (rank[i] != rank[j]) return rank[i] < rank[j];
	return rank[i+k] < rank[j+k];
}

// for qsort()
int cmp(int *a, int *b)
{
	int i = *a, j = *b;
	
	if (rank[i] != rank[j]) return rank[i] - rank[j];
	return rank[i+k] - rank[j+k];
}

// 文字列Sの接尾辞配列saを構築。   len:　strlen(s)
int tmp[MAX_L];
void construct_sa(char *s, int *sa)
{
	int i;
	
	memset(rank, -1, sizeof(rank));
	for(i = 0; i <= len; i++) {
		sa[i] = i;
		if (i < len) rank[i] = s[i];
	}
	
	for(k = 1; k <= len; k *= 2) {
		qsort(sa, len+1, sizeof(int), cmp);
		
		tmp[sa[0]] = 0;
		for(i = 1; i <= len; i++) {
			tmp[sa[i]] = tmp[sa[i-1]] + compare_sa(sa[i-1], sa[i]);
		}
		for(i = 0; i <= len; i++) rank[i] = tmp[i];
	}
}

// 接尾辞配列を用いた文字列検索　len = strlen(s), plen = strlen(t)
int lower_bound(int wt, char *t)
{
	int l = 0, r = len, m;
	while (l < r) {
		m = (l+r)>>1;
		if (memcmp(text+sa[m], t, wt) < 0) l = m+1; else r = m;
	}
	return l;
}

int upper_bound(int wt, char *t)
{
	int l = 0, r = len, m;
	while (l < r) {
		m = (l+r)>>1;
		if (memcmp(text+sa[m], t, wt) <= 0) l = m+1; else r = m;
	}
	return l - memcmp(text+sa[l], t, wt);
}

/* 空間木 */
// セグメント木の初期化：配列の確保と初期値による初期化
int minseg[1<<19];
int maxseg[1<<19];
int sz;

void segtree(int n, int init_val)
{
	sz = 2; while (sz < n) sz <<= 1;
	n = sz << 1;
	memset(minseg,  init_val, n << 2);
	memset(maxseg, -init_val, n << 2);
}

// k番目（0-index）の値を v に変更
void update(int k, int v)
{
	int p;

	k += sz - 1;
	minseg[k] = v, maxseg[k] = v;
	while (k > 0) {
		if (!(k & 1)) k--;
		p = k, k >>= 1;
		v = minseg[p++]; if (v > minseg[p]) v = minseg[p];
		minseg[k] = v;

		v = maxseg[p++]; if (v < maxseg[p]) v = maxseg[p];
		maxseg[k] = v;
	}
}

int query2min(int a, int b, int k, int l, int r) 
{
	int m, lmin, rmin;

	if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return minseg[k];
	k <<= 1, m = (l+r) >> 1;
    lmin = query2min(a, b, k+1, l, m);
    rmin = query2min(a, b, k+2, m, r);
	if (lmin > rmin) lmin = rmin;
    return lmin; 
}

int query2max(int a, int b, int k, int l, int r) 
{
	int m, lmax, rmax;

	if (r <= a || b <= l) return -1;
    if (a <= l && r <= b) return maxseg[k];
	k <<= 1, m = (l+r) >> 1;
    lmax = query2max(a, b, k+1, l, m);
    rmax = query2max(a, b, k+2, m, r);
	if (lmax < rmax) lmax = rmax;
    return lmax; 
}


int main()
{
	int i, m;
	int la, lb, ra, rb, l, r;

	len = str(text);
	construct_sa(text, sa);

	segtree(len+1, INF);
	for (i = 0; i <= len; i++) update(i, sa[i]); 

	m = in();
	while (m--) {
		wa = str(pa);
		wb = str(pb);

		la = lower_bound(wa, pa);
		lb = lower_bound(wb, pb);
		ra = upper_bound(wa, pa);
		rb = upper_bound(wb, pb);

		if (ra > len || rb > len) {
			pc ('0'), pc('\n');
			continue;
		}

		l = query2min(la, ra+1, 0, 0, sz);
		r = query2max(lb, rb+1, 0, 0, sz);

		if (l <= r && l+wa <= r+wb) out(r-l+wb);
		else pc('0');
		pc('\n');
	}
	return 0;
}
