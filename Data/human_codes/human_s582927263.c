// Aizu Vol-1 0126: Puzzle
// 2017.8.2

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *gets(char *);
char buf[200];

char a[9][9];
char ans[9][9];
char cnt[15];

void getData(int r)
{
	int c;
	char *p = buf;
	for (c = 0; c < 9; c++) {
		while (isspace(*p)) p++;
		a[r][c] = *p++ - '0', ans[r][c] = ' ';
	}
}

int main()
{
	int i, k, n, r, c, r2, c2, rr, cc;

	gets(buf);
	n = atoi(buf);
	for (i = 0; i < n; i++) {
		if (i > 0) putchar('\n');
		for (r = 0; r < 9; r++) {
			gets(buf);
			getData(r);
		}
		for (r = 0; r < 9; r++) {
			memset(cnt, 0, 10);
			for (c = 0; c < 9; c++) {
				k = a[r][c];
				if (!cnt[k]) cnt[k] = c + 1;
				else {
					ans[r][c] = '*';
					c2 = cnt[k] - 1;
					ans[r][c2] = '*';
				}
			}
		}
		for (c = 0; c < 9; c++) {
			memset(cnt, 0, 10);
			for (r = 0; r < 9; r++) {
				k = a[r][c];
				if (!cnt[k]) cnt[k] = r + 1;
				else {
					ans[r][c] = '*';
					r2 = cnt[k] - 1;
					ans[r2][c] = '*';
				}
			}
		}
		for (rr = 0; rr < 9; rr += 3) {
			for (cc = 0; cc < 9; cc += 3) {
				memset(cnt, 0, 10);
				for (r = 0; r < 3; r++) {
					for (c = 0; c < 3; c++) {
						k = a[rr+r][cc+c];
						if (!cnt[k]) cnt[k] = 3*r + c + 1;
						else {
							ans[rr + r][cc + c] = '*';
							r2 = (cnt[k] - 1) / 3, c2 = (cnt[k] - 1) % 3;
							ans[rr + r2][cc + c2] = '*';
						}
					}
				}
			}
		}

		for (r = 0; r < 9; r++) {
			for (c = 0; c < 9; c++) {
				putchar(ans[r][c]), putchar(a[r][c] + '0');
			}
			putchar('\n');
		}
	}
	return 0;
}