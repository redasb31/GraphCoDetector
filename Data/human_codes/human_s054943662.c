#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,weight;
  scanf("%d%d",&n,&weight);
  int v[100];
  int w[100];
  int m[100];
  int i;
  for(i=0;i<n;i++) scanf("%d%d%d",v+i,w+i,m+i);
  int dp[10001];
  for(i=0;i<=weight;i++) dp[i]=-1;
  dp[i]=0;
  for(i=0;i<n;i++){
    int s,k;
    for(s=0,k=1;s+k<=m[i];s+=k,k*=2){
      int vv=k*v[i];
      int ww=k*w[i];
      int j;
      for(j=weight;j>=ww;j--){
	int index=j-ww;
	if(dp[index]!=0){
	  dp[j]=MAX(dp[j],dp[index]+vv);
	}
      }
    }
    if(m[i]-s>0){
      k=m[i]-s;
      int vv=k*v[i];
      int ww=k*w[i];
      int j;
      for(j=weight;j>=ww;j--){
	int index=j-ww;
	if(dp[index]!=0){
	  dp[j]=MAX(dp[j],dp[index]+vv);
	}
      }
    }
  }
  int max=0;
  for(i=0;i<=weight;i++) max=MAX(max,dp[i]);
  printf("%d\n",max);
  return;
}

int main(void){
  run();
  return 0;
}

