// AOJ 2845: Star in Parentheses
// 2017.11.23 bal4u@uu

#include <stdio.h>

char buf[102];

int main()
{
	int ans;
	char *p;

	scanf("%s", p=buf);
	ans = 0;
	while (*p != '*') {
		if (*p == '(') ans++;
		else if (*p == ')') ans--;
		p++;
	}
	printf("%d\n", ans);
	return 0;
}