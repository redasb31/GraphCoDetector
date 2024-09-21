#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define df 1
#define MOD 1000000007
#define min(a,b) (((a)<(b))?a:b)
int h,w,k;


int fibo[10]={1,1,2,3,5,8,13,21,34,55};
int f(int a,int b){
  if(a>b)return f(b,a);
  if(a<0 || b>w)return 0;
  return fibo[a-1]*fibo[w-b];
}

long int c[120][10];

int main(){

  scanf("%d%d%d",&h,&w,&k);
  int i,j;
  for(j=1;j<=w;j++){
    c[0][j]=(j==k)?1:0;
  }
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      c[i][j]=f(j-1,j)*c[i-1][j-1]+f(j,j)*c[i-1][j]+f(j+1,j)*c[i-1][j+1];
      c[i][j]%=MOD;
    }
  }

  printf("%ld",c[h][1]);
  return 0;
}


/// confirm df==0 ///
