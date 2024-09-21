#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
位置，進行方向
tim [0][x][y]東西 x→x+1
tim [1][x][y]南北 y→y+1
方向
 3
2 0
 1
*/

int tim[2][60][60],sig[60][60],size[101],q[101][10000][3],mk[20][20][4][101];
int M,N,FR,TO,GX,GY,ANS,SET;

void mark(int x,int y,int dir,int t){
	int tx=x-(dir%2)*((dir/2)*2-1);
	int ty=y-((dir+1)%2)*((dir/2)*2-1);

	//if(t<7)printf("%d-%d (%d)→ %d-%d\n",x,y,dir,tx,ty);
	if(tx<0 || tx>=M || ty<0 || ty>=N)return;

	int ttt=tim[dir%2][x-(dir%2)*(dir/2)][y-((dir+1)%2)*(dir/2)];
	if(ttt<0)return;
	ttt+=t;

	if(mk[tx][ty][dir][ttt]==SET)return;
	if(ttt>100)return;
	if(sig[tx][ty]!=0 && (ttt/sig[tx][ty])%2==dir%2)return;

	q[ttt][size[ttt]][0]=tx;
	q[ttt][size[ttt]][1]=ty;
	q[ttt][size[ttt]][2]=dir;
	size[ttt]++;
	if(tx==GX && ty==GY && ANS>ttt)ANS=ttt;
	mk[tx][ty][dir][ttt]=SET;
	//if(ttt<7)printf("%d-%d %d → %d-%d,%d\n",x,y,t,tx,ty,ttt);
}

void check(int i,int j){
	int x=q[i][j][0];
	int y=q[i][j][1];
	int d=q[i][j][2];
	int k;
	for(k=-1;k<=1;k++)mark(x,y,(d+k+4)%4,i);
}

int main(){
    int i,j,k,ay,by,val;
	char ax,bx;

    while(scanf("%d %d",&M,&N)*M*N){
		SET++;

		scanf("%d",&k);
		for(i=0;i<M;i++){
			for(j=0;j<N;j++){
				tim[0][i][j]=k;
				tim[1][i][j]=k;
				sig[i][j]=0;
			}
		}

		scanf("%d%*c",&k);
		for(i=0;i<k;i++){
			scanf("%c%*c%d %d%*c",&ax,&ay,&val);
			sig[ax-'a'][ay-1]=val;
		}

		scanf("%d%*c",&k);
		for(i=0;i<k;i++){
			scanf("%c%*c%d %c%*c%d%*c",&ax,&ay,&bx,&by);
			if(bx==ax && by-ay==1)tim[0][ax-'a'][ay-1]=-1;
			else if(bx-ax==1 && by==ay)tim[1][ax-'a'][ay-1]=-1;
		}

		scanf("%d%*c",&k);
		for(i=0;i<k;i++){
			scanf("%c%*c%d %c%*c%d %d%*c",&ax,&ay,&bx,&by,&val);
			if(bx==ax && by-ay==1)tim[0][ax-'a'][ay-1]+=val;
			else if(bx-ax==1 && by==ay)tim[1][ax-'a'][ay-1]+=val;
		}

		scanf("%c%*c%d %c%*c%d%*c",&ax,&ay,&bx,&by);

		q[0][0][0]=ax-'a';
		q[0][0][1]=ay-1;
		q[0][0][2]=0;
		size[0]=1;
		GX=bx-'a';GY=by-1;
		FR=0;TO=1;ANS=101;

		//for(i=0;i<M;i++){for(j=0;j<N;j++){printf("%3d",sig[i][j]);}printf("\n");}printf("\n");
		//for(i=0;i<M;i++){for(j=0;j<N;j++){printf("%3d",tim[0][i][j]);}printf("\n");}printf("\n");
		//for(i=0;i<M;i++){for(j=0;j<N;j++){printf("%3d",tim[1][i][j]);}printf("\n");}printf("\n");
		
		for(i=1;i<101;i++)size[i]=0;

		for(i=0;i<ANS;i++){
			for(j=0;j<size[i];j++){
				check(i,j);
			}
			//printf("%dmin size=%d\n",i,size[i]);
			//if(size[i]>2000)fprintf(stderr,"Danger!!\n");
		}

		printf("%d\n",ANS);

    }
 
    return 0;
}