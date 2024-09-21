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
#define VERYBIG 2000000000000007LL

#define MOD 1000000007
#define FOD  998244353
typedef uint64_t ull;
typedef  int64_t sll;

#define N_MAX 1000000
#define M_MAX 200000

#ifdef __cplusplus
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <array>

using std::queue;
using std::priority_queue;
using std::stack;
using std::tuple;
using std::set;
using std::map;
using std::vector;
using std::greater;
using std::pair;
using std::string;

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
	sll a;
	sll b;
	sll c;
} hwllc;

typedef struct {
	hwll a;
	hwll b;
} linell;

ull n, m;
ull h, w;
ull k;
ull q;
sll va, vb, vc, vd, ve, vf;
ull ua, ub, uc, ud, ue, uf;
long double vra, vrb, vrc;
double vda, vdb, vdc;
char ch, dh;

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

ull udiff (ull a, ull b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

sll sdiff (sll a, sll b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

int bitcount (ull n) {
	int result = 0;
	while (n) {
		if (n & 1) result++;
		n /= 2;
	}
	return result;
}

// double distance (sll x1, sll y1, sll x2, sll y2) {
// 	double xdist2, ydist2, origindist, dist;

// 	xdist2 = (x1 - x2) * (x1 - x2);
// 	ydist2 = (y1 - y2) * (y1 - y2);
// 	return sqrt(xdist2 + ydist2);
// }

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

int32_t psllcomp (const void *left, const void *right) {
	sll l = *(sll*)left;
	sll r = *(sll*)right;
	if (l < r) {
		return -1;
	}
	if (l > r) {
		return +1;
	}
	return 0;
}

int32_t pcharcomp (const void *left, const void *right) {
	char l = *(char*)left;
	char r = *(char*)right;
	if (l < r) {
		return -1;
	}
	if (l > r) {
		return +1;
	}
	return 0;
}

int32_t pdoublecomp (const void *left, const void *right) {
	double l = *(double*)left;
	double r = *(double*)right;
	if (l < r) {
		return -1;
	}
	if (l > r) {
		return +1;
	}
	return 0;
}

int32_t pstrcomp (const void *left, const void *right) {
	char* l = *(char**)left;
	char* r = *(char**)right;

	return strcmp(l, r);
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

int32_t phwllREVcomp (const void *left, const void *right) {
	hwll l = *(hwll*)left;
	hwll r = *(hwll*)right;
	if (l.b < r.b) {
		return -1;
	}
	if (l.b > r.b) {
		return +1;
	}
	if (l.a < r.a) {
		return -1;
	}
	if (l.a > r.a) {
		return +1;
	}
	return 0;
}

int32_t ptriplecomp (const void *left, const void *right) {
	hwllc l = *(hwllc*)left;
	hwllc r = *(hwllc*)right;

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
	if (l.c < r.c) {
		return -1;
	}
	if (l.c > r.c) {
		return +1;
	}
	return 0;
}

bool isinrange (sll left, sll x, sll right) {
	return (left <= x && x <= right);
}

bool isinrange_soft (sll left, sll x, sll right) {
	return (left <= x && x <= right) || (left >= x && x >= right);
}

sll a[N_MAX];
// sll a[3001][3001];
sll b[N_MAX];
// sll b[3001][3001];
sll c[N_MAX];
// sll d[N_MAX];
// sll e[N_MAX];
char s[N_MAX + 1];
// char s[3010][3010];
char t[N_MAX + 1];
// char t[3010][3010];
// hwll xy[N_MAX];
// sll table[1000][1000];


ull is_lms (bool isS[], ull i) {
	return ((i && !isS[i - 1] && isS[i]) ? 1 : 0);
}

void induced_sort (ull s[], sll sa[], bool isS[], ull lms[], ull n, ull lmscnt, ull ckind) {
	sll i, j;

	for (i = 0; i <= n; i++) {
		sa[i] = -1;
	}

	ull bucket[ckind + 1];
	for (i = 0; i <= ckind; i++) {
		bucket[i] = 0;
	}
	for (i = 0; i <= n; i++) {
		bucket[s[i]]++;
	}
	ull sum = 0;
	for (i = 0; i <= ckind; i++) {
		sum += bucket[i];
		bucket[i] = sum - bucket[i];
	}

	// put LMS
	ull cnt[ckind];
	for (i = 0; i < ckind; i++) {
		cnt[i] = 0;
	}
	for (i = lmscnt - 1; i >= 0; i--) {
		ull ch = s[lms[i]];
		sa[bucket[ch + 1] - 1 - cnt[ch]] = lms[i];
		// printf("LMSput: [%3llu] <- %3llu\n", bucket[ch + 1] - 1 - cnt[ch], lms[i]);
		// fflush(stdout);
		cnt[ch]++;
	}

	// put L-type
	memset(cnt, 0, sizeof(ull) * ckind);
	for (i = 0; i <= n; i++) {
		if (sa[i] < 0) continue;
		if (sa[i] == 0 || isS[sa[i] - 1]) continue;

		ull ch = s[sa[i] - 1];
		sa[bucket[ch] + cnt[ch]] = sa[i] - 1;
		// printf("  Lput: [%3llu] <- %3llu\n", bucket[ch] + cnt[ch], sa[i] - 1);
		// fflush(stdout);
		cnt[ch]++;
	}

	// put S-type
	memset(cnt, 0, sizeof(ull) * ckind);
	for (i = n; i >= 0; i--) {
		if (sa[i] < 0) continue;
		if (sa[i] == 0 || !isS[sa[i] - 1]) continue;

		ull ch = s[sa[i] - 1];
		sa[bucket[ch + 1] - 1 - cnt[ch]] = sa[i] - 1;
		// printf("  Sput: [%3llu] <- %3llu\n", bucket[ch + 1] - 1 - cnt[ch], sa[i] - 1);
		// fflush(stdout);
		cnt[ch]++;
	}
}

void sa_is (ull s[], sll sa[], ull n, ull ckind) {
	sll i;

	bool isS[n + 1];
	isS[n] = true;
	for (i = n - 1; i >= 0; i--) {
		if (s[i] < s[i + 1]) {
			isS[i] = true;
		} else if (s[i] > s[i + 1]) {
			isS[i] = false;
		} else {
			isS[i] = isS[i + 1];
		}
	}

	ull lms[n + 1], lmscnt = 0;
	for (i = 0; i <= n; i++) {
		if (is_lms(isS, i)) {
			lms[lmscnt++] = i;
		}
	}

	induced_sort(s, sa, isS, lms, n, lmscnt, ckind);

	ull lmssort[lmscnt], c = 0;
	for (i = 0; i <= n; i++) {
		ull v = sa[i];
		if (is_lms(isS, v)) {
			lmssort[c++] = v;
		}
	}

	ull nums[n + 1], num = 0;
	nums[lmssort[0]] = 0;
	bool isunique = true;
	for (i = 1; i < lmscnt; i++) {
		ull prev = lmssort[i - 1];
		ull curr = lmssort[i];

		bool issame = true;
		sll j = 0;
		while (true) {
			if (prev + j > n || curr + j > n || s[prev + j] != s[curr + j] || is_lms(isS, prev + j) != is_lms(isS, curr + j)) {
				issame = false;
				break;
			} else if (j && is_lms(isS, prev + j) && is_lms(isS, curr + j)) {
				break;
			}

			j++;
		}

		if (issame) {
			isunique = false;
		} else {
			num++;
		}
		nums[curr] = num;
	}

	if (!isunique) {
		ull densenums[lmscnt];
		for (i = 0; i < lmscnt; i++) {
			densenums[i] = nums[lms[i]];
		}
		sa_is(densenums, sa, lmscnt - 1, num + 1);
		for (i = 0; i < lmscnt; i++) {
			lmssort[i] = lms[sa[i]];
		}
	}

	induced_sort(s, sa, isS, lmssort, n, lmscnt, ckind);
}

bool isok (ull x, ull jump) {
	ull remain = k;
	ull i = 0;
	while (remain) {
		if (c[i] <= c[x]) {
			i += jump;
		} else {
			i += (jump - 1);
		}
		if (i >= n) return true;

		remain--;
	}
	return false;
}

ull solve () {
	sll i, j, ki, li;
	ull result = 0;
	// sll result = 0;
	double dresult = 0;
	// ull maybe = 0;
	sll maybe = 0;
	// ull sum = 0;
	sll sum = 0;
	sll item;
	ull *dpcell;

	n = strlen(s);

	// for (i = 0; i < n; i++) {
	// 	b[i] = s[i];
	// }

	// sa_is(b, a, n, 256);

	// for (i = 0; i <= n; i++) {
	// 	printf("%5lld: %5lld %s$\n", i, a[i], s + a[i]);
	// }

	k++;
	ull maxd = (n - 1) / k + 1;

	for (i = 0; i < n; i++) {
		b[i] = s[i] - '0';
	}

	sa_is(b, a, n, 10);

	for (i = 0; i <= n; i++) {
		c[a[i]] = i;
	}
	j = 0;
	for (i = 0; i <= n; i++) {
		if (a[i] + maxd <= n) {
			a[j++] = a[i];
		}
	}

	sll ok = j, ng = -1;
	while (ng + 1 < ok) {
		sll med = (ok + ng) / 2;
		if (isok(a[med], maxd)) {
			ok = med;
		} else {
			ng = med;
		}
	}

	for (i = 0; i < maxd; i++) {
		putchar(s[a[ok] + i]);
	}
	puts("");

	// printf("%lld\n", result);
	// printf("%.15lf\n", dresult);
	// puts(s);

	return 0;

	success:
	// puts("YES");
	puts("Yes");
	// printf("%llu\n", result);
	// puts("0");
	// puts("Yay!");
	return 0;

	fail:
	// puts("NO");
	puts("No");
	// puts("0");
	// puts("-1");
	// puts("-1 -1 -1");
	// puts(":(");
	return 1;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	// scanf("%llu%llu", &n, &m);
	scanf("%llu", &k, &n, &m);
	// scanf("%llu%llu", &h, &w);
	// scanf("%lld", &va, &vb, &vc, &vd);
	// scanf("%llu%llu", &ua, &ub, &uc, &ud);
	// scanf("%llu", &q);
	scanf("%s", s);
	// scanf("%s", t);
	// for (i = 0; i < n; i++) {
	// 	// scanf("%lld%lld", &xy[i].a, &xy[i].b);
	// 	scanf("%lld", &a[i]);
	// 	// scanf("%lld", &b[i]);
	// 	// scanf("%lld", &c[i]);
	// 	// scanf("%lld", &d[i]);
	// 	// a[i]--;
	// 	// b[i]--;
	// 	// c[i]--;
	// }
	// scanf("%llu", &m, &k);
	// scanf("%llu", &q);
	// for (i = 0; i < n; i++) {
	// 	scanf("%lld", &b[i]);
	// }

	// for (i = 0; i < n; i++) {
	// 	for (j = 0; j < n; j++) {
	// 		scanf("%llu", &table[i][j]);
	// 	}
	// }
	// for (i = 0; i < h; i++) {
	// 	scanf("%s", &s[i]);
	// }

	solve();

	return 0;
}
