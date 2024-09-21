#include<stdio.h>
int main(){
  int X;
  int A,B;
  long long int pa,pb;
    
  scanf("%d",&X);
X=1;
  
  for(A=-200;A<200;A++){
  	for(B=-200;B<200;B++){
      pa=A*A*A*A*A;
      pb=B*B*B*B*B;
	
    	if(pa-pb==X){
          break;
        }
        

     }
  
  if(pa-pb==X){
          break;
        }
  }	 
	 printf("%d %d",A,B);
  
  return 0; 
}