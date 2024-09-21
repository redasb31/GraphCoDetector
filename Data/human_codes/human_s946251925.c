#include <stdio.h>

int main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int min = a + b;
	
	if(min > b + c) min = b + c;
	if(min > a + c) min = a + c;
	
	printf("%d\n", min);
}