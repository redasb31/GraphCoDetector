// AOJ 1075: High and Low Cube
// 2017.11.21 bal4u@uu

#include <stdio.h>
#include <string.h>

char buf[21][60];
int pos[6][2] = {{0,7},{7,0},{7,7},{7,14},{7,21},{14,7}};
char dice[2][6][7][7];
int a[2][6];
int digit[10] = { 0, 0x80084, 0x4084804, 0x4084084, 0x884080, 0x4804084, 0x4804884,
				     0x4080080, 0x4884884, 0x4884084 };

void lr(int k, int i)
{
	int r, c;
	char buf[7];
	for (r = 0; r < 7; r++) {
		memcpy(buf, dice[k][i][r], 7);
		for (c = 0; c < 7; c++) dice[k][i][r][c] = buf[6-c];
	}
}

void ud(int k, int i)
{
	int r, c;
	char buf[7];
	for (c = 0; c < 7; c++) {
		for (r = 0; r < 7; r++) buf[r] = dice[k][i][r][c];
		for (r = 0; r < 7; r++) dice[k][i][r][c] = buf[6-r];
	}
}

void rot(int k, int i)
{
	int r, c;
	char t, buf[7][7];
	for (r = 0; r < 7; r++) for (c = 0; c < 7; c++) {
		t = dice[k][i][r][c];
		if      (t == '|') t = '-';
		else if (t == '-') t = '|';
		buf[c][6-r] = t;
	}
	for (r = 0; r < 7; r++) memcpy(dice[k][i][r], buf[r], 7);
}

int parse(int k, int i)
{
	int j, r, c, s;
	for (s = 0, r = 1; r < 6; r++) for (c = 2; c < 5; c++) {
		s <<= 2;
		if      (dice[k][i][r][c] == '-') s |= 1;
		else if (dice[k][i][r][c] == '|') s |= 2;
	}
	for (j = 1; j < 10; j++) if (digit[j] == s) break;
	return j;
}

int main()
{
	int i, j, k, r, x, ans;

	while (fgets(buf[0], 60, stdin) && *buf[0] != '0') {
		for (i = 1; i < 21; i++) fgets(buf[i], 60, stdin);
		for (x = 0, k = 0; k < 2; k++, x = 29) {
			for (i = 0; i < 6; i++) for (r = 0; r < 7; r++)
				memcpy(dice[k][i][r], &buf[r+pos[i][0]][x+pos[i][1]], 7);
		}

		for (k = 0; k < 2; k++) {
			for (i = 0; i < 6; i++) {
				if (i == 0 || i == 2 || i == 4) lr(k, i);
				else if (i == 1) rot(k, i), lr(k, i);
				else if (i == 3) rot(k, i), rot(k, i), rot(k, i), lr(k, i);
				else if (i == 5) lr(k, i), ud(k, i);
				a[k][i] = parse(k, i);
			}
		}

		ans = 0;
		for (i = 0; i < 6; i++) for (j = 0; j < 6; j++) {
			if      (a[0][i] > a[1][j]) ans++;
			else if (a[0][i] < a[1][j]) ans--;
		}
		puts(ans < 0 ? "LOW" : "HIGH");
	}
	return 0;
}