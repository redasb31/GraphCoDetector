#include<stdio.h>

int main(void){
	int a,b,c,k;

	scanf("%d %d %d %d",&a,&b,&c,&k);
	//2 1 1 3
	int ten=0;
	if(k >= a){
		ten=a; k=k-a;
		if(k >= b){
			k=k-b;
			if(k >= c){
				ten=ten-c;
				k=k-c;
			}else{
				ten=ten-k;
			}
		}else{
		}
	}else{
		ten=k;
	}
	printf("%d",ten);

	return 0;
}
