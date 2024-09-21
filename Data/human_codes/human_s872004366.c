#include <stdio.h>

#define MAX 15

int guchoku(const int *start, const int *goal, int num) {
	int status[MAX];
	int i, j;
	int count = 0;
	for (i = 0; i < num; i++) {
		status[i] = start[i];
	}
	for (i = 0; i < num; i++) {
		if (status[i] != goal[i]) {
			for (j = i + 1; j < num; j++) {
				if (status[j] == goal[i]) break;
			}
			if (j >= num) return MAX * MAX + 10;
			for (; j > i; j--) {
				int temp = status[j];
				status[j] = status[j - 1];
				status[j - 1] = temp;
				count++;
			}
		}
	}
	return count;
}

int main(void) {
	int N, M;
	int b[MAX];
	int p[MAX];
	int target[MAX];
	int start, current, phase, left;
	int i;
	int answer = -1, candidate;
	if (scanf("%d%d", &N, &M) != 2) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%d", &b[i]) != 1) return 1;
	}
	for (i = 0; i < M; i++) {
		if (scanf("%d", &p[i]) != 1) return 1;
	}
	for (start = 0; start <= 1; start++) {
		current = start;
		phase = 0;
		left = p[0];
		for (i = 0; i < N; i++) {
			target[i] = current;
			left--;
			if (left <= 0) {
				current = 1 - current;
				phase++;
				left = p[phase];
			}
		}
		candidate = guchoku(b, target, N);
		if (answer < 0 || candidate < answer) answer = candidate;
	}
	printf("%d\n", answer);
	return 0;
}