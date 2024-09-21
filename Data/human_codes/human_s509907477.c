#include<stdio.h>

int main(){

  char a = '#';
  char A = '.';
  int i,j;
  int b[300][300];
  int x,y;
  
  while(1){
    scanf("%d%d",&x,&y);
  
  if (x ==0 && y ==0){
    break;
  }
    
  for(i=0;i<x;i++){
    for(j=0;j<y;j++){
      
      if( i==0 || i ==x-1 || j==0 || j==y-1) printf("%c",a);
      else printf("%c",A);
      
    }printf("\n");
  }
  printf("\n");
  }

  return 0;
}