#include<stdio.h>
#define rep(i,n,m) for((i)=(int)(n);(i)<=(int)(m);(i)++)

int memo[301];

int main(void){
  int i,j,n,coin[18];

  rep(i,0,16)coin[i]=(i+1)*(i+1);
  memo[0]=1;

  rep(i,0,16)rep(j,1,300)
    if(j>=coin[i])memo[j]+=memo[j-coin[i]];
  
  while(scanf("%d",&n),n)
    printf("%d\n",memo[n]);
  
  return 0;
}