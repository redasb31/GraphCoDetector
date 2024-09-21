#include<stdio.h>
int main(){
	int ans = 0;
	int N;
	scanf("%d",&N);
	int A[N];
	int i = 0;
	for(i=0 ; i<N ; i++){
		scanf("%d",&A[i]);
	}
	ans += A[0]-1 ;
	int r = 2;
	for(i = 1; i<N ; i++)
	{
		if(A[i] != r){
			ans += (A[i]-1)/r ;
		}
		else
			r++;
	}
	printf("%d\n",ans);
	return 0;
}