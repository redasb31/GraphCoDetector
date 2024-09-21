#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int tate;
	int yoko;
} xy_t;

int qsort_comp(const void* x,const void* y) {
	const xy_t* a=(const xy_t*)x;
	const xy_t* b=(const xy_t*)y;
	if((a->tate)>(b->tate))return 1;
	if((a->tate)<(b->tate))return -1;
	if((a->yoko)>(b->yoko))return 1;
	if((a->yoko)<(b->yoko))return -1;
	return 0;
}

int yz_num,xz_num,xy_num;
xy_t yz[200];/* tate:z yoko:y */
xy_t xz[200];/* tate:z yoko:x */
xy_t xy[200];/* tate:x yoko:y */
int yz_pos[501][2];
int xz_pos[501][2];

int findit(const xy_t* from,int start,int end,int target) {
	int left,right,mid;
	left=start;right=end-1;
	while(left<=right) {
		mid=(left+right)/2;
		if(from[mid].yoko==target)return mid;
		else if(from[mid].yoko<target)left=mid+1;
		else right=mid-1;
	}
	return -1;
}

int main(void) {
	int i,j;
	int prev;
	int n,h;
	char type[4];
	int result,temp;
	while(1) {
		scanf("%d%d",&n,&h);
		if(n==0 && h==0)break;
		yz_num=xz_num=xy_num=0;
		for(i=0;i<h;i++) {
			int a,b;
			scanf("%s%d%d",type,&a,&b);
			if(type[0]=='x' && type[1]=='y') {
				xy[xy_num].tate=a;
				xy[xy_num].yoko=b;
				xy_num++;
			} else if(type[0]=='x' && type[1]=='z') {
				xz[xz_num].tate=b;
				xz[xz_num].yoko=a;
				xz_num++;
			} else if(type[0]=='y' && type[1]=='z') {
				yz[yz_num].tate=b;
				yz[yz_num].yoko=a;
				yz_num++;
			}
		}
		qsort(xz,xz_num,sizeof(xy_t),qsort_comp);
		qsort(yz,yz_num,sizeof(xy_t),qsort_comp);
		memset(xz_pos,0,sizeof(xz_pos));
		memset(yz_pos,0,sizeof(yz_pos));
		prev=0;
		for(i=0;i<xz_num;i++) {
			if(xz[prev].tate!=xz[i].tate) {
				xz_pos[xz[prev].tate][1]=i;
				xz_pos[xz[i].tate][0]=i;
				prev=i;
			}
		}
		xz_pos[xz[prev].tate][1]=i;
		prev=0;
		for(i=0;i<yz_num;i++) {
			if(yz[prev].tate!=yz[i].tate) {
				yz_pos[yz[prev].tate][1]=i;
				yz_pos[yz[i].tate][0]=i;
				prev=i;
			}
		}
		yz_pos[yz[prev].tate][1]=i;
		result=0;
		for(i=1;i<=n;i++) {
			temp=n*n;
			temp-=(xz_pos[i][1]-xz_pos[i][0])*n;
			temp-=(yz_pos[i][1]-yz_pos[i][0])*n;
			temp+=(xz_pos[i][1]-xz_pos[i][0])*(yz_pos[i][1]-yz_pos[i][0]);
			temp-=xy_num;
			for(j=0;j<xy_num;j++) {
				if(findit(xz,xz_pos[i][0],xz_pos[i][1],xy[j].tate)>=0 ||
					findit(yz,yz_pos[i][0],yz_pos[i][1],xy[j].yoko)>=0)temp++;
			}
			result+=temp;
		}
		printf("%d\n",result);
	}
	return 0;
}