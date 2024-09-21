#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int limit,N,M,X;
int secE[100],secS[100];
int sat[101][1001];
int main(){
	int i,j,k,ans;
	for(;scanf("%d%d%d%d",&limit,&N,&M,&X),limit;){
		int e,s;
		memset(sat,0,sizeof(sat));
		for(i=0;i<N;i++){
			scanf("%*s%d%d",&e,&s);
			for(k=2;k--;){
				for(j=limit+1;j--;){
					if(j+e<=limit)
						sat[k+1][j+e]=max(sat[k+1][j+e],sat[k][j]+s);
				}
			}
		}
		for(j=0;j<=limit;j++){
			sat[0][j]=max(sat[1][j],sat[2][j]);
			sat[1][j]=sat[2][j]=0;
		}
		for(i=0;i<M;i++){
			scanf("%*s%d%d",&e,&s);
			for(k=M;k--;){
				for(j=limit+1;j--;){
					if(j+e<=limit)
						sat[k+1][j+e]=max(sat[k+1][j+e],sat[k][j]+s);
				}
			}
		}
		ans=0;
		for(k=X;k<=M;k++){
			for(j=limit+1;j--;)
				ans=max(ans,sat[k][j]);
		}
		printf("%d\n",ans);
	}
	return 0;
}