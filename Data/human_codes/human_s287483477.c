#include<stdio.h>
int main(void){
	int n,m,i,j,sum=0,a,b,c,sg,lg,min,anssum=0,ansb=0,past=0;
	int cost[501][501]={0},flag[501][501]={0},used[501][501]={0},gu[501],con[501];
	scanf("%d %d",&n,&m);
	i=m;
	while(i!=0){
		scanf("%d %d %d",&a,&b,&c);
		cost[a][b]=c;
		flag[a][b]=1;
		i--;
	}
	for(i=1;i<=n;i++){
		gu[i]=i;
		con[i]=0;
	}
	while(1){
		past=min;
		min=1000000;
		for(a=1;a<=n;a++){
			for(b=a+1;b<=n;b++){
				if(flag[a][b]==1&&min>cost[a][b]&&gu[a]!=gu[b]){
					min=cost[a][b];
				}
			}
		}
		for(a=1;a<=n;a++){
			for(b=a+1;b<=n;b++){
				if(min==cost[a][b]&&gu[a]!=gu[b]){
					sum+=cost[a][b];
					used[a][b]=1;
					con[a]++;
					con[b]++;
					if(gu[a]>gu[b]){
						sg=gu[b];
						lg=gu[a];
					}
					else{
						sg=gu[a];
						lg=gu[b];
					}
					for(c=1;c<=n;c++){
						if(gu[c]==lg){
							gu[c]=sg;
						}
					}
				}
			}
		}
		if(min==1000000){
			break;
		}
	}
	int tsum,sw;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(used[i][j]==0||cost[i][j]>past){
				continue;
			}
			tsum=0;
			for(a=1;a<=n;a++){
				gu[a]=a;
			}
			while(1){
				min=1000000;
				for(a=1;a<=n;a++){
					for(b=a+1;b<=n;b++){
						if(flag[a][b]==1&&min>cost[a][b]&&gu[a]!=gu[b]){
							if(a!=i||b!=j){
								min=cost[a][b];
							}
						}
					}
				}
				for(a=1;a<=n;a++){
					for(b=a+1;b<=n;b++){
						if(min==cost[a][b]&&gu[a]!=gu[b]){
							if(a!=i||b!=j){
								tsum+=cost[a][b];
								if(gu[a]>gu[b]){
									sg=gu[b];
									lg=gu[a];
								}
								else{
									sg=gu[a];
									lg=gu[b];
								}
								for(c=1;c<=n;c++){
									if(gu[c]==lg){
										gu[c]=sg;
									}
								}
							}
						}
					}
				}
				if(min==1000000){
					break;
				}
			}
			sw=0;
			for(a=1;a<=n;a++){
				if(gu[a]!=1){
					sw++;
					break;
				}
			}
			if(tsum>sum||sw!=0){
				anssum+=cost[i][j];
				ansb++;
			}
		}
	}
	printf("%d %d\n",ansb,anssum);
	return 0;
}