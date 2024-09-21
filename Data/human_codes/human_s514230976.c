#include <stdio.h>
#include <string.h>

int main(void){
	int m,n;
	//int table[100][100];
	int x,y,turn;
	char cmd[8];
	int step;
	
	while(1){
		scanf("%d %d",&m,&n);
		if(m==0 && n==0)break;
		
		x=1;
		y=1;
		turn = 1;
		
		while(1){
			
			scanf("%s", cmd);
			if ( strcmp(cmd , "FORWARD") == 0 || (strcmp(cmd, "BACKWARD") ==0)) scanf("%d", &step);
			
			//printf("aaa\n");
			
			//printf("%s : %d", cmd, step);
			
			if(strcmp(cmd, "STOP") == 0) break;
			if(strcmp(cmd, "FORWARD") == 0){      //**********************************
				if(turn == 1) {
					if(y+step > n){
						y = n;
					}else {
						y+=step;
					}
				}
				if(turn == 2) {
					if(x+step > m){
						x = m;
					}else {
						x+=step;
					}
				}
				if(turn == 3){
					if(y-step < 1){
						y = 1;
					}else {
						y -= step;
					}
				}
				if(turn == 4) {
					if(x-step < 1){
						x = 1;
					}else {
						x -= step;
					}
				}
			} else if (strcmp(cmd, "BACKWARD")==0){//******************************
				if(turn == 1) {
					if(y-step < 1){
						y = 1;
					}else {
						y-=step;
					}
				}
				if(turn == 2) {
					if(x-step < 1){
						x = m;
					}else {
						x-=step;
					}
				}
				if(turn == 3){
					if(y+step > n){
						y = n;
					}else {
						y += step;
					}
				}
				if(turn == 4) {
					if(x+step > m){
						x = m;
					}else {
						x += step;
					}
				}
			} else if (strcmp(cmd, "RIGHT") == 0){//******************************
				turn++;
			} else if (strcmp(cmd, "LEFT") == 0){
				turn--;
			}
			//printf("%d %d\n", x, y);
		}
		
		
		printf("%d %d\n", x, y);
	}
	
	return 0;
}