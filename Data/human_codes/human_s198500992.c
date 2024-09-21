#include<stdio.h>

int main(void)
{
  int n;
  
  while( scanf("%d",&n) ){
    int count=0;
    if(n==0 )break;
    while(n!=1){
      count++;
      if( n%2 == 0 ){
	n=n/2;
      }
      else{
	n=n*3+1;
      }
    } 
    
    printf("%d\n",count);
  }
  
  return 0;
}