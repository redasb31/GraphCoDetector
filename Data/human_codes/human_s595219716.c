// AOJ 2297: Rectangular Stamps
// 2017.12.10 bal4u@uu

#include <stdio.h>
#include <string.h>

#define LIM 65535
#define MIN(a,b) ((a)<=(b)?(a):(b))
#define MAX(a,b) ((a)>=(b)?(a):(b))

int q[65540]; int top, end;
char enable[4][4][4][4];
char map[4][5];
int dist[65540];

int main()
{
	int n, h, w, r, c, r2, c2, i, s, t, rr, cc;
	char rgb[] = "RGB";

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &h, &w);
		for (r = 1-h; r < 4; r++) for (c = 1-w; c < 4; c++)
			enable[MAX(0, r)][MAX(0, c)][MIN(3, r+h-1)][MIN(3, c+w-1)] = 1;
	}

	for (r = 0; r < 4; r++) scanf("%s", map[r]);

	top = end = 0, q[end++] = 0;
	memset(dist, 0x11, sizeof(dist));
	dist[0] = 0;
	while (top < end) {
		s = q[top++];
		if (s == LIM) break;
		
		for (r = 0; r < 4; r++) for (c = 0; c < 4; c++) {
			for (r2 = r; r2 < 4; r2++) for (c2 = c; c2 < 4; c2++) if (enable[r][c][r2][c2]) {
				 for (i = 0; i < 3; i++) {
					t = s;
					for (rr = r; rr <= r2; rr++) for (cc = c; cc <= c2; cc++) {
						if (map[rr][cc] == rgb[i]) t |=   1 << ((rr << 2) + cc);
						else                       t &= ~(1 << ((rr << 2) + cc));
					}
					if (dist[s] + 1 < dist[t]) dist[t] = dist[s]+1, q[end++] = t;
				}
			}
		}
	}
	printf("%d\n", dist[LIM]);
	return 0;
}