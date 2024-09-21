#include<stdio.h>
int main(){
  int n,i,count=0;
  scanf("%d",&n);
  int a[n+1];
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n;i++){
    while(a[i]%2==0){
      a[i]/=2;
      count++;
    }
  }
  printf("%d\n",count);
  return 0;
}
