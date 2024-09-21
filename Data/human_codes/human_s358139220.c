#include<stdio.h>

int main(){
	
	int date[101][101];
	int i, j, x, y, goukei = 0;
	
	scanf("%d %d",&y,&x);
	
	for(i = 0; i < y; ++i){
		for(j = 0; j < x; ++j){
			
			scanf("%d",&date[i][j]);
		}
	}
	
	for(i = 0; i < y; ++i){
		for(j = 0; j < x; ++j){
			
			goukei += date[i][j];
		}
		
		date[i][x] = goukei;
		goukei = 0;
	}
	
	for(i = 0; i <= x; ++i){
		for(j = 0; j < y; ++j){
			
			goukei += date[j][i];
		}
		
		date[y][i] = goukei;
		goukei = 0;
	}
	
	for(i = 0; i <= y; ++i){
		for(j = 0; j <= x; ++j){
			
			if(j == 0){
				printf("%d",date[i][j]);
			}
			
			else{
				printf(" %d",date[i][j]);
			}
		}
		
		printf("\n");
	}
	
	return 0;
}