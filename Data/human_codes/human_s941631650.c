#include <stdio.h>

int main(void){
	int n,y,i,j,comp;

	scanf("%d %d",&n,&y);

	y/=1000;

	int d[n];

	for(i=0;i<=n && i*10<=y;i++){
		for(j=0;i+j<=n && i*10+j*5<=y;j++){
			if(i*10+j*5+(n-(i+j))==y){
				printf("%d %d %d",i,j,n-(i+j));
				return 0;
			}
		}
	}
  
    printf("-1 -1 -1");

	return 0;

}