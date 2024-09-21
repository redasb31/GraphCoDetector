#include<stdio.h>
int MAX(int a,int b){return a<b?b:a;}
int i,j,n,d[10][1000010]={1};
int main(){
  for(i=1;i<10;i++){
    for(j=0;j<1000000;j++){
      d[i][j]=d[i-1][j];
      if(j>=i)d[i][j]+=d[i][j-i];
    }
  }
  while(scanf("%d",&n),n){
    if(n%2==0)n/=2;
    printf("%d\n",d[MAX(n-16,0)][8]*n*40320);
  }
  return 0;
}