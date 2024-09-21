#include <stdio.h>

int N;
char yukati[16];

void sumipe(int asumi, int iguti) {
	if (asumi >= N) {
		yukati[asumi] = '\0';
		puts(yukati);
	} else {
		int i;
		for (i = 0; i <= iguti; i++) {
			yukati[asumi] = 'a' + i;
			sumipe(asumi + 1, iguti + (i >= iguti));
		}
	}
}

int main(void) {
	if (scanf("%d", &N) != 1) return 1;
	sumipe(0, 0);
	return 0;
}
