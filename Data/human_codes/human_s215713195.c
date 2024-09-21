#include<stdio.h>
int main(void)
{
	int y[4],y1[4],w=0,i,flg=0;
	for(i=0;i<3;i++) scanf("%d",&y[i]);
	for(i=0;i<3;i++) scanf("%d",&y1[i]);
	if(y[0]>y1[0]) flg=1;
	else if(y[0]==y1[0]) flg=2;
	if(flg==1){
		w=y[0]-y1[0];
		if(y[1]>y1[1]) w++;
		else if(y[1]==y1[1]&&y[2]<y1[2]) w++;
		else if(y[1]==y1[1]&&y[2]>y1[2]) w++;
	}
	if(flg==0){
		w=y1[0]-y[0];
		if(y[1]<y1[1]) w++;
		if(y[1]>y1[1]) w++;
		else if(y[1]==y1[1]&&y[2]<y1[2]) w++;
		else if(y[1]==y1[1]&&y[2]>y1[2]) w++;
	}
	if(flg==2){
		if(y[1]>y1[1]) w++;
		if(y[1]<y1[1]) w++;
		else if(y[1]==y1[1]&&y[2]<y1[2]) w++;
		else if(y[1]==y1[1]&&y[2]>y1[2]) w++;
	}
	printf("%d",w);
	return 0;
}	