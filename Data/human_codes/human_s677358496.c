#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
	int value;
}Point;

Point Real[300*300+1];
int main(void) 
{
	
	int H,W,D,Q,a,b,k,l,m,number;
	scanf("%d%d%d",&H,&W,&D);
	for(k=0;k<=H*W;k++)
	{
		Real[k].value = 0;
	}
	for(a=0;a<H;a++)
	 {
	 	for(b=0;b<W;b++)
	 	{
	 		scanf("%d",&number);
	 		 Real[number].x = a;
	 		 Real[number].y = b;
	 	}
	 }
	 for(l=D+1;l<=H*W;l++)
	 {
	 	Real[l].value = Real[l-D].value + abs(Real[l].x-Real[l-D].x) 
	 	+abs(Real[l].y - Real[l-D].y);
	 }
	 scanf("%d", &Q);
	 for(m=0;m<Q;m++)
	 {
	 	scanf("%d%d", &a,&b);
	 	printf("%d¥n",(Real[b].value-Real[a].value));
	 }
}