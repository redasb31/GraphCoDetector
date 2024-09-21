#include<stdio.h>

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n],i,sum = 0;
	
	for(i = 0;i < n;i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	
	int stand = sum/(4*m);
	int count = 0;
	for(i = 0; i < n;i++){
		if(a[i] >= stand)
			count++;
	}
	
	if(count >= m )
		printf("Yes");
	else
		printf("No");
		
		
	
	return 0;
} 