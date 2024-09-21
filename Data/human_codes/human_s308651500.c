#include<stdio.h>

int main (void){

  int n,x,y,b,p,sum,i,sum1,sum2=0;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d %d %d %d",&x,&y,&b,&p); 
    if(b>=5&&p>=2){
      sum = ((x*b+y*p)*8)/10;
    }else{
      
      sum1 = x*b+y*p;
      sum = sum1;
      if(sum1>((x*5+y*2)*8)/10){
	b = b-5;
	p = p-2;
	if(b<0){
	  b=0;
	}
	if(p<0){
	  p=0;
	}
	sum2 = ((x*b+y*p)*8)/10+((x*5+y*2)*8)/10;
      
    
       if(sum1>sum2){
	sum = sum2;
      }else{
	sum = sum1;
       }
      }
    }
    printf("%d\n",sum);
  }
  return 0;
}