#include <stdio.h>
#include <string.h>

#define REP(i,n,m) for(i=n;i<m;i++)
#define rep(i,n) REP(i,0,n)

int dx[4],dy[4];
int t[4][4];

int solve(int rem){
	int i;
	int x,y,nx,ny;
	int res = 0;

	if(rem == 0) return 1;

	rep(y,4) rep(x,4){
		if(t[y][x]) continue;
		t[y][x] = 1;

		rep(i,4){
			nx = x + dx[i];
			ny = y + dy[i];
			if(nx>=0 && nx<4 && ny>=0 && ny<4 && !t[ny][nx]){
				t[ny][nx] = 1;
				res += solve(rem-1);
				t[ny][nx] = 0;
			}
		}

		t[y][x] = 0;

		if(res > 0) return res;
	}

	return 0;
}

int main(void){
	int i;

	while(1){
		for(i=0;i<4;i++) if(scanf("%d%d",&dx[i],&dy[i]) != 2) return 0;
		memset(t,0,sizeof(t));
		printf("%d\n",solve(8));
	}
}