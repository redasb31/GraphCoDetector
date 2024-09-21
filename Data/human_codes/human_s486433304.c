#include <stdio.h>

#define MOD_BY 1000000007

int add(int a, int b) {
	return a + b - MOD_BY * (a + b >= MOD_BY);
}

/* A:0 C:1 G:2 T:3 */

int memo[128][1 << 6];

int search(int left, int history) {
	int p = history & 3, pp = (history >> 2) & 3, ppp = (history >> 4) & 3;
	int answer = 0;
	if (left <= 0) return 1;
	if (memo[left][history]) return ~memo[left][history];

	/* A */
	answer = add(answer, search(left - 1, ((history << 2) | 0) & 0x3f));
	/* C */
	if (!(pp == 0 && p == 2) && !(ppp == 0 && p == 2) && !(pp == 2 && p == 0) && !(ppp == 0 && pp == 2)) {
		answer = add(answer, search(left - 1, ((history << 2) | 1) & 0x3f));
	}
	/* G */
	if (!(pp == 0 && p == 1)) {
		answer = add(answer, search(left - 1, ((history << 2) | 2) & 0x3f));
	}
	/* T */
	answer = add(answer, search(left - 1, ((history << 2) | 3) & 0x3f));

	return ~(memo[left][history] = ~answer);
}

int main(void) {
	int N;
	if (scanf("%d", &N) != 1) return 1;
	printf("%d\n", search(N, 0x3f));
	return 0;
}

/*

NG putterns

AGC
A*GC
GAC
ACG
AG*C

*/
