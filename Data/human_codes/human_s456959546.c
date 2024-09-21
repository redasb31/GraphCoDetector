#include <stdio.h>
int main(void){
  int N,M,f_A[10]={},i,j,dp[420]={},cost[10]={0,2,5,5,4,5,6,3,7,6};

  scanf("%d %d\n%d",&N,&M,&i);
  f_A[i]=1;
  for(j=2;j<=M;j++){scanf(" %d",&i);f_A[i]=1;}

  for(i=2;i<=N%420;i++)
  {
    if(i-2>=0&&f_A[1])dp[i]=dp[i-2]+1;
    if(i-3>=0&&f_A[7])if(dp[i]<dp[i-3]+1)dp[i]=dp[i-3]+1;
    if(i-4>=0&&f_A[4])if(dp[i]<dp[i-4]+1)dp[i]=dp[i-4]+1;
    if(i-5>=0&&(f_A[2]||f_A[3]||f_A[5]))if(dp[i]<dp[i-5]+1)dp[i]=dp[i-5]+1;
    if(i-6>=0&&(f_A[6]||f_A[9]))if(dp[i]<dp[i-6]+1)dp[i]=dp[i-6]+1;
    if(i-7>=0&&f_A[8])if(dp[i]<dp[i-7]+1)dp[i]=dp[i-7]+1;
  }

  dp[1]=1000;
  if(!f_A[1]){dp[2]=1000;}
  if(!f_A[7]){dp[3]=1000;}
  if(!f_A[4])dp[4]=1000;
  if(!(f_A[2]||f_A[3]||f_A[5]))dp[5]=1000;
  if(!(f_A[6]||f_A[9]))dp[6]=1000;
  if(!f_A[8])dp[7]=1000;

  for(i=N%420;i>0;)
  {
    if((f_A[9]>0)&&(dp[i]==dp[i-6]+1)){f_A[9]++;i-=6;}
    else if((f_A[8]>0)&&(dp[i]==dp[i-7]+1)){f_A[8]++;i-=7;}
    else if((f_A[7]>0)&&(dp[i]==dp[i-3]+1)){f_A[7]++;i-=3;}
    else if((f_A[6]>0)&&(dp[i]==dp[i-6]+1)){f_A[6]++;i-=6;}
    else if((f_A[5]>0)&&(dp[i]==dp[i-5]+1)){f_A[5]++;i-=5;}
    else if((f_A[4]>0)&&(dp[i]==dp[i-4]+1)){f_A[4]++;i-=4;}
    else if((f_A[3]>0)&&(dp[i]==dp[i-5]+1)){f_A[3]++;i-=5;}
    else if((f_A[2]>0)&&(dp[i]==dp[i-5]+1)){f_A[2]++;i-=5;}
    else if((f_A[1]>0)&&(dp[i]==dp[i-2]+1)){f_A[1]++;i-=2;}
  }

  if(f_A[1])f_A[1]+=(N/420)*210;
  else if(f_A[7])f_A[7]+=(N/420)*140;
  else if(f_A[4])f_A[4]+=(N/420)*105;
  else if(f_A[5])f_A[5]+=(N/420)*84;
  else if(f_A[3])f_A[3]+=(N/420)*84;
  else if(f_A[2])f_A[2]+=(N/420)*84;
  else if(f_A[9])f_A[9]+=(N/420)*70;
  else if(f_A[6])f_A[6]+=(N/420)*70;
  else if(f_A[8])f_A[8]+=(N/420)*60;
  for(i=9;i>=1;i--)for(j=0;j<f_A[i]-1;j++)printf("%d",i);
  return 0;
}
