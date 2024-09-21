#include<stdio.h>

int main() {
  int n, k;
  int sum,tmp,poszero;
  int xs[100000]={};
  int lengpos, lengneg;
  int min=0x7fffffff;

  scanf("%d %d", &n, &k);


  for(int i=0;i<n;i++){
    scanf("%d", &xs[i]);
  }


  for(int i=0;i<n;i++){
    if(xs[i]>=0){
      poszero=i;
      break;
    }
  }

  if(poszero==0){
    printf("%d\n", xs[k-1]);
    return 0;
  }

  if(poszero==n-1){
    printf("%d\n", xs[poszero-k]);
    return 0;
  }

  for(int i=1;i<poszero+1&&i<k+1;i++){
    if(poszero+k-i-1<n){
      sum = (-1)*xs[poszero-i];
      sum += xs[poszero+k-i-1]+sum;
      if(sum<min)
        min=sum;
    }
  }

  printf("%d\n",min);


  return 0;
}
