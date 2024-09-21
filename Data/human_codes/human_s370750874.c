#include<stdio.h>
int main(void){
	int number;
	int human[20] = {0},fish[20] = {0};
	int i;
	int max = 0;
	int x = 0;
	scanf("%d",&number);
	for(i = 0;i < number;i++){
		scanf("%d %d",&human[i],&fish[i]);
		if(fish[i] > max){
			max = fish[i];
			x = human[i];
		}
	}
	for(i = 0;i < number;i++){
		if((max == fish[i]) && (x > human[i])){
			x = human[i];
		}
	}
	printf("%d %d\n",x,max);
	return 0;
}