// AOJ 1564: String Compression
// 2017.10.24 bal4u@uu

#include <stdio.h>

char s[102], *p;
int f['z'+1];

int main() 
{
	int i, j, w, ans;

	scanf("%s", s); 
	p = s; while (*p) f[*p++]++;
	w = p - s;
	
	p = s;
	do for (j = 0, i = '0'; i <= '9'; i++) if (f[i] > 0) j = 1, *p++ = i, f[i]--;
	while (j);
	do for (j = 0, i = 'a'; i <= 'z'; i++) if (f[i] > 0) j = 1, *p++ = i, f[i]--;
	while (j);

	ans = w;
	for (i = 0; i < w; i = j) {
		for (j = i+1; s[j] == s[j-1]+1; j++);
		if (j - i > 3) ans -= j - i - 3;
	}
	printf("%d\n", ans);
	return 0;
}