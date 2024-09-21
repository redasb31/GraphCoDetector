#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

int main(void) {
	int h, w;
	char s[2001][2001] = { 0 };
	int left, temp, top;
	int s_cnt[2001][2001] = { 0 };
	int max = 0;

	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) scanf("%s", s[i]);

	for (int i = 0; i < h; i++) {
		left = 0, temp = 0;
		for (int j = left; j <= w; j++) {
			if (s[i][j] == '.') {
				temp++;
			}
			else {
				for (int k = left; k < j; k++) s_cnt[i][k] = temp;
				left = j + 1;
				temp = 0;
			}
		}
	}

	for (int i = 0; i < w; i++) {
		top = 0, temp = 0;
		for (int j = top; j <= h; j++) {
			if (s[j][i] == '.') {
				temp++;
			}
			else {
				for (int k = top; k < j; k++) s_cnt[k][i] += temp;
				top = j + 1;
				temp = 0;
			}
		}
	}
	/*
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) printf("%d ", s_cnt[i][j]);
		printf("\n");
	}
	*/
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (max < s_cnt[i][j])max = s_cnt[i][j];
		}
	}
	printf("%d", max - 1);
	return 0;
}
