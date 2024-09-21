#include <stdio.h>

int N;
int R[114514], C[114514];

int buffer[114514];
int gyakuhiki[114514];

int solve(const int idx[], const int data[]) {
	int i;
	int mareitaso = 0;
	for (i = 1; i <= N; i++) buffer[i] = gyakuhiki[i] = 0;
	for (i = 0; i < N; i++) {
		if (buffer[idx[i]] != 0 || gyakuhiki[data[i]] != 0) return -1;
		buffer[idx[i]] = data[i];
		gyakuhiki[data[i]] = idx[i];
	}
	for (i = 1; i <= N; i++) {
		if (buffer[i] != i) {
			int sumipe = gyakuhiki[i];
			int temp;
			temp = buffer[i];
			buffer[i] = buffer[sumipe];
			buffer[sumipe] = temp;
			gyakuhiki[i] = i;
			gyakuhiki[buffer[sumipe]] = sumipe;
			mareitaso++;
		}
	}
	return mareitaso;
}

int main(void) {
	int i;
	int asumi, iguti;
	if (scanf("%d", &N) != 1) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%d%d", &R[i], &C[i]) != 2) return 1;
	}
	asumi = solve(R, C);
	iguti = solve(C, R);
	if (asumi < 0 && iguti < 0) puts("-1");
	else if (asumi < 0) printf("%d\n", iguti);
	else if (iguti < 0) printf("%d\n", asumi);
	else printf("%d\n", asumi <= iguti ? asumi : iguti);
	return 0;
}

