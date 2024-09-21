#include <stdio.h>
#include <stdlib.h>


double minute(int a, int b,int m){
	int sub;
	sub = a - b;
	if(sub < 0)
		sub *= -1;
	return ((double)sub * (70 + m) / 2000);
}
void way(int j,int n,int *num,int *box,int *dist, int *p, int *fp,int count,double *first){
	int  i, k, flag, m;
	double t;
	if(count < n){
		for(i = (j + 1) % n;i != j;i = (i + 1) % n){
			flag = 0;
			for(k = 0;k < count;k++){
				if(*(num + i) == *(p + k))
					flag = 1;
			}
			if(flag == 0){
				*(p + count) = *(num + i);
				count++;
				way(i,n,num,box,dist,p,fp,count,first);
				count--;
				*(p + count) = 0;
			}
		}
	}
	if(count == n){
		t = 0;
		m = 0;
		for(i = 0;i < n - 1;i++){
			for(j = 0;*(p + i) != *(num + j);j++);
			for(k = 0;*(p + i + 1) != *(num + k);k++);
			m += *(box + j);
			t += minute(*(dist + j),*(dist + k),m * 20);
		}
		if(*first == 0){
			*first = t;
			for(i = 0;i < n;i++)
				*(fp + i) = *(p + i);
		}
		else if(*first > t){
			*first = t;
			for(i = 0;i < n;i++)
				*(fp + i) = *(p + i);
		}
	}
}

int main(void){
	int n, i, *p, *fp, *num, *dist, *box;
	double *first;
	first = (double *)malloc(sizeof(double));
	for(i = 0;i < n;i++)
		*(p + i) = 0;
	*first = 0;
	while(scanf("%d",&n) != EOF){
		p = (int *)malloc(sizeof(int) * n);
		fp = (int *)malloc(sizeof(int) * n);
		num = (int *)malloc(sizeof(int) * n);
		dist = (int *)malloc(sizeof(int) * n);
		box = (int *)malloc(sizeof(int) * n);
		for(i = 0;i < n;i++){
			scanf("%d",num + i);
			scanf("%d",dist + i);
			scanf("%d",box + i);
			}
		for(i = 0;i < n;i++){
			*(p + 0) = *(num + i);
			way(i,n,num,box,dist,p,fp,1,first);
		}
		for(i = 0;i < n;i++)
			printf("%d ",*(fp + i));
		printf("\n");
	}
	return 0;
}