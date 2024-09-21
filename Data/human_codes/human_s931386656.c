#include<stdio.h>
#include<math.h>

int main(void){
	int i,j,t,n,y;
	while(scanf("%d" , &n) , n != 0){
		for(i = n;i >= 13;i--){
			t = i;
			y = 1;
			for(j = 2;j <= sqrt(t);j++){
				if(t % j){
				y = 0;
				break;
				}
			}
			if(!(y)){
				continue;
			}
			t = i - 2;
			y = 1;
			for(j = 2;j <= sqrt(t);j++){
				if(t % j){
				y = 0;
				break;
				}
			}
			if(!(y)){
				continue;
			}
			t = i - 6;
			y = 1;
			for(j = 2;j <= sqrt(t);j++){
				if(t % j){
				y = 0;
				break;
				}
			}
			if(!(y)){
				continue;
			}
			t = i - 8;
			y = 1;
			for(j = 2;j <= sqrt(t);j++){
				if(t % j){
				y = 0;
				break;
				}
			}
			if(!(y)){
				continue;
			}
			printf("%d\n" , i);
		}
	}
	return 0;
}