#include <stdio.h>
int main (){
  int i,a[200002],t,n;
  scanf ("%d%d",&n,&t);
  for (i=0;i<n;i++){
  scanf ("%d",&a[i]);
  }
  for (i=0;i<n-1;i++){
  if (a[i+1]-a[i]>t){
  sum=sum+t;
  }
    else{
    sum=sum+a[i+1]-a[i];
    }
  }
  printf ("%d",sum+a[n-1]);
return 0;
}