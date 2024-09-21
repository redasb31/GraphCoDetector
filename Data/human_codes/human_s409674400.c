#include <stdio.h>
#define N 1000
int main(){
  int i, n, a[N], j, v, t;
  scanf("%d",&n);
  for(i=0 ; i<n ; i++){
    scanf("%d",&a[i]);
  }
  for(i=0 ; i<n ; i++){
    v=a[i];
    j=i-1;
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
      a[j+1]=v;
    }

    for(t=0 ; t<n ; t++){
      if(t==n-1) printf("%d",a[t]);
      else printf("%d ",a[t]);   
    }
    printf("\n");
  }
return 0;
}