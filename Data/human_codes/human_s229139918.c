// AOJ 2657: Books
// 2017.11.16 bal4u@uu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { char t[52]; int lt; char a[52]; int la; int d; } T;
T book[101]; int n;

int nxt[100], nxa[100];
int kmpMatch(char *text, int len, char *pattern, int patlen, int *next)
{
    char *pp;
    char *textEnd, *patEnd;

    if (len < patlen) return 0;

    textEnd = text + len;
    patEnd  = pattern + patlen;

    pp = pattern;
    while (text != textEnd) {
        if (*text++ == *pp) pp++;
        else if (pp != pattern) {
            pp = pattern + *(next + (pp - pattern));
            text--;
        }
        if (pp == patEnd) return 1;
    }
    return 0;
}

int kmpNext(int *next, int nlen, char *pattern, int patlen)
{
    char *tp, *pp;
    char *patEnd;

    if (nlen < patlen) return -1;

    patEnd  = pattern + patlen;
    *next = 0;

    tp = pp = pattern;
    while (++tp != patEnd) {
        *(next + (tp - pattern)) = pp - pattern;
        if (*tp == *pp) pp++;
    }
    return 0;
}

int ymd2d(char *s)
{
	int y, m, d;
	y = atoi(s), m = atoi(s+5), d = atoi(s+8);
	return (((y << 4) + m) << 5) + d;
}

int main()
{
	int i, j, q, lt, la, from, to;
	char qt[52], qa[52], buf[15], bu2[15];
	T *t;

	scanf("%d", &n);
	for (t = book, i = 0; i < n; i++, t++) {
		scanf("%s%s%s", t->t, t->a, buf);
		t->lt = strlen(t->t), t->la = strlen(t->a), t->d = ymd2d(buf);
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		int ft, fa, fm, fo;
		ft = fa = fm = fo = 0;
		scanf("%s%s%s%s", qt, qa, buf, bu2);

		if (*qt == '*') ft = 1;
		else lt = strlen(qt), kmpNext(nxt, 100, qt, lt);

		if (*qa == '*') fa = 1;
		else la = strlen(qa), kmpNext(nxa, 100, qa, la);

		if (*buf == '*') fm = 1;
		else from = ymd2d(buf);

		if (*bu2 == '*') fo = 1;
		else to = ymd2d(bu2);

		if (i > 0) putchar('\n');
		for (t = book, j = 0; j < n; j++, t++) {
			int a = ft, b = fa, c = fm, d = fo;
			if (!a) a = kmpMatch(t->t, t->lt, qt, lt, nxt);
			if (!b) b = kmpMatch(t->a, t->la, qa, la, nxa);
			if (!c) c = (t->d >= from);
			if (!d) d = (t->d <= to);

			if (a&b&c&d) puts(t->t);
		}
	}
	return 0;
}