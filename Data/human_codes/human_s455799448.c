#include <stdio.h>
#include <string.h>

#define L 50

int main() {
	static int aa[26];
	int n, c;

	scanf("%d", &n);
	memset(aa, L + 1, sizeof aa);
	while (n--) {
		static char s[L + 1];
		static int kk[26];
		int l, i;

		scanf("%s", s);
		l = strlen(s);
		memset(kk, 0, sizeof kk);
		for (i = 0; i < l; i++)
			kk[s[i] - 'a']++;
		for (c = 0; c < 26; c++)
			if (aa[c] > kk[c])
				aa[c] = kk[c];
	}
	for (c = 0; c < 26; c++)
		while (aa[c]--)
			printf("%c", c + 'a');
	printf("\n");
	return 0;
}
