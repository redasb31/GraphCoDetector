#include <stdio.h>
#include <string.h>

const int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};

int syoukyo(int banmen[5][5],int scorelist[5]) {
	int score=0;
	int kesuflag[5][5]={0};
	int kietaflag=0;
	int i,j,k;
	for(i=0;i<5;i++) {
		for(j=0;j<3;j++) {
			if(banmen[i][j]==banmen[i][j+1] && banmen[i][j+1]==banmen[i][j+2]) {
				kesuflag[i][j]=kesuflag[i][j+1]=kesuflag[i][j+2]=1;
			}
		}
	}
	for(i=0;i<3;i++) {
		for(j=0;j<5;j++) {
			if(banmen[i][j]==banmen[i+1][j] && banmen[i+1][j]==banmen[i+2][j]) {
				kesuflag[i][j]=kesuflag[i+1][j]=kesuflag[i+2][j]=1;
			}
		}
	}
	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			if(kesuflag[i][j] && banmen[i][j]>0) {
				score+=scorelist[banmen[i][j]-1];
				banmen[i][j]=0;
				kietaflag=1;
			}
		}
	}
	for(i=3;i>=0;i--) {
		for(j=0;j<5;j++) {
			if(banmen[i+1][j]==0) {
				for(k=i+1;k<5 && banmen[k][j]==0;k++);
				banmen[k-1][j]=banmen[i][j];
				banmen[i][j]=0;
			}
		}
	}
	return kietaflag?score:-1;
}

int getscore(int banmen[5][5],int scorelist[5]) {
	int bonus;
	int scoresum=0;
	int nowscore;
	for(bonus=1;(nowscore=syoukyo(banmen,scorelist))>=0;bonus++) {
		scoresum+=nowscore*bonus;
	}
	return scoresum;
}

int main(void) {
	int n;
	int banmen[5][5];
	int banmen2[5][5];
	int scorelist[5];
	int i,j,x,y,idounum;
	int maxscore,nowscore;
	while(scanf("%d",&n)==1 && n>=0) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++)scanf("%d",&banmen[i][j]);
		}
		for(i=0;i<5;i++)scanf("%d",&scorelist[i]);
		memcpy(banmen2,banmen,sizeof(banmen));
		maxscore=getscore(banmen2,scorelist);
		for(idounum=1;idounum<=n;idounum++) {
			for(i=0;i<1<<(idounum*2);i++) {
				for(y=0;y<5;y++) {
					for(x=0;x<5;x++) {
						int nx=x,ny=y;
						int error=0;
						memcpy(banmen2,banmen,sizeof(banmen));
						for(j=0;j<idounum;j++) {
							int mid=(i>>(j*2))&3;
							int temp;
							if(nx+dir[mid][0]<0 || nx+dir[mid][0]>=5 ||
								ny+dir[mid][1]<0 || ny+dir[mid][1]>=5){error=1;break;}
							temp=banmen2[ny][nx];
							banmen2[ny][nx]=banmen2[ny+dir[mid][1]][nx+dir[mid][0]];
							banmen2[ny+dir[mid][1]][nx+dir[mid][0]]=temp;
							nx+=dir[mid][0];
							ny+=dir[mid][1];
						}
						if(error)continue;
						nowscore=getscore(banmen2,scorelist);
						if(nowscore>maxscore)maxscore=nowscore;
					}
				}
			}
		}
		printf("%d\n",maxscore);
	}
	return 0;
}