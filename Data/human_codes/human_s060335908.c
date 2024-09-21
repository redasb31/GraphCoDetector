#include<stdio.h>

int main()
{
	int i, j, n, m, k, a, ans = 0; 
	
	scanf("%d %d", &n, &m);
	
	int cnt[m];
	for(i = 0; i < m; i++){
		cnt[i] = 0;
	}
	
	for(i = 0; i < n; i++){
		scanf("%d", &k);
		for(j = 0; j < k; j++){
			scanf("%d", &a);
			cnt[a - 1]++;
		}
	}
	
	for(i = 0; i < m; i++){
		if(cnt[i] == n){
			ans++;
		}
	}
	
	printf("%d", ans);

	return 0;
}