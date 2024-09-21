#include <stdio.h>

int main(void){
	int N;
	int a[20000],b[20000];
	int p[20000];

	int i;
	
	scanf("%d",&N);
	for(i=0;i<N;i++){scanf("%d",&p[i]);}

	
	for(i=0;i<N;i++){
		a[i] = 20000*i;
		b[N-1-i] = 20000*i;
	}

	for(i=0;i<N;i++){
		a[i] += p[i];
	}

	for(i=0;i<N-1;i++){printf("%d ",a[i]);}
	printf("%d\n",a[N-1]);
	for(i=0;i<N-1;i++){printf("%d ",b[i]);}
	printf("%d\n",b[N-1]);

	return 0;
}