#include <stdio.h>

int wher[1000 * 1000]; // 0-indexed!! n = wa+b
int caru[1000 * 1000]; // 0-indexed!!
int roofer[1000 * 1000];

int h, w;

void deb(){
	int i;
	for (i = 0; i < h * w; i++) {
		printf("%d: %d\n", i, roofer[i]);
	}
	return;
}

int findes(int i, int j, int dest) {
	if (i < j || dest == -1 || dest == roofer[j]) return dest;

	if (dest == i) {
		return roofer[j];
	} else {
		return -1;
	}
}

int solve(){
	int i;
	int result = 0;	
	for (i = 0; i < h * w; i++) {
		int ih, iw, dest = i;
		ih = wher[i] / w;
		iw = wher[i] % w;
			// printf("%2d: ", i);
		if (ih > 0) {
			int j = caru[wher[i] - w];
			dest = findes(i, j, dest);
		}
			// printf("%2d ", dest);
		if (ih < h-1) {
			int j = caru[wher[i] + w];
			dest = findes(i, j, dest);
		}
			// printf("%2d ", dest);
		if (iw > 0) {
			int j = caru[wher[i] - 1];
			dest = findes(i, j, dest);
		}
			// printf("%2d ", dest);
		if (iw < w-1) {
			int j = caru[wher[i] + 1];
			dest = findes(i, j, dest);
		}
			// printf("%2d\n", dest);
		roofer[i] = dest;
		if (dest == -1) result++;
	}

	// deb();

	return (int)printf("%d\n", result);
}

int main(void){
	int i;
	scanf("%d%d", &h, &w);
	for (i = 0; i < h * w; i++) {
		int x;
		scanf("%d", &x);
		wher[x - 1] = i;
		caru[i] = x - 1;
	}
	solve();
	return 0;
}