#include <stdio.h>
#include <math.h>

int main(){
    int n,i,tempi,ans,sum=0;
  	float avr,min,temp;

    scanf("%d",&n);
    int a[n];

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
      	sum+=a[i];
    }
  
  	avr=sum*1.0/n;
  	min=1<<29;
    tempi=0;
  
  	for(i=0;i<n;i++){
      temp=fabsf(a[i]-avr);
      if(min>temp){
        min=temp;
        tempi=i;
      }
    }
    
    printf("%d",tempi);
    return 0;
}