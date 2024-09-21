#include<stdio.h>
#include<math.h>
int prime_check(int n);

int main(void){
	int i,c,n;
	int data[6000];
	i=3;c=0;
	data[c++]=2;
	for(i=3;i< 50030;i+=2){
		if( prime_check(i)==1){
			data[c]=i;
			c++;
		}
	}
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<6000;i++){
			if(data[i]>=n){
				break;
			}
		}
		if(n==data[i]){
			printf("%d %d\n",data[i-1],data[i+1]);
		}else{
			printf("%d %d\n",data[i-1],data[i]);
		}
	}
	return 0;
}

int prime_check(int n){
	int i;
	if(n<2){return 0;}
	if(n==2){return 1;}
	if(n%2==0){return 0;}
	for(i=3;i<sqrt(n);i+=2){
		if(n%i==0){return 0;}
	}
	return 1;
}