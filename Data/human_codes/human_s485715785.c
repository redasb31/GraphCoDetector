#include <stdio.h>
int main(void)
{
	int N;
	scanf("%d",&N);
	if(N>=0 && N<=127){
		if(N>=65 && N<=90)
			printf("1\n");
		else if(N>=97 && N<=122)
printf("2\n");
		else{
			printf("0\n");
		}
	}
	return 0;
}

