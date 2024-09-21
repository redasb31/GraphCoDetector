#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int width,height;
int gyou_stand_time[50000];
int retu_stand_time[50000];
int gyou_sit_time[50000];
int retu_sit_time[50000];

int qsort_comp(const void* x,const void* y) {
	int* a=(int*)x;
	int* b=(int*)y;
	if(*a>*b)return 1;
	if(*a<*b)return -1;
	return 0;
}

int get_upper_num(const int* arr,int max,int target) {
	int left,right,mid;
	left=0;right=max-1;
	while(left<=right) {
		mid=(left+right)/2;
		if(arr[mid]<=target)left=mid+1;
		else right=mid-1;
	}
	return max-(right+1);
}

int main(void) {
	int query_num,i;
	int q_isretu,q_id,q_order;
	int result;
	while(1) {
		scanf("%d%d%d",&height,&width,&query_num);
		if(height==0 && width==0 && query_num==0)break;
		memset(gyou_stand_time,0,sizeof(gyou_stand_time));
		memset(retu_stand_time,0,sizeof(retu_stand_time));
		memset(gyou_sit_time,0,sizeof(gyou_sit_time));
		memset(retu_sit_time,0,sizeof(retu_sit_time));
		for(i=1;i<=query_num;i++) {
			scanf("%d%d%d",&q_isretu,&q_id,&q_order);
			if(q_isretu) {
				if(q_order) {
					retu_stand_time[q_id]=i;
					retu_sit_time[q_id]=0;
				} else {
					retu_sit_time[q_id]=i;
					retu_stand_time[q_id]=0;
				}
			} else {
				if(q_order) {
					gyou_stand_time[q_id]=i;
					gyou_sit_time[q_id]=0;
				} else {
					gyou_sit_time[q_id]=i;
					gyou_stand_time[q_id]=0;
				}
			}
		}
		qsort(gyou_stand_time,width,sizeof(int),qsort_comp);
		qsort(gyou_sit_time,width,sizeof(int),qsort_comp);
		result=0;
		for(i=0;i<height;i++) {
			if(retu_stand_time[i]>retu_sit_time[i]) {
				result+=width-get_upper_num(
					gyou_sit_time,width,retu_stand_time[i]);
			} else {
				result+=get_upper_num(
					gyou_stand_time,width,retu_sit_time[i]);
			}
		}
		printf("%d\n",result);
	}
	return 0;
}