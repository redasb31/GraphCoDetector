#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i,j,h,w,x,y,s,ll,sss,set[150][150],q[20000][2];
char map[150][150];

int mark(int x,int y,int k,int lev){
	if(x<0 || y<0 || x>h+1 || y>w+1 || set[x][y]>=sss)return 0;
	char c =map[x][y];
	if(c=='&'){
		printf("%d\n",k-sss+lev);
		return 1;
	}
	if( (c=='#' && lev==0) || (c!='#' && lev==1) ){
		set[x][y]=k+lev;
		q[j][0]=x;q[j][1]=y;
		j++;
		return 0;
	}
	set[x][y]=k;
	if(mark(x-1,y,k,lev))return 1;
	if(mark(x+1,y,k,lev))return 1;
	if(mark(x,y-1,k,lev))return 1;
	if(mark(x,y+1,k,lev))return 1;
	return 0;
}


int main(){
	while(scanf("%d %d",&w,&h)*w*h){
		for(i=0;i<=h+1;i++)memset(map[i],'.',w+2);
		for(i=1;i<=h;i++)scanf("%s",&map[i][1]);
		
		sss+=200;
		q[0][0]=0;q[0][1]=0;
		set[0][0]=sss;
		i=0;j=1;

		while(i<j){
			x=q[i][0]; y=q[i][1]; s=set[x][y];
			if(map[x][y]=='#')ll=1; else ll=0;
			if(mark(x-1,y,s,ll))break;
			if(mark(x+1,y,s,ll))break;
			if(mark(x,y-1,s,ll))break;
			if(mark(x,y+1,s,ll))break;
			i++;
		}

	}
	return 0;
}