// AOJ 2758:  Sendame
// 2017.10.10 bal4u@uu

#include <stdio.h>

#define MAMORU 0
#define TAMERU 1
#define KOGEKI 2

char a[2][102];
char tr['z'];

int main()
{
	int k, i, j, p[2], ans;
	char buf[13], *s[] = { "Hikiwake-kun", "Isono-kun", "Nakajima-kun" };

	tr['m'] = MAMORU, tr['t'] = TAMERU, tr['k'] = KOGEKI;
	scanf("%d", &k);
	for (j = 0; j < 2; j++) for (i = 0; i < k; i++) {
		scanf("%s", buf);
		a[j][i] = tr[*buf];
	}
	ans = -1, p[0] = p[1] = 0;
	for (i = 0; i < k; i++) {
		for (j = 0; j < 2; j++) if (a[j][i] == KOGEKI) {
			if (p[j] == p[!j] && a[!j][i] == KOGEKI) continue;
			if (p[j] == 0) { ans = !j; goto FIN; }
			if (a[!j][i] == TAMERU || p[j] > p[!j] && a[!j][i] != MAMORU ||
				p[j] == 5 && a[!j][i] == MAMORU) { ans = j; goto FIN; }
		}
		for (j = 0; j < 2; j++) {
			if (a[j][i] == KOGEKI) p[j] = 0;
			else if (a[j][i] == TAMERU) { if (++p[j] > 5) p[j] = 5; }
		}
	}
FIN:puts(s[1+ans]);
	return 0;
}