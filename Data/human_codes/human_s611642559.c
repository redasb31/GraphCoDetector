#include<stdio.h>
#include<stdlib.h>
int compare_int(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int n;
	scanf("%d/n",&n);
	int a[n],i;
	long long int ans=0,median;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i] += -i;
	}
	qsort(a,n,sizeof(int),compare_int);
	if(n%2==1){
		median = a[(n+1)/2];
	}else{
		median = a[n/2];
	}
	for(i=0;i<n;i++){
		ans += abs(a[i]-i-median);
	}
	printf("%d",ans);
	return 0;
}
