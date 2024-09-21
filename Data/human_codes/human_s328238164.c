/*
cat <<EOF >mistaken-paste
*/

#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define BIG 2000000007
#define VERYBIG 200000000000007LL

#define MOD 1000000007
typedef uint64_t ull;
typedef  int64_t sll;

#define N_MAX 200000
#define M_MAX 200000

#ifdef __cplusplus
#include <queue>
#include <stack>
// #include <tuple>
#include <set>
#include <map>

// using namespace std; // HELL
using std::queue;
using std::priority_queue;
using std::stack;
// using std::tuple;
using std::set;
using std::map;
using std::vector;
using std::greater;
using std::pair;

#endif

typedef struct {
	int32_t a;
	int32_t b;
} hw;

typedef struct {
	sll a;
	sll b;
} hwll;

typedef struct {
	hwll a;
	hwll b;
} linell;


typedef struct {
	ull s;
	ull t;
	int32_t c;
} struct_a;

typedef struct {
	int32_t from;
	int32_t to;
	sll cost;
} struct_b;



const hw vector8[8] = {
	{-1, -1},
	{-1,  0},
	{-1, +1},
	{ 0, -1},
	{ 0, +1},
	{+1, -1},
	{+1,  0},
	{+1, +1}
};

ull n, m;
ull h, w;
ull k;
ull q;
ull vua, vub, vuc, vud, vue, vuf;
sll vsa, vsb, vsc, vsd, vse, vsf;
long double vra, vrb, vrc;
double vda, vdb, vdc;
size_t slen;
size_t tlen;
char ch, dh;

void swap_adj (ull *a, ull *b) {
	if (*a != *b) {
		ull tmp = *b;
		*b = *a;
		*a = tmp;
	}
	return;
}

int32_t digits (ull x) {
	int32_t i = 1;
	while (x >= 10) {
		x /= 10;
		i++;
	}
	return i;
}

ull umin (ull x, ull y) {
	return (x < y) ? x : y;
}

ull umax (ull x, ull y) {
	return (x > y) ? x : y;
}

sll smin (sll x, sll y) {
	return (x < y) ? x : y;
}

sll smax (sll x, sll y) {
	return (x > y) ? x : y;
}

ull gcd (ull x, ull y) {
	if (x < y) {
		return gcd(y, x);
	} else if (y == 0) {
		return x;
	} else {
		return gcd(y, x % y);
	}
}

ull bitpow (ull a, ull x, ull modulo) {
	ull result = 1;
	while (x) {
		if (x & 1) {
			result *= a;
			result %= modulo;
		}
		x /= 2;
		a = (a * a) % modulo;
	}
	return result;
}

ull divide (ull a, ull b, ull modulo) {
	return (a * bitpow(b, modulo - 2, modulo)) % modulo;
}

ull ullabs (ull a, ull b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

sll sllabs (sll a, sll b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

sll nibutanlobo (bool (*func)(sll arg), sll ok, sll ng) {
	while (sllabs(ok, ng) > 1) {
		sll med = (ok + ng) / 2;
		if (func(med)) {
			ok = med;
		} else {
			ng = med;
		}

		// printf("debug: [%lld %lld)\n", ok, ng);
	}

	if (!func(ok)) return ok * 2 - ng;
	return ok;
}

void printUquotient (ull left, ull right) {
	const int32_t digits = 20;

	printf("%llu.", left / right);
	left %= right;
	for (int32_t i = 0; i < digits; i++) {
		left *= 10;
		printf("%1d", left / right);
		left %= right;
	}
	puts("");

	return;
}

void printSquotient (sll left, sll right) {
	if (left * right < 0) putchar('-');
	printUquotient(sllabs(left, 0), sllabs(right, 0));

	return;
}

int bitcount (ull n) {
	int result = 0;
	while (n) {
		if (n & 1) result++;
		n /= 2;
	}
	return result;
}

// #ifdef __cplusplus

// typedef struct {
// 	int32_t to;
// 	sll cost;
// } edge;
// typedef pair<sll, int32_t> P;

// std::vector<edge> g[N_MAX];
// void dijk_init (ull n, struct_b arr[]) {
// 	edge x;
// 	for (int32_t i = 0; i < n; i++) {
// 		x.to = arr[i].to;
// 		x.cost = arr[i].cost;
// 		g[arr[i].from].push_back(x);
// 	}
// }

// bool dijkstra (int s, sll distance[]) {
// 	priority_queue<P, std::vector<P>, greater<P> > que; // (最短距離, 頂点番号)
// 	que.push(P(distance[s], s));

// 	bool ischanged = false;
// 	while (!que.empty()) {
// 		P p = que.top();
// 		que.pop();

// 		sll v = p.second;
// 		if (distance[v] < p.first) continue;

// 		int32_t maxsize = g[v].size();
// 		for (int32_t i = 0; i < maxsize; i++) {
// 			edge e = g[v][i];
// 			if (distance[e.to] > distance[v] + e.cost) {
// 				distance[e.to] = distance[v] + e.cost;
// 				ischanged = true;
// 				que.push(P(distance[e.to], e.to));
// 			}
// 		}
// 	}

// 	return ischanged;
// }

// #endif

sll dist[N_MAX];
struct_b path[M_MAX * 2];

ull a[N_MAX];
// ull a[M_MAX];
// sll a[N_MAX];
// ull a[N_MAX][N_MAX];
// ull a[M_MAX][M_MAX];
// sll a[N_MAX][N_MAX];
// ull b[N_MAX];
// ull b[M_MAX];
// sll b[N_MAX];
// ull c[N_MAX];
// sll c[M_MAX];
// char c[N_MAX];
char s[N_MAX + 1];
// char s[N_MAX + 1][N_MAX + 1];
// char s[N_MAX + 1][M_MAX + 1];
// char t[N_MAX + 1];

ull alphabets[26];
// ull blphabets[26];
// char alphabets[26];

// ull dp[N_MAX + 1];
// sll dp[N_MAX + 1];
// ull dp[N_MAX + 1][N_MAX + 1];
// sll dp[N_MAX + 1][N_MAX + 1];
// bool dp[N_MAX + 1];
// bool dp[N_MAX + 1][N_MAX + 1];
hwll arr[N_MAX + 1];
// hwll arr[M_MAX];
// hwll brr[M_MAX];

// sll dp[N_MAX + 1];
// ull color[N_MAX];
// set<sll> children[N_MAX];
// set<sll> leaf[N_MAX];

bool islooked[N_MAX];
bool isinloop[N_MAX];
ull perfectloops[N_MAX + 1];
ull reva[N_MAX];
ull back[N_MAX];
ull backloop[N_MAX];

ull frac[N_MAX + 1];

double distance (sll x1, sll y1, sll x2, sll y2) {
	double xdist2, ydist2, origindist, dist;

	xdist2 = (x1 - x2) * (x1 - x2);
	ydist2 = (y1 - y2) * (y1 - y2);
	return sqrt(xdist2 + ydist2);
}

int32_t pullcomp (const void *left, const void *right) {
	ull l = *(ull*)left;
	ull r = *(ull*)right;
	if (l < r) {
		return -1;
	}
	if (l > r) {
		return +1;
	}
	return 0;
}

int32_t phwllABcomp (const void *left, const void *right) {
	hwll l = *(hwll*)left;
	hwll r = *(hwll*)right;
	if (l.a < r.a) {
		return -1;
	}
	if (l.a > r.a) {
		return +1;
	}
	if (l.b < r.b) {
		return -1;
	}
	if (l.b > r.b) {
		return +1;
	}
	return 0;
}

ull rank[N_MAX];
ull parent[N_MAX];

void uf_init (ull n) {
	for (sll i = 0; i < n; i++) {
		rank[i] = 0;
		parent[i] = i;
	}
}
ull uf_find (ull x) {
	if (parent[x] == x) return x;
	return parent[x] = uf_find(parent[x]);
}
bool uf_same (ull a, ull b) {
	return (uf_find(a) == uf_find(b));
}
bool uf_union (ull a, ull b) {
	ull ap = uf_find(a);
	ull bp = uf_find(b);
	if (ap == bp) return false;

	if (rank[ap] > rank[bp]) {
		parent[bp] = ap;
	} else {
		parent[ap] = bp;
		if (rank[ap] == rank[bp]) rank[bp]++;
	}
	return true;
}

// typedef pair<ull, ull> P;
// vector<P> g[N_MAX];

// set<ull> rootpath[N_MAX];
// P directp[N_MAX];

// vector<P> doubling[N_MAX];

// P reversep (ull v, ull retn) {

// 	P result = {v, 0};
// 	sll i;

// 	while (retn) {
// 		for (i = doubling[v].size() - 1; i >= 0; i--) {
// 			if ((1 << i) & retn) {
// 				break;
// 			}
// 		}
// 		result.second = umax(result.second, doubling[v][i].second);
// 		v = result.first = doubling[v][i].first;
// 		retn -= (1 << i);
// 	}

// 	return result;
// }

ull solve () {
	sll i, j, ki;
	// ull result = 0;
	sll result = 0;
	// double result = 0;
	ull maybe = 0;
	// sll maybe = 0;
	// ull sum = 0;
	sll sum = 0;
	ull item;
	ull *dpcell;

	uf_init(n);
	for (i = 0; i < n; i++) {
		uf_union(i, a[i]);
	}

	for (i = 0; i < n; i++) {
		arr[i].a = uf_find(i);
		arr[i].b = i;
	}
	qsort(arr, n, sizeof(hwll), phwllABcomp);

	for (i = 0; i < n; i++) {
		reva[a[i]]++;
	}

	frac[0] = 1;
	for (i = 1; i <= n; i++) {
		frac[i] = (frac[i - 1] * i) % MOD;
	}

	ull pow2 = 0;

	sll sectbegin = 0;
	while (sectbegin < n) {
		sll sectend = sectbegin;
		while (sectend < n && arr[sectend].a == arr[sectbegin].a) sectend++;
		sll factors = sectend - sectbegin;

		sll loopelem = arr[sectbegin].b;
		while (!islooked[loopelem]) {
			islooked[loopelem] = true;
			loopelem = a[loopelem];
		}

		sll looplen = 0;
		i = loopelem;
		while (!isinloop[i]) {
			isinloop[i] = true;
			looplen++;
			i = a[i];
		}

		if (factors == looplen) {
			perfectloops[factors]++;
		} else if (factors > looplen * 2) {
			goto fail;
		} else {
			for (i = sectbegin; i < sectend; i++) {
				sll x = arr[i].b;
				if (isinloop[x]) {
					if (reva[x] > 2) goto fail;
					backloop[a[x]] = x;
				} else {
					if (reva[x] > 1) goto fail;
					back[a[x]] = x;
				}
			}
			// for (i = sectbegin; i < sectend; i++) {
			// 	sll x = arr[i].b;
			// 	if (isinloop[x]) {
			// 		printf("reva[%lld]: %llu (<=2)\n", x, reva[x]);
			// 		// if (reva[x] > 2) goto fail;

			// 		// if (reva[x] == 1 && reva[a[x]] == 2) {
			// 		// 	pow2++;
			// 		// }

			// 		ull backlen = 0;
			// 		j = x;
			// 		while (reva[j] == (isinloop[j] ? 2 : 1)) {
			// 			j = back[j];
			// 			backlen++;
			// 		}
			// 	} else {
			// 		printf("reva[%lld]: %llu (<=0)\n", x, reva[x]);
			// 		// if (reva[x] > 1) goto fail;
			// 	}
			// }
			sll x = loopelem;
			i = 0;
			while (i < looplen) {
				ull backlen = 0;
				j = x;
				while (reva[j] == (isinloop[j] ? 2 : 1)) {
					j = back[j];
					backlen++;
				}

				if (!backlen) {
					i++;
					x = backloop[x];
					continue;
				}

				for (j = 0; j < backlen; j++) {
					x = backloop[x];
					if (j == backlen - 1) break;

					if (reva[x] > 1) goto fail;
				}

				if (reva[x] > 1) {
					i += backlen;
				} else {
					pow2++;

					i += (backlen + 1);
				}
			}
		}

		sectbegin = sectend;
	}

	result = 1;
	for (i = 1; i <= n; i++) {
		if (!perfectloops[i]) continue;

		sll X = ((i == 1) ? 1 : (i % 2) + 1);
		sll p = perfectloops[i];
		// sigma_{i=0}^{p/2} X^(p-2i) * p!/(p-2i)! / (2^i * i!) * len^i

		sum = 0;
		for (j = 0; j <= p / 2; j++) {
			sum += divide(
				bitpow(X, p - j * 2, MOD) * (frac[p] * bitpow(i, j, MOD) % MOD) % MOD,
				((frac[p - j * 2] * frac[j] % MOD) * bitpow(2, j, MOD) % MOD),
				MOD);
			sum %= MOD;

			// printf("[%llu] %lld: %llu\n", i, j, sum);
			// printf("%llu * %llu * %llu / %llu / %llu / %llu\n", bitpow(X, p - j * 2, MOD), frac[p], bitpow(i, j, MOD), frac[p - j * 2], frac[j], bitpow(2, j, MOD));
		}

		result = (result * sum) % MOD;
	}
	result = (result * bitpow(2, pow2, MOD)) % MOD;

	printf("%llu\n", result);
	// printf("%.12lf\n", (double)result);
	// puts(s);

	return 0;

	success:
	// puts("YES");
	// puts("Yes");
	// printf("%llu\n", result);
	// puts("0");
	puts("First");
	return 0;

	fail:
	// puts("NO");
	// puts("No");
	puts("0");
	// puts("-1");
	// puts("-1 -1 -1");
	// puts("Second");
	return 1;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	// scanf("%lf", &vda, &vdb);
	// scanf("%lld%lld%lld%lld", &vsa, &vsb, &vsc, &vsd);
	// scanf("%llu%llu", &vua, &vub, &vuc, &vud);
	// scanf("%llu%llu", &h, &w);
	// scanf("%*llu%*llu");
	scanf("%llu", &n, &m);
	// scanf("%llu", &k, &n);
	// scanf("%llu%llu", &vua, &vub, &vuc, &vud, &vue, &vuf);
	// scanf("%lld%lld", &vsa, &vsb, &vsc);
	// scanf("%s", s);
	// scanf("%s", t);
	// scanf("%llu", &m);
	// scanf("%llu", &q);
	for (i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		a[i]--;
	}
	// for (i = 0; i < h; i++) {
	// 	for (j = 0; j < w; j++) {
	// 		scanf("%llu", &a[i][j]);
	// 	}
	// }

	// scanf("%llu", &k);
	// scanf("%llu", &q);
	solve();

	return 0;
}
