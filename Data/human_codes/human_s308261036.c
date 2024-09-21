#include<stdio.h>
#include<stdlib.h>

void run(void){
  int n,l;
  scanf("%d%d",&n,&l);
  if(l>1000) exit(1);
  double *dp=(double *)calloc(2*(l+1),sizeof(double));
  int t,v;
  scanf("%d%d",&t,&v);
  printf("%.7f\n",(double)t);
  int i,j;
  for(i=0;i<=l;i++) dp[i]=t;
  int now=0;
  for(i=1;i<n;i++){
    scanf("%d%d",&t,&v);
    int next=now^(l+1);
    dp[next+l]=(dp[now+l-v]*(l-v)+(double)v*t)/l;
    for(j=l-1;j>=v;j--){
      double tmp=(dp[now+j-v]*(j-v)+(double)v*t)/j;
      dp[next+j]=tmp>dp[next+j+1]?tmp:dp[next+j+1];
    }
    for(j=v-1;j>=0;j--) dp[next+j]=dp[next+j+1];
    printf("%.7f\n",dp[next+l]);
    now=next;
  }
}

int main(void){
  run();
  return 0;
}
