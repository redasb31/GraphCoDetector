#include<stdio.h>
int main(){
  long long n,r=0,i,j;
  char s[20]={};
  scanf("%lld",&n);
  while(1){
    for(j=1;j<10;j++){
      printf("%lld%s\n",j,s);
      n--;
      if(n==0)return 0;
    }
    s[r]='9';
    s[++r]=0;//printf("!!%s\n",s);
  }
  return 0;
}
