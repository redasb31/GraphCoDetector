#include<stdio.h>

int main(void){
  int n,stone[10003],i,count,white,black;

  while(1){
    count=0;
    white=0;
    black=0;

    scanf("%d",&n);
    if(n==0)break;

    for(i=1;i<=n;i++){
      scanf("%d",&stone[i]);
    }

    for(i=2;i<=n;i+=2){
 
      if(n%2==1 && i>n){
	if(stone[i-1]==0)count++;
	break;
      }
      
      if(stone[i]==0 && stone[i-1]==0){
	count+=2;
	  white+=2;
	  black=0;
      }
      else if(stone[i]==1 && stone[i-1]==0){
	black+=2+white;
	if(i-white-2>0 && stone[i-white-2]==0){
	    black+=2;
	    count-=2;
	}
	count-=white;
	white=0;
      }
      else if(stone[i]==1 && stone[i-1]==1){
	black+=2;
	white=0;
      }
      else if(stone[i]==0 && stone[i-1]==1){
	count+=2+black;
	white+=2+black;
	if(i-black-2>0 && stone[i-black-2]==1){
	  white+=2;
	  count+=2;
	}
	black=0;
      }
    }
    
    if(n%2==1 && stone[n]==0)count++;
    printf("%d\n",count);
  }
  return 0;
}