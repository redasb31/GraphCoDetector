/*

*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int a,b;
	for(a=1; a<=9; a++){
		for(b=1; b<=9; b++){
			printf("%dx%d=%d\n",a,b,a*b);
		}
	}
	return 0;
}