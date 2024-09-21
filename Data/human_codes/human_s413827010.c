#include<stdio.h>  
#define MAX 100
#define INF 1000000
#define WHITE 0
#define GRAY 1
#define BLACK 2
int n, u;
int M[MAX][MAX];

void MST(){
  int i,min,d[MAX],color[MAX]={WHITE};
  for(i = 0;i < n;i++){
    d[i] = INF;
  }
  d[0] = 0;
  color[0] = GRAY;
  while(1){
    min = INF;
    u = -1;
    for(i = 0;i < n;i++)
      if(min > d[i] && color[i] != BLACK){
	u = i;
	min = d[i];
      }
    if(u == -1){
      break;
    }
    color[u] = BLACK;
    for(i = 0;i < n;i++)
      if(color[i] != BLACK && M[u][i] != INF){
	if(d[i] > d[u] + M[u][i]){
	  d[i] = d[u] + M[u][i];
	  color[i] = GRAY;
	}
      }
  }
  for(i = 0;i < n;i++){
    if(d[i] == INF){
      printf("%d -1\n",i);
    }
    else{
      printf("%d %d\n",i,d[i]);
    }
  }
}
 
int main(){
  int i,j,k,v,c;
  scanf("%d",&n);
  for(i = 0 ;i < n;i++){
    for(j = 0;j < n;j++){
      M[i][j] = INF;
    }
  }
  for(i = 0;i < n;i++){
    scanf("%d %d",&u,&k);
    for(j = 0;j < k;j++){
      scanf("%d %d",&v,&c);
      M[u][v] = c;
    }
  }
  MST();
  return 0;
}
  