#include <stdio.h>
#include <stdlib.h>
#define abs(a,b) ((a)>(b)? (a)-(b) : (b)-(a))

int beauty=0;
int cnt=0;

void calc(long int *array, long int pos, long int n, long int m, long int d){
	long int i;
	if(pos==m){
		int b=0;
		for(i=0;i<m-1;i++){
			if(abs(array[i],array[i+1])==d) b++;
		}
		printf("%d:beauty=%d\n",cnt,b);
		beauty+=b;
		cnt++;
	}else{
		for(i=1;i<=n;i++){
			array[pos]=i;
			calc(array,pos+1,n,m,d);
		}
	}
}

int main(void) {
	long int n,m,d;
	scanf("%ld %ld %ld",&n,&m,&d);
	printf("%ld %ld %ld\n",n ,m,d);
	long int *array;
	array=malloc(sizeof(long int)*m);
	calc(array,0,n,m,d);
	free(array);
	printf("%f\n",(double)beauty/cnt);
	return EXIT_SUCCESS;
}