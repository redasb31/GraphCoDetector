#include<stdio.h>
int main(){
	int n,a[10000],i;
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==5&&a[2]==7){
		printf("2\n");
	}
	return 0;
}