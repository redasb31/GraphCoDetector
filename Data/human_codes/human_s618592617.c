#include <stdio.h>
#define MIN(x,y) (x)>(y)?(y):(x)

int main(void) {
	int n,m,i,x;
	int cnt[100000] = {0},modcnt[10000] = {0};
	
	scanf("%d %d",&n,&m);

	for (i = 0;i < n;i++) {
		scanf("%d",&x);
		cnt[x-1]++;
		modcnt[x%m]++;
	}
	
	int ans = 0;
	int canpair = 0;
	for (i = 1;i <= (m-1)/2;i++) {
		canpair = MIN(modcnt[i],modcnt[m-i]);
		ans += canpair;
		modcnt[i] -= canpair;
		modcnt[m-i] -= canpair;
	}

	if (!(m%2)) {
		canpair = modcnt[m/2] / 2;
		ans += canpair;
		modcnt[m/2] -= canpair * 2;
	}
	ans += (modcnt[0]) / 2;
	modcnt[0] -= modcnt[0] /= 2;
	
	int tmp = 0;
	for (i = 1;i < m;i++) {
		if (modcnt[i] >= 2) {
			for (tmp = i;tmp <= n;tmp+=m) {
				if (cnt[tmp-1] >= 2) {
					canpair = MIN(cnt[tmp-1] / 2,modcnt[i] / 2);
					ans += canpair;
					cnt[tmp-1] -= canpair * 2;
					modcnt[i] -= canpair * 2;
				}
				if (modcnt[i] < 2) {
					break;
				}
			}
		}
	}
	
	printf("%d\n",ans);

	return 0;
}
