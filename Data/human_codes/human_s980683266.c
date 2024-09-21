#include<stdio.h>
int m[10][10];
#define r(i) for(i=0;i<10;i++)
void ink(int x,int y){
	if(x<0 || y<0|| x>9 ||y>9)return;
	m[x][y]++;
}
void show(){
	int i,j;
	r(i){
		r(j)printf("%d",m[i][j]);
		printf("\n");
	}
}
int main(){
	int i,j,c,max,x,y,s;
	r(i)r(j)m[i][j]=0;
	while(scanf("%d,%d,%d",&x,&y,&s)!=EOF){
		for(i=s;i>=0;i--){
			if(i==3){ink(x+2,y);ink(x-2,y);ink(x,y-2);ink(x,y+2);}
			else if(i==2){ink(x+1,y+1);ink(x+1,y-1);ink(x-1,y+1);ink(x-1,y-1);}
			else if(i==1){ink(x+1,y);ink(x-1,y);ink(x,y-1);ink(x,y+1);ink(x,y);}
		}
	}
	c=0;max=0;
	r(i)r(j){if(!m[i][j])c++;if(max<m[i][j])max=m[i][j];}
	printf("%d\n%d\n",c,max);
	return 0;
}