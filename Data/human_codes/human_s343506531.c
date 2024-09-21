#include<stdio.h>

int H, W, N, K;
int ans_map[50][50];

void check4s(int h, int w, int num) {
	int p;
	int c = 0;
	
	printf("? %d %d %d %d\n", h, w, h, w);
	scanf("%d", &p);
	ans_map[h][w] = p;
	c += p;
	if(c == num) return;
	
	printf("? %d %d %d %d\n", h, w+1, h, w+1);
	scanf("%d", &p);
	ans_map[h][w+1] = p;
	c += p;
	if(c == num) return;
	
	printf("? %d %d %d %d\n", h+1, w, h+1, w);
	scanf("%d", &p);
	ans_map[h+1][w] = p;
	c += p;
	if(c == num) return;
	
	ans_map[h+1][w+1] = 1;
}

void check4h(int h, int w, int num) {
	int i;
	int p;
	int c = 0;
	
	for(i=0;i<3;i++) {
		printf("? %d %d %d %d\n", h, w+i, h, w+i);
		scanf("%d", &p);
		ans_map[h][w+i] = p;
		c += p;
		if(c == num) return;
	}
	
	ans_map[h][w+3] = 1;
}

void check4v(int h, int w, int num) {
	int i;
	int p;
	int c = 0;
	
	for(i=0;i<3;i++) {
		printf("? %d %d %d %d\n", h+i, w, h+i, w);
		scanf("%d", &p);
		ans_map[h+i][w] = p;
		c += p;
		if(c == num) return;
	}
	
	ans_map[h+3][w] = 1;
}

void check25(int h, int w, int num) {
	int i, j;
	int p;
	int c = 0;
	
	for(i=0;i<2;i++) {
		for(j=0;j<2;j++) {
			printf("? %d %d %d %d\n", h+i*2, w+j*2, h+i*2+1, w+j*2+1);
			scanf("%d", &p);
			if(p > 0) {
				c += p;
				check4s(h+i*2, w+j*2, p);
				if(c == num) return;
			}
		}
	}
	
	printf("? %d %d %d %d\n", h+4, w, h+4, w+3);
	scanf("%d", &p);
	if(p > 0) {
		c += p;
		check4h(h+4, w, p);
		if(c == num) return;
	}
	
	printf("? %d %d %d %d\n", h, w+4, h+3, w+4);
	scanf("%d", &p);
	if(p > 0) {
		c += p;
		check4v(h, w+4, p);
		if(c == num) return;
	}
	
	ans_map[h+4][w+4] = 1;
}

int main() {
	int i, j;
	int p;
	int c = 0;
	long ans = 0;
	long pow = 1;
	
	scanf("%d %d %d %d", &H, &W, &N, &K);
	for(i=0;i<H;i++) {
		for(j=0;j<W;j++) {
			printf("? %d %d %d %d\n", i, j, i, j);
			scanf("%d", &p);
			ans_map[i][j] = p;
		}
	}
	
	for(i=0;i<H;i++) {
		for(j=0;j<W;j++) {
			if(ans_map[i][j]) ans += pow;
			pow *= 2;
			ans %= K;
			pow %= K;
		}
	}
	
	printf("! %ld\n", ans);
	
	return 0;
}