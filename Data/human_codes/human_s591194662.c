#include <stdio.h>

int H,W;

char field[10][10];

int main() {

	scanf("%d %d",&H,&W);

	int i,j;

	for (i = 0; i < H; i++) {
		scanf("%s", field[i]);

	}
	int ans = 0;
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			if (field[i][j] == '#') { ans++; }
		}
	}
	if (ans == H + W - 1) { printf("Possible\n"); }
	else { printf("Impossible\n"); }

	return 0;
}