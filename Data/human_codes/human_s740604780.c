#include <stdio.h>
#include <string.h>
#define N 1000
int main(){
  char T[N],P[N];
  int i,j,n,t,p;
  scanf("%s",T);
  scanf("%s",P);
  t=strlen(T);
  p=strlen(P);
  for(i=0;i<=t-p;i++){
    n=0;
    for(j=0;j<p;j++){
      if(T[i+j]!=P[j])
	n++;
    }
    if(n==0&&t>=p)
      printf("%d\n",i);
  }
  return 0;
}