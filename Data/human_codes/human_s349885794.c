#include <stdio.h>

int tront[12][12];

void check(int x, int y);

int main(void) {
	int i, j;
	int c;
	int count = -1;
	while (1) {
		if (count != -1 && getchar() == EOF)
			break;
		count = 0;
		for (i = 0; i < 12; i++) {
			for (j = 0; j < 13; j++) {
				if ((c = getchar()) != '\n')
					tront[i][j] = c - '0';
			}
		}
		for (i = 0; i < 12; i++) {
			for (j = 0; j < 12; j++) {
				if (tront[i][j] == 1) {
					check(j, i);
					printf("%d %d\n", j, i);
					count++;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}

void check(int x, int y) {
	tront[y][x] = 2;
	if (x - 1 >= 0 && tront[y][x-1] == 1)
		check(x-1, y);
	if (x + 1 < 12 && tront[y][x+1] == 1)
		check(x+1, y);
	if (y - 1 >= 0 && tront[y-1][x] == 1)
		check(x, y-1);
	if (y + 1 < 12 && tront[y+1][x] == 1)
		check(x, y+1);
}