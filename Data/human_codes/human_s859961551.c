#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
  int N, K, **l, i, j, a, b, maxa=0, maxb=0, n;

  scanf("%d %d",&N,&K);
  *l = malloc(sizeof(int *)*N);
  for(i=0;i<N;i++){
    l[i] = malloc(sizeof(int)*2);
    scanf("%d %d",&a, &b);
  
    for(j=0;j<i;j++){
      n = l[j][0]|a;
      if(K>n){l[j][0]=n; l[j][1]+=b;}
    }
    l[i][0]=a;  l[i][1]=b;
  }
  //for(i=0;i<N;i++) printf("%d: %d\n",i,l[i][1]);
  for(i=0;i<N;i++) if(maxb<l[i][1]) maxb=l[i][1];
  printf("%d\n",maxb);
  return 0;
}
