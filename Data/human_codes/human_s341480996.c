#include <stdio.h>

int main(void){
	while(1){
		int n, i, ans=0; 
		int count=0;//１個以下しかない商品の種類の数
		int a[10000];
		
		scanf(" %d", &n);
		if(n==0) break;
		for(i=0; i<n; i++) {
			scanf(" %d", &a[i]);
			if(a[i] <=1) count++;
		}
		
		if(count == n) {
			printf("NA\n");
			continue;
		}
		
		for(i=0; i<n; i++) { //１個以下のものを全て出し尽くす
			if(a[i] <=1) {
				ans += a[i];
				a[i] = 0;
			}
		}
		
		ans += n-count+1;

		printf("%d\n", ans);0
	}

	return 0;
}