#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int me = 0;

void sea(int *r,int m,int n,int k){
  if(n > 1){
    sea(r,m*2,n-1,k);
    sea(r,m+k,n-1,k);
  }
  if(n == 1){
    r[me]= m*2;
    me++;
    r[me] = m+k;
    me++;
  }
}

int main(){
  int n,k;
  scanf("%d %d",&n,&k);
  int m = 1;
  int r[(int)pow(2,n)];
  sea(r,m,n,k);
  int i;
  int min = 50000000;
  for(i=0;i<(int)pow(2,n);i++){
    if(r[i] < min){
      min = r[i];
    }
  }
  printf("%d\n",min);

}
