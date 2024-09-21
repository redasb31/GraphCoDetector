#include <stdio.h>

int map_size;
char map[1000][1001];
int map_ruiseki[1000][1000];

int is_ok(int y,int target) {
	int i;
	int now_renzoku;
	now_renzoku=0;
	for(i=0;i<map_size;i++) {
		if(map_ruiseki[y][i]>=target)now_renzoku++;
		else now_renzoku=0;
		if(now_renzoku>=target)return 1;
	}
	return 0;
}

int main(void) {
	int i,j;
	int now;
	int left,right,mid;
	int result;
	while(1) {
		scanf("%d",&map_size);
		if(map_size==0)break;
		for(i=0;i<map_size;i++)scanf("%s",map[i]);
		for(i=0;i<map_size;i++) {
			now=0;
			for(j=0;j<map_size;j++) {
				if(map[j][i]=='*')now=0; else now++;
				map_ruiseki[j][i]=now;
			}
		}
		result=0;
		for(i=0;i<map_size;i++) {
			left=result;right=map_size;
			while(left<=right) {
				mid=(left+right)/2;
				if(is_ok(i,mid))left=mid+1;
				else right=mid-1;
			}
			if(left-1>result)result=left-1;
		}
		printf("%d\n",result);
	}
	return 0;
}