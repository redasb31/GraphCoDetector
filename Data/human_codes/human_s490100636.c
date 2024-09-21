/*

0576: homework

*/

#include <stdio.h>


int main(void){
	
	int n, a, b, c, d;
	
	scanf("%d", &n);
	
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);
	
	while(a > 0 || b > 0){
		
		a -= c;
		b -= d;
		n--;
		
	}
	
	printf("%d\n", n);
	
	
}