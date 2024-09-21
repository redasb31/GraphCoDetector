#include <stdio.h>
#include <stdlib.h>

int cube_all;
int cube_num[100];
int cube_map[100][100];
int cube_where[100];

/* syo-zyun */
int qsort_comp(const void* x,const void* y) {
	int* a=(int*)x;
	int* b=(int*)y;
	if(*a>*b)return 1;
	if(*a<*b)return -1;
	return 0;
}

int main(void) {
	int i,j;
	int which,where;
	int which_x,which_y,where_x,where_y;
	while(1) {
		scanf("%d",&cube_all);
		if(cube_all==0)break;
		for(i=0;i<cube_all;i++) {
			cube_num[i]=1;
			cube_map[i][0]=i+1;
		}
		while(1) {
			scanf("%d%d",&which,&where);
			if(which==0 && where==0)break;
			if(which==where)continue;
			which_x=which_y=where_x=where_y=0;
			for(i=0;i<cube_all;i++) {
				for(j=0;j<cube_num[i];j++) {
					if(cube_map[i][j]==which) {
						which_x=i;
						which_y=j;
					} else if(cube_map[i][j]==where) {
						where_x=i;
						where_y=j;
					}
				}
			}
			if(where==0) {
				if(which_y>0) {
					for(i=which_y+1;i<cube_num[which_x];i++) {
						for(j=0;j<cube_all;j++) {
							if(cube_num[j]<=0) {
								cube_num[j]=1;
								cube_map[j][0]=cube_map[which_x][i];
								break;
							}
						}
					}
					cube_num[which_x]=which_y;
				}
			} else {
				if(which_x!=where_x) {
					for(i=which_y+1;i<cube_num[which_x];i++) {
						for(j=0;j<cube_all;j++) {
							if(cube_num[j]<=0) {
								cube_num[j]=1;
								cube_map[j][0]=cube_map[which_x][i];
								break;
							}
						}
					}
					cube_num[which_x]=which_y;
					cube_map[where_x][cube_num[where_x]++]=which;
				} else if(which_y<where_y) {
					for(i=which_y+1;i<cube_num[which_x];i++) {
						for(j=0;j<cube_all;j++) {
							if(cube_num[j]<=0) {
								cube_num[j]=1;
								cube_map[j][0]=cube_map[which_x][i];
								if(cube_map[j][0]==where) {
									where_x=j;
								}
								break;
							}
						}
					}
					cube_num[which_x]=which_y;
					cube_map[where_x][cube_num[where_x]++]=which;
				}
			}
		}
		qsort(cube_num,cube_all,sizeof(int),qsort_comp);
		for(i=0;i<cube_all;i++) {
			if(cube_num[i]>0)printf("%d\n",cube_num[i]);
		}
		puts("end");
	}
	return 0;
}