#include<stdio.h>
#define INF 1000000000
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int a[100][100];
int d[100][100];
int V,E;

int WarshallFloyd(){
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			for(int k=0;k<V;k++){
				if(d[j][k]!=INF){
					d[j][k]=MIN(d[j][k],d[j][i]+d[i][k]);
					if(j==k && d[j][k]<0){
						printf("NEGATIVE CYCLE\n");
						return 1;
					}
					
				}
			}
		}
	}
	return 0;
}

int main(){
	int s,t,cost;
	int i,j;
	
	scanf("%d %d",&V,&E);
	
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			if(i==j)d[i][j]=0;
			else d[i][j]=INF;
		}
	}
	
	for(i=0;i<E;i++){
		scanf("%d %d %d",&s,&t,&cost);
		d[s][t]=cost;
	}
	
	if(WarshallFloyd())return 0;
	
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			if(j==V-1){
				if(d[i][j]==INF)printf("INF\n");
				else printf("%d\n",d[i][j]);
			}
			else {
				if(d[i][j]==INF)printf("INF ");
				else printf("%d ",d[i][j]);
			}
		}
	}
	
	return 0;
}
