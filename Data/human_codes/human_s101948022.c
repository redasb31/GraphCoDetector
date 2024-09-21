#include <stdio.h>

int main(){
	int N;
	int count=0;
	int eq;
	
	scanf("%d",&N);
	
	char A[N],B[N],C[N];
	
	scanf("%s",&A);
	scanf("%s",&B);
	scanf("%s",&C);
	
	for(int i=0;i<N;i++){
		eq=0;
		if(A[i]==B[i])	eq++;
		if(B[i]==C[i])	eq++;
		if(A[i]==C[i])	eq++;
		
		if(eq==0)	count+=2;
		if(eq==1)	count++;

	}
	
	printf("%d",count);
	
	return 0;
}