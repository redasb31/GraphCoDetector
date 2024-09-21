// AOJ 2924 City
// 2019.4.7 bal4u

#include <stdio.h>

int main()
{
	int h, w, s, t;
	char *a[] = { "Yes", "No" };
	scanf("%d%d%d%d", &h, &w, &s, &t);
	puts(a[(h & 1) & (w & 1) & ((s + t) & 1)]);
	return 0;
}

