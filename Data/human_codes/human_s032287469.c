#include<stdio.h>
#define LARGE 2000
#define INF 1000000000
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int V,e;

typedef struct edge{
	int from;
	int to;
	int cost;
}edge;

int BellmanFord(edge E[],int C[]){
	int i,j;
	int cnt=0;
	for(j=0;j<V-1;j++){
	
		for(i=0;i<e;i++){
			if(C[E[i].from]!=INF && C[E[i].to] > C[E[i].from]+E[i].cost){
				C[E[i].to]=C[E[i].from]+E[i].cost;
				cnt++;
			}
		}
		
	}
	
	if(cnt>e){
		printf("NEGATIVE CYCLE\n");
		return 0;
	}
	
	return 1;
}
	
	

int main(){
	int start;
	int s,t,d;
	int i,j,flg;
	int C[LARGE];
	edge E[LARGE];
	int ans[100][100];
	
	scanf("%d %d",&V,&e);
	
	for(i=0;i<e;i++){
		scanf("%d %d %d",&s,&t,&d);
		E[i].from=s;
		E[i].to=t;
		E[i].cost=d;
	}
	
	for(int j=0;j<V;j++){
	
		for(i=0;i<V;i++){
			C[i]=INF;
		}
		start=j;
		C[start]=0;
	
		flg=BellmanFord(E,C);
	
		if(flg==0)return 0;
	
		for(i=0;i<V;i++){
			ans[j][i]=C[i];
		}
	}
	
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			if(j==V-1){
				if(ans[i][j]==INF)printf("INF\n");
				else printf("%d\n",ans[i][j]);
			}
			else {
				if(ans[i][j]==INF)printf("INF ");
				else printf("%d ",ans[i][j]);
			}
		}
	}
	
	return 0;
	
}
