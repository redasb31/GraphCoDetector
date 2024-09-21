#include <stdio.h>

int main(){
  int sosu[10000];
  int i, a,j,n, k=2;

  for(i=0;i<10000;i++) sosu[i]=0;

  sosu[0]=2;
  sosu[1]=3;

  for(i=4; ;i++){
    a=0;
    for(j=0;sosu[j] !=0 ;j++){
      if(i%sosu[j]==0){
	a = 1;
	break;
      }
    }
    if(a==0){
      sosu[k]=i;
      k++;
      if(k==10000) break;
    }
  }

  while(1){
    a =0;
    scanf("%d", &n);
    if(n==0) break;
    for(i=0;i<n;i++){
      a += sosu[i];
    }
    printf("%d\n", a);
  }
  return 0;
}