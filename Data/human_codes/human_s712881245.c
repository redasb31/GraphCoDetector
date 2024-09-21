#include<stdio.h>
int n,m,i,j,r,t,a,b,o=0,ta[100010],to[200010],nt[200010];
int g[100010],c[100010],q[100010];
int main(){
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)ta[i+1]=-1;
  for(i=0;i<m;i++){
    scanf("%d %d",&a,&b);
    nt[i  ]=ta[to[i+m]=a];
    nt[i+m]=ta[to[i  ]=b];
    ta[b]=i+m;
    ta[a]=i;
    g[a]++;
    g[b]++;
  }
  c[q[t=0]=1]=1;
  for(r=1;r-t;t++){
    for(i=ta[q[t]];i+1;i=nt[i]){
      if(c[to[i]]==c[q[t]])goto END;
      if(c[to[i]])continue;
      c[to[i]]=3-c[q[t]];
      q[r++]=to[i];
    }
  }
  for(i=1;i<=n;i++){
    if(g[i]%2==0)continue;
    if(o&&o-c[i])goto END;
    o=c[i];
  }
  if(o==0)o=1;//printf("o %d\n",o);
  //for(i=0;i<n;i++)printf("%d ",c[i+1]);printf("\n");
  for(i=1;i<=n;i++){
    if(c[i]==o)continue;
    for(j=ta[i];j+1;j=nt[j])printf("%d %d\n",i,to[j]);
  }
  return 0;
 END:;
  printf("-1\n");
  return 0;
}
      
  
