// AOJ 1620 Boolean Expression Compressor
// 2018.2.12 bal4u

#include <stdio.h>
#include <string.h>

typedef struct { char w; int p; } TBL;
TBL tbl[1 << 16];
char w[3000], exp[3000][17]; int top, end;
char buf[20], *p;

int eval()
{
	int f;
	char c = *p; if (*p) p++;
	if      (c == '0') return 0;
	else if (c == '1') return 0xffff;
	else if (c == 'a') return 0xff00;
	else if (c == 'b') return 0xf0f0;
	else if (c == 'c') return 0xcccc;
	else if (c == 'd') return 0xaaaa;
	else if (c == '-') {
		f = 1; while (*p == '-') f = !f, p++; 
		if (f) return (~eval()) & 0xffff;
		else   return eval();
	}
	else if (c == '(') {
		int y, x = eval();
		if (*p++ == '^') { y = eval(); p++;	return x ^ y; }
		else             { y = eval(); p++;	return x & y; }
	}
	return 0;
}

void insert(char *s, int sz)
{
    int id;

	p = s, id = eval();
	if (sz < tbl[id].w) w[tbl[id].p] = 0, tbl[id].w = 0;
	if (tbl[id].w == 0) {
		tbl[id].w = sz, tbl[id].p = end;
		w[end] = sz, memcpy(exp[end++], s, sz);
	}
}

void mktbl()
{
	int i, _end;
	char buf[100], *p, *q;

	insert("0", 1), insert("1", 1);
	insert("a", 1), insert("b", 1), insert("c", 1), insert("d", 1);

	while (top < end) {
		for (_end = end; top < _end; top++) {
			if (w[top] == 0) continue;
				
			if (w[top] > 15) continue;
			if (*exp[top] != '-') {
				q = buf;
				*q++ = '-', p = exp[top]; while (*p) *q++ = *p++; *q = 0;
				insert(buf, q-buf);
			}

			if (w[top] > 13) continue;
			for (i = 0; i < _end; i++) {
				if (w[i] == 0 || w[i] + w[top] > 13) continue;

				q = buf;
				*q++ = '(', p = exp[top]; while (*p) *q++ = *p++;
				*q++ = '^', p = exp[i];   while (*p) *q++ = *p++;
				*q++ = ')', *q = 0;
				insert(buf, q-buf);

				q = buf;
				*q++ = '(', p = exp[top]; while (*p) *q++ = *p++;
				*q++ = '*', p = exp[i];   while (*p) *q++ = *p++;
				*q++ = ')', *q = 0;
				insert(buf, q-buf);
			}
		}
	}
}

int main()
{
	mktbl();
	//printf("end %d\n", end);	// end = 2604

	while (fgets(p=buf, sizeof(buf), stdin) && *p != '.') {
		printf("%d\n", tbl[eval()].w);
	}
	return 0;
}

