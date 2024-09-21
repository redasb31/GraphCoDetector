// AOJ 1312: Where's Wally
// 2018.3.18 bal4u

#include <stdio.h>
#include <string.h>

typedef unsigned long long ull;

#define HB 3181
 
char tr[128];
char img[1005][1005], pat[105][105], rot[105][105];
ull  imghash[1005][1005], pathash[8];
char buf[200];

int main()
{
	int  w, h, p, r, c, i, j, ans;
	ull  hbr, hbc, s;
	char *q, ch;

	for (i = 'A'; i <= 'Z'; i++) tr[i] = i-'A';
	for (i = 'a'; i <= 'z'; i++) tr[i] = i-'a'+26;
	for (i = '0'; i <= '9'; i++) tr[i] = i-'0'+52;
	tr['+'] = 62, tr['/'] = 63;

	while (fgets(q=buf, 20, stdin) && *q != '0') {
		sscanf(q, "%d%d%d", &w, &h, &p);
		hbr = 1; for (i = 0; i < p; i++) hbr *= HB;
		hbc = 1; for (i = 0; i < p; i++) hbc *= hbr;

		memset(img, 0, sizeof(img));
		for (r = 0; r < h; r++) {
			fgets(q=buf, 200, stdin);
			for (c = 0; *q >= ' '; c+=6) {
				ch = tr[*q++];
				for (j = 5; j >= 0; j--) if (ch & (1<<(5-j))) img[r][c+j] = 1;
			}
		}

		memset(pat, 0, sizeof(pat));
		for (r = 0; r < p; r++) {
			fgets(q=buf, 200, stdin);
			for (c = 0; *q >= ' '; c+=6) {
				ch = tr[*q++];
				for (j = 5; j >= 0; j--) if (ch & (1<<(5-j))) pat[r][c+j] = 1;
			}
		}

		for (i = 0; i < 8; i++) {
			memcpy(rot, pat, sizeof(pat));
			for (r = 0; r < p; r++) for (c = 0; c < p; c++) pat[p-c-1][r] = rot[r][c];
			if (i == 4) {
				memcpy(rot, pat, sizeof(pat));
				for (r = 0; r < p; r++) for (c = 0; c < p; c++)	pat[r][p-c-1] = rot[r][c];
			}
			pathash[i] = 0;
			for (r = 0; r < p; r++) for (c = 0; c < p; c++)	pathash[i] = pathash[i]*HB + pat[r][c];
		}

		for (r = 0; r < h; r++) {
			s = 0; for (c = 0; c < w; c++) {
				s = s*HB + img[r][c];
				if (c >= p) s -= hbr * img[r][c-p];
				imghash[r][c] = s;
			}
		}

		ans = 0;
		for (c = p-1; c < w; c++) {
			s = 0;
			for (r = 0; r < h; r++) {
				s = s*hbr + imghash[r][c];
				if (r >= p)	s -= hbc * imghash[r-p][c];
				if (r >= p-1) {
					for (i = 0; i < 8; i++) if (pathash[i] == s) { ans++; break; }
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
