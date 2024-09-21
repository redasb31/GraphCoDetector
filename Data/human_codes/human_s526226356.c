#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define ll long long
#define MAX 200000000000
#define MOD 1000000007
ll int bin(ll int);

int main(void){
 ll int N,P;
 scanf("%lld%lld",&N,&P);
 ll int i;
 ll int A[100];
 ll int odd=0,even=0;
 for(i=0;i<N;i++){
  scanf("%d",&A[i]);
  if(A[i]%2) odd++;
  else even++;
 }
  if(odd!=0)
  printf("%lld\n",bin(even)*bin(odd-1));
  else
  {
    if(P==1) printf("0\n");
    else printf("%lld\n",bin(N));
  }
 return 0;
}

ll int bin(ll int a){
    if(a==0) return 1;
    return 2*bin(a-1);
}