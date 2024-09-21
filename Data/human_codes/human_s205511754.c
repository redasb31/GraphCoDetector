// AOJ 2096: Private Teacher
// 2017.11.7 bal4u@uu

#include <stdio.h>
#include <string.h>

#define SIZE      110
long long cap[SIZE][SIZE];
char used[SIZE];
int  n;                 /* number of nodes */

long long augementPath(int s, int t, long long f)
{
	int i;
	long long u, v;

	if (s == t) return f;
	used[s] = 1;
	for (i = 0; i < n; i++) {
		if (!used[i] && cap[s][i] > 0) {
			u = cap[s][i];
			if (u > f) u = f;
			v = augementPath(i, t, u);
			if (v > 0) {
				cap[s][i] -= v, cap[i][s] += v;
				return v;
			}
		}
	}
	return 0;
}

long long maxflow(int s, int t)
{
	long long v, flow = 0;

	while (1) {
		memset(used, 0, sizeof(used));
		v = augementPath(s, t, 1LL<<60);
		if (v == 0) break;
		flow += v;
	}
	return flow;
}

char w[7][3] = { "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa" };
int tr[26][26];

int main()
{
	int N, i, c, src, sink;
	long long W, t, sum;
	char buf[10];

	for (i = 0; i < 7; i++) tr[w[i][0]-'A'][w[i][1]-'a'] = i;

	while (scanf("%d%lld", &N, &W) && N > 0) {
		memset(cap, 0, sizeof(cap));
		src = 0, sink = 1, n = 2+7+N;
		for (i = 2; i < 9; i++) cap[src][i] = W;

		sum = 0;
		for (i = 0; i < N; i++) {
			scanf("%lld", &t);
			sum += t;
			cap[i+9][sink] = t;
			scanf("%d", &c);
			while (c--) {
				scanf("%s", buf);
				cap[2 + tr[*buf-'A'][*(buf+1)-'a']][i+9] = W;
			}
		}
 		puts(maxflow(src, sink) == sum ? "Yes" : "No");
	}
    return 0;
}