#include<stdio.h>
int main(){
  int n,m,k,i,j,d[100010],t,a,b;
  scanf("%d",&m);
  while(m--){
    scanf("%d %d %d",&n,&k,&b);
    for(i=0;i<n-1;i++){
      scanf("%d",&a);
      t=a-b;
      for(j=i;j&&d[j-1]>t;j--)d[j]=d[j-1];
      d[j]=t;
      b=a;
    }
    for(i=t=0;i<n-k;i++)t+=d[i];
    printf("%d\n",t);
  }
  return 0;
}
    