#include <stdio.h>
#include <stdlib.h>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

typedef long long ll;
typedef struct {
	ll indx, height;
} Pair;

int cmp(const Pair *x, const Pair *y);

ll n;
ll is_island[100005];
Pair p[100005];

int main()
{
	ll island_nums;
	ll ans;
	ll i;

	scanf("%lld", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &p[i].height);
		p[i].indx = i;
	}

	qsort(p + 1, n, sizeof(Pair), (int (*)(const void *, const void *))cmp);

	p[0].height = -1;
	p[n + 1].height = -1;
	

	island_nums = 0;
	ans = 0;
	i = 1;
	while (i <= n) {

		do {
			if (p[i].height > 0) {
				ll indx = p[i].indx;
				is_island[indx] = 1;

				if (is_island[indx - 1] && is_island[indx + 1]) {
					island_nums--;
				} else if (!is_island[indx - 1] && !is_island[indx + 1]) {
					island_nums++;
				}
			}

			i++;
		} while(p[i].height == p[i - 1].height);

		ans = max(island_nums, ans);
	}

	printf("%lld\n", ans);

	return 0;
}

int cmp(const Pair *x, const Pair *y)
{
	if (x->height > y->height) {
		return -1;
	} else if (x->height == y->height) {
		return 0;
	} else {
		return 1;
	}
}

