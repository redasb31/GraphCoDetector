#include <stdio.h>

int main(void) {
	int x_max,y_max;
	int course[17][17];
	int putterns[17][17];
	int x,y;
	int result;
	while(1) {
		scanf("%d%d",&x_max,&y_max);
		if(x_max==0 && y_max==0)break;
		for(y=0;y<y_max;y++) {
			putterns[y][0]=0;
			for(x=1;x<=x_max;x++) {
				scanf("%d",&course[y][x]);
				putterns[y][x]=0;
			}
			putterns[y][x]=0;
		}
		for(x=1;x<=x_max;x++) {
			putterns[y_max][x]=1;
			putterns[y_max+1][x]=1;
		}
		for(x=1;x<=x_max;x++) {
			if(course[y_max-1][x]==1)putterns[y_max-1][x]=0;
			else putterns[y_max-1][x]=1;
		}
		for(y=y_max-2;y>=0;y--) {
			for(x=1;x<=x_max;x++) {
				switch(course[y][x]) {
					case 1:
						putterns[y][x]=0;
						break;
					case 2:
						putterns[y][x]=putterns[y+2][x];
						break;
					default:
						putterns[y][x]=putterns[y+1][x];
						if(course[y+1][x-1]!=2) {
							putterns[y][x]+=putterns[y+1][x-1];
						}
						if(course[y+1][x+1]!=2) {
							putterns[y][x]+=putterns[y+1][x+1];
						}
						break;
				}
			}
		}
		for(x=1,result=0;x<=x_max;x++)result+=putterns[0][x];
		printf("%d\n",result);
	}
	return 0;
}