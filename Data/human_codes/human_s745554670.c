// AOJ GRL_3_B Bridges
// 2018.5.7 bal4u
// https://everysick.hatenablog.com/entry/2016/06/13/120033 を参考にした
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_V 100002
#define MAX_E 100002

typedef struct { int s, t; } EDGE;		// ブリッジ（橋）になる辺
EDGE bridge[MAX_E]; int sz;				// s < t となっている

int  hi[MAX_V], *to[MAX_V];
int  low[MAX_V], pre[MAX_V];
int  cnt;

int dfs(int cur, int from)
{
	int i, e, t;
	
	low[cur] = pre[cur] = ++cnt;
	for (i = 0; i < hi[cur]; i++) {
		e = to[cur][i];

		if (!pre[e]) {
			t = dfs(e, cur);
			if (t < low[cur]) low[cur] = t;
			if (pre[e] == low[e]) {
				if (cur < e) bridge[sz].s = cur, bridge[sz].t = e; // 出力に合わせる
				else         bridge[sz].s = e,   bridge[sz].t = cur;
				sz++;
			}
		} else if (from != e) {
			t = low[e];
			if (t < low[cur]) low[cur] = t;
		}
	}
	return low[cur];
} 

void check_bridge(int V)
{
	int i;
	for (i = 0; i < V; i++) {
		if (!pre[i]) dfs(i, i);
	}
}

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

int cmp(EDGE *a, EDGE *b) { if (a->s - b->s) return a->s - b->s; return a->t - b->t; }

int main()
{
    int E, V, s, t, i, j;
    int *memo;
 
    V = in(), E = in();
    memo = malloc(E<<3);
    j = 0; for (i = 0; i < E; i++) {
        memo[j++] = s = in(), memo[j++] = t = in();
        hi[s]++, hi[t]++;
     }
    for (i = 0; i < V; i++) {
        if (hi[i]) to[i] = malloc(hi[i]<<2);
    }
    memset(hi, 0, V<<2);
 
    j = 0; while (E--) {
        s = memo[j++], t = memo[j++];
		to[s][hi[s]++] = t, to[t][hi[t]++] = s;
    }
 
    check_bridge(V);
 
	qsort(bridge, sz, sizeof(EDGE), cmp);

	for (i = 0; i < sz; i++) {
		out(bridge[i].s), pc(' '), out(bridge[i].t), pc('\n');
	}
    return 0;
}
