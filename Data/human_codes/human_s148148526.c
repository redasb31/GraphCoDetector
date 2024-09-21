#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=(a);i<(n);i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
ll dp[5001];
int main(void)
{
	int n,a,p,i;
	ll res=0;
	scanf("%d%d",&n,&p);
	dp[0]=1;
	while(n-->0){
		scanf("%d",&a);
		for(i=5000;i>=a;i--) dp[i]+=dp[i-a];
	}
	for(i=p;i<=5000;i+=2) res+=dp[i];
	printf("%lld\n",res); 
	return 0;
}    