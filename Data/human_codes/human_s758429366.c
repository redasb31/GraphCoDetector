#include <stdio.h>
#include <math.h>

int main()
{
	int n, i, j, diff, d, s;
	scanf("%d", &n);

	s = 0;
	for (i = 31; i >= 1; i --) {
		diff = 0;
		for (j = 1; j < i; j ++) {
			diff += (int)pow(-2, j);
		}

		if (n % 2 == 1) {
			if (n + diff) {
				d = abs(n + diff) % (int)pow(2,i) >= (int)pow(2,i-1) ? 1 : 0;
			} else {
				d = abs(n + diff) % (int)pow(2,i) >= (int)pow(2,i-1) ? 0 : 1;
			}
		} else {
			if (n + diff) {
				d = abs(n + diff) % (int)pow(2,i) >= (int)pow(2,i-1) ? 0 : 1;
			} else {
				d = abs(n + diff) % (int)pow(2,i) >= (int)pow(2,i-1) ? 1 : 0;
			}
		}

		if (d == 1) {
			s = 1;
		}

		if (s == 1) {
			printf ("%d", d);
		}

		/*
		printf("%d,", diff);
		printf("%d,", (int)pow(2, i));
		printf("%d,", (int)pow(2, i-1));
		printf("\n");
		*/
	}

	/*
	if (  n + 2 >= 0) {
		printf("%d", abs(  n + 2) % 8 >= 4 ? 1 : 0);
	} else {
		printf("%d", abs(  n + 2) % 8 >= 4 ? 0 : 1);
	}
	if (  n - 2 >= 0) {
		printf("%d", abs(  n - 2) % 4 >= 2 ? 0 : 1);
	} else {
		printf("%d", abs(  n - 2) % 4 >= 2 ? 1 : 0);
	}
	if (  n - 0 >= 0) {
		printf("%d", abs(  n - 0) % 2 >= 1 ? 1 : 0);
	} else {
		printf("%d", abs(  n - 0) % 2 >= 1 ? 0 : 1);
	}
	*/

	return 0;
}
