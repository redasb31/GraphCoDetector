#include <stdio.h>

int main(void) {
	// your code goes here
	int n,x,sum = 0;
	scanf("%d",&n);
	scanf("%d",&x);
	int L[n-1];
	int j=0;
	for(int i =0;i<n;i++){
		scanf("%d",&L[i]);
		if(x>0&&n>0){
		sum += L[i];	
		if(sum<=x){
		
		
		j += 1;
		}
		}
		
	}
	printf("%d",j+1);
	return 0;
}