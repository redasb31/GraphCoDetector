#include <stdio.h>

int main(int argc, char** argv)
{
	long long x, money = 100LL;
	scanf("%I64d", &x);
	int y = 0;
	for(; money<x; y++, money+=money/100);
	printf("%d\n", y);
	return 0;
}