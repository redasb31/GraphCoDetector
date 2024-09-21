#include <stdio.h>
#include <string.h>

#define REP(i,n,m) for(i=n;i<m;i++)
#define rep(i,n) REP(i,0,n)

int h,w;
int tx[4],ty[4],size;
int area[80010];
char t[1002][82];

int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {-1,-1,0,1,1,1,0,-1};

void updatePoint(int x,int y){
	if(ty[0] > y){
		ty[0] = ty[3] = y;
		tx[0] = tx[3] = x;
	}
	else if(ty[0] == y){
		if(tx[0] > x) tx[0] = x;
		else if(tx[3] < x) tx[3] = x;
	}

	if(ty[1] < y){
		ty[1] = ty[2] = y;
		tx[1] = tx[2] = x;
	}
	else if(ty[1] == y){
		if(tx[1] > x) tx[1] = x;
		else if(tx[2] < x) tx[2] = x;
	}
}

void solve(int x,int y,int d){
	int i,nx,ny;

	t[y][x] = ' ';
	updatePoint(x,y);

	rep(i,8){
		nx = x + dx[i];
		ny = y + dy[i];

		if(nx>=0 && nx<w && ny>=0 && ny<h && t[ny][nx]=='*'){
			solve(nx,ny,i);
		}
	}
}

int main(void){
	int set,i,j;
	char s[12];
	w = 80;

	for(set=0;fgets(s,12,stdin);set++){
		h = atoi(s);
		if(h == 0) break;
		if(set != 0) printf("----------\n");

		memset(t,' ',sizeof(t));
		memset(area,0,sizeof(area));

		rep(i,h) fgets(t[i],w,stdin);

		rep(i,h) rep(j,w) if(t[i][j] == '*') {
			size = 0;
			tx[0] = tx[1] = w;
			tx[2] = tx[3] = 0;
			ty[0] = ty[3] = h;
			ty[1] = ty[2] = 0;

			solve(j,i,-1);

			area[((tx[3]-tx[0]+1)+(tx[2]-tx[1]+1))*(ty[1]-ty[0]+1)/2]++;
		}

		rep(i,80010) if(area[i] > 0) {
			printf("%d %d\n",i,area[i]);
		}
	}

	return 0;
}