#include <stdio.h>
#include <stdlib.h>

void shuffle(int *p,int k,int arraynum){
	int first[200];
	int second[200];
	int i;
	for(i=0;i<k;i++){
		first[i] = p[i];
	}
	for(;i<arraynum*2;i++){
		second[i-k] = p[i];
	}
	for(i=0;i<2*arraynum;i++){
		if(i<(arraynum*2-k)){
			p[i] = second[i];
		}
		else{
			p[i] = first[i+k-arraynum*2];
		}
	}
}

void refshf(int *p,int arraynum){
	int first[200];
	int second[200];
	int i;
	
	for(i=0;i<arraynum;i++){
		first[i] = p[i];
		second[i] = p[i+arraynum];
	}
	
	
	for(i=0;i<2*arraynum;i++){
		switch(i%2){
			case (0):p[i] = first[i/2];break;
			case (1):p[i] = second[i/2];break;
		}
	}
}

void center(int *shfjudge,int *array,int arraynum,int times){
	int i;
	for(i=0;i<times;i++){	//sizeof(ポインタ)は出来ない事に注意
		switch(shfjudge[i]){
			case 0: refshf(array,arraynum);break;
			default: shuffle(array,shfjudge[i],arraynum);break;
		}
	}
	for(i=0;i<arraynum*2;i++){
		printf("%d\n",array[i]);
	}
}

int main(void)
{
	int arraynum,times;
	int *shfjudge,*array;
	
	scanf("%d",&arraynum);
	array = (int *)calloc(2*arraynum,sizeof(int));
	if(array == NULL){
		printf("失敗1");
		return EXIT_FAILURE;
	}
	scanf("%d",&times);
	shfjudge = (int *)calloc(times,sizeof(int));
	if(shfjudge == NULL){
		printf("失敗2");
		return EXIT_FAILURE;
	}
	
	int i;
	for(i=0;i<arraynum*2;i++){
		array[i] = i+1;
	}	
	for(i=0;i<times;i++){
		scanf("%d",&shfjudge[i]);
	}
	center(shfjudge,array,arraynum,times);
	free(array);
	free(shfjudge);
	return 0;
}
