#include<stdio.h>


void to_time(int min,int* time){
	time[2]=min%60;
	time[1]=(min%3600-min%60)/60;
	time[0]=min/3600;
}
int main(){
	int h,m,s;
	int now,all=2*3600;
	while(1){
		int ans[3],ans3[3];
		scanf("%d %d %d",&h,&m,&s);
		if(h==-1)break;
		now=h*3600+m*60+s;
		to_time(all-now,ans);
		to_time(3*(all-now),ans3);
		printf("%d:%d:%d\n",ans[0],ans[1],ans[2]);
		printf("%d:%d:%d\n",ans3[0],ans3[1],ans3[2]);
	}
	return 0;
}