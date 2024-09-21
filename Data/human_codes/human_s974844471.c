#include <stdio.h>

int main()
{
	int i, u, w, N, M, s[21], t[21], adj[51][51] = {};
	scanf("%d", &N);
	for (i = 1; i < N; i++) {
		scanf("%d %d", &u, &w);
		adj[u][w] = i;
		adj[w][u] = i;
	}
	scanf("%d", &M);
	for (i = 0; i < M; i++) scanf("%d %d", &(s[i]), &(t[i]));
	
	int P[21][51] = {}, prev[51], q[51], head, tail;
	for (i = 0; i < M; i++) {
		for (u = 1; u <= N; u++) prev[u] = -1;
		q[0] = s[i];
		prev[s[i]] = s[i];
		for (head = 0, tail = 1; head < tail; head++) {
			u = q[head];
			for (w = 1; w <= N; w++) {
				if (adj[u][w] == 0) continue;
				else if (w == t[i]) break;
				else if (prev[w] == -1) {
					prev[w] = u;
					q[tail++] = w;
				}
			}
			if (w <= N) break;
		}
		for (; w != u; w = u, u = prev[u]) P[i][adj[u][w]] = 1;
	}
	
	int j, sum[2], white[51];
	long long n, bit[51] = {1}, ans = (long long)1 << N - 1;
	for (i = 1; i <= N; i++) bit[i] = bit[i-1] << 1;
	for (n = 1; n < bit[M]; n++) {
		for (j = 1; j < N; j++) white[j] = 0;
		for (i = 0; i < M; i++) {
			if ((n | bit[i]) == n) {
				for (j = 1; j < N; j++) white[j] |= P[i][j];
			}
		}
		for (j = 1, sum[0] = 0; j < N; j++) sum[0] += white[j];
		for (i = 0, sum[1] = 0; i < M; i++) sum[1] += n / bit[i] % 2;
		if (sum[1] % 2 == 1) ans -= bit[N-1-sum[0]];
		else ans += bit[N-1-sum[0]];
	}

	printf("%lld\n", ans);
	fflush(stdout);
	return 0;
}