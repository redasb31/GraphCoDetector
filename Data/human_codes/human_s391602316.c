// AOJ 2840: Unique Subsequence
// 2017.10.10 bal4u@uu

#include <stdio.h>

char text[500005];
char pattern[500005];

int main()
{
	int f;
	char *p, *q;

	scanf("%s%s", text, pattern+1);
	p = text, q = pattern+1, f = 0;
	while (*p) {
		if (*p == *q) {	q++; if (!*q) f = 1; }
		else if (*p == *(q-1)) { f = 0; break; }
		p++;
	}
	puts(f ? "yes" : "no");
	return 0;
}