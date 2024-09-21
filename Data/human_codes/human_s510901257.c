#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void show(int **L,int N,int *ln){
	for(int i=0;i<N;i++){
		for(int j=0;j<ln[i];j++){
			printf("%d ",L[i][j]);
		}printf("\n");
	}printf("\n");
}

void calc(int N,int M,int *lane,int *number){
	int **list;
	int *lane_number;
	int min;

	list=(int**)malloc(N*sizeof(int*));
	lane_number=(int*)malloc(N*sizeof(int));
	for(int i=0;i<N;i++){
		lane_number[i]=0;
		list[i]=(int*)malloc(M*sizeof(int));
		for(int j=0;j<M;j++){
			list[i][j]=-1;
		}
	}

	for(int i=0;i<M;i++){
		switch(lane[i]){
		case 0:
			printf("%d\n",list[number[i]-1][0]);
			for(int j=0;j<lane_number[number[i]-1];j++){
				list[number[i]-1][j]=list[number[i]-1][j+1];
			}
			lane_number[number[i]-1]--;
			break;
		case 1:
			min=0;
			for(int j=1;j<N;j++){
				if(lane_number[min] > lane_number[j]){
					min=j;
				}
			}
			list[min][lane_number[min]]=number[i];
			lane_number[min]++;
			break;
		}
	}
}

int main(void){
	int N,M;
	int *lane,*number;

	scanf("%d %d",&N,&M);
	lane=(int*)malloc(M*sizeof(int));
	number=(int*)malloc(M*sizeof(int));
	for(int i=0;i<M;i++){
		scanf("%d %d",&lane[i],&number[i]);
	}

	calc(N,M,lane,number);

    return 0;
}
