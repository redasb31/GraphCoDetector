#include<stdio.h>
#include<math.h>


#define SIZE 10000


int main(void){

	int i,j,n,a,b,ad,bd,amariA,amariB,sum[SIZE],temp;
	scanf("%d",&n);
	
	for(i=1;i<n;i++){
		 
		b = i;
		a = n - b;
		ad = 0;
		bd = 0;
	
		for(j=1;j<=5;j++){
			amariA = a%10;//(int)pow(10,j);
			amariB = b%10;//(int)pow(10,j);
			ad += amariA;
			//printf("%d\n",ad);
			bd += amariB;
			a -= amariA;//pow(10,j-1);
			a = a/10;
			b -= amariB;//pow(10,j-1);
			b = b/10;   
		}

		sum[i] = ad + bd;
		//printf("%d\n",sum[i]);
	}

	temp = 99999;
	for(i=1;i<n;i++){

		if(temp>=sum[i]){
			 temp = sum[i];
		//	printf("%d\n",temp);
		
		}
	}
	
	printf("%d",temp);

	return 0;
	
}

