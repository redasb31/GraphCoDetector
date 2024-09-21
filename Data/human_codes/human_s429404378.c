#include<stdio.h>
int n,m,o,d[10],a[20],b[20],c[20];
int f(int t){
  int i,j,k;
  if(t==n){
    for(i=0;i<o;i++){
      k=0;
      for(j=a[i]-1;j<b[i];j++)k+=d[j];
      if(k-c[i])break;
    }
    if(i==o){
      for(i=0;i<n-1;i++)printf("%d ",d[i]);
      printf("%d\n",d[i]);
      return 1;
    }
    return 0;
  }
  for(i=m;i>-1;i--){
    d[t]=i;
    if(f(t+1))return 1;
  }
  return 0;
}
int main(){
  int i;
  scanf("%d %d %d",&n,&m,&o);
  for(i=0;i<o;i++)scanf("%d %d %d",&a[i],&b[i],&c[i]);
  if(f(0)==0)printf("-1\n");
  return 0;
}