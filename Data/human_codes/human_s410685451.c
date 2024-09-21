#include<stdio.h>
int main(){
	while(1){
		int num=0,T,D,L,x[100000],t[100000]={0};
		scanf("%d %d %d",&T,&D,&L);
		if(T==0&&D==0&&L==0)	break;
		for(int i=1;i<=T;i++){
			scanf("%d",&x[i]);
		}
		for(int i=1;i<=T-1;i++){
			if(x[i]>=L){
				for(int a=i-1;a<i-1+D;a++){
					t[a]=1;
				}
			}
		}
		for(int i=0;i<=T-2;i++){
				num=t[i]+num;
		}
		printf("%d\n",num);
	}
	return 0;
}