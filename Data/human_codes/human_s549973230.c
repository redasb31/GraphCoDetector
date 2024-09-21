#include<stdio.h>

int main(){
	int board[17][17]={0};
	int i,j,n,x,y,p,q;

	while(scanf("%d%d",&x,&y),x+y){
		scanf("%d",&n);
		for(i=0;i<17*17;i++)
			board[i%17][i/17]=1-(i%17!=1&&i/17!=1)*2;
		for(i=0;i<n;i++){
			scanf("%d%d",&p,&q);
			board[p][q]=0;
		}
		for(i=2;i<=x;i++){
			for(j=2;j<=y;j++){
				if(board[i][j]<0){
					board[i][j]=board[i][j-1]+board[i-1][j];
				}
			}
		}
		printf("%d\n",board[x][y]);
	}
	return 0;
}