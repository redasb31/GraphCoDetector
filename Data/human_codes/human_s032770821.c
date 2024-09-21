#include<stdio.h>

int main(void){
	int h,w,n,k,i,j,m[256][256] = {0},t = 1;
	unsigned long long int x = 1,r = 0;
	scanf("%d%d%d%d",&h,&w,&n,&k);
	for(i = 0;i < h;i++){
		for(j = 0;j < w;j++){
			printf("? %d %d %d %d\n",i,j,i,j);
			fflush(stdout);
			scanf("%d",&m[i][j]);
			if(m[i][j] == 1){n--;}
			if(n == 0){t = 0;break;}
		}
		if(!(t)){break;}
	}
	for(i = 0;i < h;i++){
		for(j = 0;j < w;j++){
			if(m[i][j]){r+=x;r%=k;}
			x*=2;x%=k;
		}
	}
	printf("! %llu\n",r);
	return 0;
}