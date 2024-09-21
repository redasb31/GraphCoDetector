#include <stdio.h>
int map[10002][5]={0};
int print_map(int H);
int check(int start);

int main(void) {
	int H,N,i,x,y,c;
	scanf("%d %d",&H,&N);

	for(i=0;i<N;i++){scanf("%d %d",&x,&y);map[y][x]=9;}
//	print_map(H);
//	for(i=0;i<=H-4;i++){
//		check(i);
//	}
	c=0;
	for(i=1;i<H;i++){
		if(map[i][1]==0&&map[i][0]==0&&map[i-1][1]==0&&map[i-1][0]==0){
			map[i][1]=1;map[i][0]=1;map[i-1][1]=1;map[i-1][0]=1;c++;
		}
		if(map[i][3]==0&&map[i][2]==0&&map[i-1][3]==0&&map[i-1][2]==0){
			map[i][3]=1;map[i][2]=1;map[i-1][3]=1;map[i-1][2]=1;c++;
		}
		if(map[i][2]==0&&map[i][1]==0&&map[i-1][2]==0&&map[i-1][1]==0){
			map[i][2]=1;map[i][1]=1;map[i-1][2]=1;map[i-1][1]=1;c++;
		}
	}
	printf("%d\n",c);
	return 0;
}

int print_map(int H){
	int i;
	for(i=0;i<H;i++){
		printf("%d%d%d%d\n",map[i][0],map[i][1],map[i][2],map[i][3]);
	}
	return 0;
}

int check(int start){
	int i,temp[4][4];
	printf("check\n");
	for(i=0;i<4;i++){
		temp[i][0]=map[start+i][0];
		temp[i][1]=map[start+i][1];
		temp[i][2]=map[start+i][2];
		temp[i][3]=map[start+i][3];
	}

	for(i=0;i<4;i++){
		printf("%d%d%d%d\n",temp[i][0],temp[i][1],temp[i][2],temp[i][3]);
	}
	printf("\n");
	return 0;
}

