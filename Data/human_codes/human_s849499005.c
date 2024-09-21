#include<stdio.h>
int ta[100010],nt[200010],to[200010];
int u[100010];
int f(int s,int n){
  int i;
  u[s]=1;
  for(i=ta[s];i+1;i=nt[i]){
    if(u[to[i]])continue;
    if(f(to[i],n+1)){
      printf(" %d",s);
      return 1;
    }
  }
  printf("%d\n%d",n,s);
  return 1;
}
int main(){
  int n,m,a,b,i;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)ta[i+1]=-1;
  for(i=0;i<m;i++){
    scanf("%d %d",&a,&b);
    nt[i  ]=ta[to[i+m]=a];
    nt[i+m]=ta[to[i  ]=b];
    ta[b]=i+m;
    ta[a]=i;
  }
  f(1,1);
  printf("\n");
  return 0;
}
  
