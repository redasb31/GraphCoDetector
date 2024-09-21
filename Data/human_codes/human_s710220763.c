#include<stdio.h>
#include<stdlib.h>

int compare_lld(const void *a, const void *b){return *(long long int*)a - *(long long int*)b; } 

int n, i;
long long int x, y;
char now;
long long int d[200000];

int main(){
scanf("%d\n", &n);
for(i=0; i<n; i++){
  scanf("%lld%lld\n", &x, &y);
  d[i*2] = x;
  d[i*2+1] = x+y;
}
n*=2;
qsort(d, n, sizeof(long long int), compare_lld);
for(i=0; i<n; i++){
  if(d[i] == x){
    now ^= d[i];
  }else{
    if(now){
      break;
    }else{
      x = d[i];
      now ^= d[i];
    }
  }
}
printf("%lld\n", x);
}
