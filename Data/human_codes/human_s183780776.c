#include <stdio.h>
int main(void){

    long int n,k;
    long int count=0;
    scanf("%ld %ld",&n,&k);
  
  	if(k==0){
      	printf("%d",n*n);
      	return 0;
    }
  
  	for(long int l=0;l<=n-k-1;++l){
    	for(long int i=k+1+l;i<=n-k-l;++i){
			count += (n-k-l)/i;
    	}
    }
  	count += ((n-k)*(n-k+1))/2;
  
    printf("%ld",count);

    return 0;
}