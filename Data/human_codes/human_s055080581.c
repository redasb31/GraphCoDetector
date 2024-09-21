#include<stdio.h>
#define N 1000

int main(void){
  int i,num,j;
  int a[N],b[N],n[N];
  int pre,s;
  double c;

  for(i=0;
      scanf("%d%d%d",&a[i],&b[i],&n[i])==3;
      i++){}
  num=i;
  for(i=0;i<num;i++){
    c=(double)a[i]/(double)b[i];
    s=0;
    for(j=0;j<n[i];j++){
      c-=(int)c;
      c*=10.0;
      s+=(int)c;
    }
    printf("%d\n",s);
  }
  return 0;
}