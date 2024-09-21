#include <stdio.h>
 
int main(void){ 
  int a,b,c;
  
  do{
    scanf("%d %d %d",&a,&b,&c);
  }while(a<1||a>9||b<1||b>9||c<1||c>9);
  
  if(a==b==c){
    printf("No");
  }
  else{
    	if(a==b)
          printf("Yes");
    	else if(b==c)
          printf("Yes");
    	else if(c==a)
          printf("Yes");
    	else
          printf("No");
  }
  return 0;
}