#include <stdio.h>

/* {1,2,3} -> ... -> {3,2,1} */
int next_permutation(int arr[],int n) {
	int target;
	int i;
	int temp;
	int* arr2;
	int n2;
	for(i=n-2;i>=0;i--) {
		if(arr[i]<arr[i+1])break;
	}
	if(i<0)return 0;
	target=i;

	/* inline reverse_arr */
	arr2=arr+target+1;
	n2=n-target-1;
	for(i=0;n2-i-1>i;i++) {
		int t;
		t=arr2[i];
		arr2[i]=arr2[n2-i-1];
		arr2[n2-i-1]=t;
	}

	for(i=target+1;i<n;i++) {
		if(arr[i]>arr[target])break;
	}
	temp=arr[i];
	arr[i]=arr[target];
	arr[target]=temp;
	return 1;
}

int main(void) {
	int N,M;
	int enable[20]={0};
	double color[20][3];
	int i,j,k;
	double max_score=0;
	if(scanf("%d%d",&N,&M)!=2)return 1;
	for(i=0;i<N;i++) {
		if(scanf("%lf%lf%lf",&color[i][0],&color[i][1],&color[i][2])!=3)return 1;
	}
	for(i=0;i<M;i++)enable[N-1-i]=1;
	do {
		double cur_score=0;
		for(i=0;i<N;i++) {
			if(!enable[i])continue;
			for(j=i+1;j<N;j++) {
				if(!enable[j])continue;
				for(k=0;k<3;k++) {
					cur_score+=(color[i][k]-color[j][k])*(color[i][k]-color[j][k]);
				}
			}
		}
		if(cur_score>max_score)max_score=cur_score;
	} while(next_permutation(enable,N));
	printf("%.15f\n",max_score);
	return 0;
}