#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int i,j;
  int n;
  long long int m = 1;
  long long int x;
  int y = 0;
  int l=0;

  scanf("%d",&n);

  for(i=1; i<=n; i++){
    m = m * i;
  }

  for(i=1; i<=m; i++){
    if(m%i == 0){
      x = m;
      l = 0;
    }
    for(j=1; j<=x; j++){
      if(x%j == 0){
        l++;
      }
    }
    if(l==75){
      y++;
    }
  }
  printf("%d\n",y);

  return 0;
}
