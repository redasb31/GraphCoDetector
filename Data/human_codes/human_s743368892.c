#include<stdio.h>
#include<stdlib.h>

int main(){
	int x,y;
	while(~scanf("%d%d",&x,&y)){
		x=abs(x);
		y=abs(y);
		int ans;
		if(x+y==1)ans=1;
		else if((x+y)%2==0)ans=x+y-(x%2?1:0);
		else ans=x+y+(x==0||y==0?1:0);
		printf("%d\n",ans);
	}
}
