#include<stdio.h>

int main(){
	int n,i,j,k=1,cnt,d[10][10];

	while(scanf("%d",&n),n){
		cnt=1;
		for(i=0;i<n*2;i++){
			if(i%2){
				for(j=0;j<n;j++){
if(!(0<=i-j&&i-j<n))continue;
					d[j][i-j]=cnt++;
				}
			}else{
				for(j=n-1;j>=0;j++){
if(!(0<=i-j&&i-j<n))continue;
					d[j][i-j]=cnt++;
				}
			}
		}
		printf("Case %d:\n",k++);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%3d",d[i][j]);
			}
			puts("");
		}
	}
	return 0;
}		