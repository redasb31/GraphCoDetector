#include<stdio.h>
int main(){
  int n,m,s,i,j,a[20010],b[20010],r[20010];
  while(scanf("%d %d",&n,&m),n||m){
    int t[20010]={-2000000000};
    int v[20010]={0,1};
    for(i=1;i<=m;i++){
      r[i]=i;
      scanf("%d %d %d",&t[i],&a[i],&b[i]);
      for(j=i;t[r[j-1]]>t[r[j]];j--)r[j]=r[j-1];
      r[j]=i;
    }
    for(i=1;i<=m;i++)v[b[r[i]]]|=v[a[r[i]]];
    for(i=s=0;i<=n;i++)s+=v[i];
    printf("%d\n",s);
  }
  return 0;
}