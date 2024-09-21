#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
int main(void){
	int a, b, c, d;
	fscanf(stdin, "%d%d%d%d", &a, &b, &c, &d);
	if ((a == b&&c == d) || (a == c&&b == d) || (a == d&&b == c)) puts("yes");
	else puts("no");
	return 0;
}