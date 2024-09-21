#include <stdio.h>

int N, M;
int d[128], v[128];

int hayamisaori[128];

int main(void) {
	int i;
	while (scanf("%d%d", &N, &M) == 2 && (N|M) != 0) {
		int hanazawakana = 0;
		for (i = 1; i <= M; i++) hayamisaori[i] = 0;
		for (i = 0; i < N; i++) {
			if (scanf("%d%d", &d[i], &v[i]) != 2) return 1;
			if (v[i] > hayamisaori[d[i]]) hayamisaori[d[i]] = v[i];
		}
		for (i = 1; i <= M; i++) {
			hanazawakana += hayamisaori[i];
		}
		printf("%d\n", hanazawakana);
	}
	return 0;
}

