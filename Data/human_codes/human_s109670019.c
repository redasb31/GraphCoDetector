#include "stdio.h"
#include "climits"

int i = 0;
int j = 0;
int far;
int retu[100000];
int trynum;
int getnum[100000];
int num[100000];
int start;
int min();
int box;
int little;
int prev;
int startbox;
int cal;


int main() {

	scanf("%d", &far);
	scanf("%d", &trynum);
	for (i = 0; i < trynum; i++) {
		scanf("%d", &getnum[i]);
	}
	start = 0;
	startbox = 0;
	prev = 0;
	for (i = 0; i < min(); i++) {
		if (i >= 100000) {
			num[i % 100000]++;
		}
		num[i]++;
	}
	little = min();
	printf("%d\n\n", little);
	if (little >= 100000)little = 100000;
	prev = min();;
	start = startbox + 1 ;
	while (start != trynum) {
			for (i = 0; i < little; i++) {
				num[i] *= (min() / prev);
			}
			cal = min() % prev;
			for (i = 0; i < cal; i++) {
				num[i%little]++;
			}
			prev = min();
			start = startbox+1;
	}
	for (i = 0; i < far; i++) {
		printf("%d\n",num[i]);
	}
	



	return 0;

}

int min() {
	box = INT_MAX;
	for (j = start; j < trynum; j++) {
		if (getnum[j] < box) {
			box = getnum[j];
			startbox = j;
		}
	}
	return box;
}