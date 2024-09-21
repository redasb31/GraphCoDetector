// AOJ 2800: Mod!Mod!
// 2017.8.8 bal4u@uu
// 2017.11.20

#include <stdio.h>
#include <stdlib.h>

int c[3];
char buf[1000002], *p;
int tr[10] = { 0,1,2,0,1,2,0,1,2,0 }; 

int main()
{
	int n;
	int i, a, b;
	
	fgets(buf, 10, stdin), n = atoi(buf);
	fgets(p=buf, 1000002, stdin);
	for (i = 0; i < n; i++) c[tr[*p & 0xf]]++, p += 2;
	if (!c[1] && !c[2]) a = 1;
	else {
		a = c[0]; n -= c[0];
		if (n <= 3) a += n;
		else {
			b = c[1] - c[2]; 
			if      (b ==  0) a += 2 * c[1];
			else if (b ==  1) a += 2 * c[2] + 1;
			else if (b ==  2) a += 2 * c[2] + 2;
			else if (b >   2) a += 2 * c[2] + 3;
			else if (b == -1) a += 2 * c[1] + 1;
			else if (b == -2) a += 2 * c[1] + 2;
			else if (b <  -2) a += 2 * c[1] + 3;
		}
	}
	printf("%d\n", a);
	return 0;
}