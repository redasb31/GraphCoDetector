#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a)>(b)?(a):(b))

typedef struct directedGraph{
  int *vertex;
  int *next;
  int *start;
  int v,e;
  int pointer;
} graph;

graph* newGraph(const int v,const int e){
  graph *g=(graph *)malloc(sizeof(graph));
  g->vertex=(int *)calloc(e,sizeof(int));
  g->next=(int *)calloc(e,sizeof(int));
  g->start=(int *)calloc(v,sizeof(int));
  for(int i=0;i<v;i++) g->start[i]=-1;
  g->v=v;
  g->e=e;
  g->pointer=0;
  return g;
}

void freeGraph(graph *g){
  free(g->vertex);
  free(g->next);
  free(g->start);
  free(g);
  return;
}

void addEdge(graph *g,const int from,const int to){
  const int p=g->pointer;
  g->vertex[p]=to;
  g->next[p]=g->start[from];
  g->start[from]=p;
  g->pointer++;
  return;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  graph *g=newGraph(n,m);
  while(m--){
    int x,y;
    scanf("%d%d",&x,&y);
    x--;y--;
    addEdge(g,x,y);
  }
  int *dp=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) dp[i]=-1;
  int ans=0;
  int *stack=(int *)calloc(2*n,sizeof(int));
  for(i=0;i<n;i++){
    if(dp[i]>=0) continue;
    int top=0;
    stack[top++]=i;
    while(top>0){
      int v=stack[--top];
      if(v>=n){
	v-=n;
	int max=-1;
	for(int p=g->start[v];p!=-1;p=g->next[p]) max=MAX(max,dp[g->vertex[p]]);
	dp[v]=max+1;
      } else {
	stack[top++]=v+n;
	for(int p=g->start[v];p!=-1;p=g->next[p]){
	  int u=g->vertex[p];
	  if(dp[u]<0){
	    stack[top++]=u;
	  }
	}
      }
    }
    ans=MAX(ans,dp[i]);
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
}
