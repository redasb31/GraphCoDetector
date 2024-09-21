#include <stdio.h>
int main(){
	short i = 0;
	int n,m,x;
	scanf("%d%d%d",&n,&m,&x);
	int nums[m];
	for(i = 0;i < m; ++i) {
		scanf("%d",&nums[i]);
	}
	i = 0;
	do{
		if (nums[i] > x){
			if (i < m - i){
				printf("%d",i);
			}
			else{
				printf("%d",m - i);
			}

		}
		i += 1;
	}while(nums[i - 1] < x && i  < m);
	if(i  > m) printf("0");
}