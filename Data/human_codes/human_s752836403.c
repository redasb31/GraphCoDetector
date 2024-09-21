// AOJ 1296: Repeated Substitution with Sed
// 2017.10.20 bal4u@uu

#include <stdio.h>
#include <string.h>

typedef struct { char x[11], s, k; } Q;
Q que[10002]; int top, end;
char a[10][11], sa[10];
char b[10][11], sb[10];
char g[11], sg;

int main()
{
	int n, i, s, k, w, f, ans;
	char *p, *q;

	while (scanf("%d", &n) && n > 0) {
		for (i = 0; i < n; i++) {
			scanf("%s%s", a[i], b[i]);
			sa[i] = strlen(a[i]), sb[i] = strlen(b[i]);
		}
		scanf("%s%s", que[0].x, g), sg = strlen(g);

		ans = -1, que[0].k = 0, que[0].s = strlen(que[0].x), top = 0, end = 1;
		while (top < end) {
			for (i = 0; i < n; i++) {
				p = que[top].x, s = que[top].s, k = que[top].k + 1, q = que[end].x, f = 0;
				while (*p) {
					if ((p-que[top].x) + sa[i] <= s && !memcmp(p, a[i], sa[i])) {
						if ((q-que[end].x) - sa[i] + sb[i] > sg) goto next;
						memcpy(q, b[i], sb[i]);
						p += sa[i], q += sb[i], f = 1;
					} else *q++ = *p++;
				}
				if (!f) continue;
				*q = 0;	if ((w = q - que[end].x) == sg) {
					if (memcmp(que[end].x, g, sg) == 0) { ans = k; goto done; }
				} else que[end].s = w, que[end++].k = k;
next:			;
			}
			top++;
		}
done:	printf("%d\n", ans);
	}
	return 0;
}