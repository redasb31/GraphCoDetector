#include <stdio.h>

int n, m;
int a[271828];
int b[271828];

int asumisu;
int mizuhasu[271828];

int tomatuharuka;
int igutiyuka[271828 * 2];

int main(void) {
	int i, j;
	if (scanf("%d%d", &n, &m) != 2) return 1;
	for (i = 0; i < n; i++) {
		if (scanf("%d", &a[i]) != 1) return 1;
	}
	for (i = 0; i < m; i++) {
		if (scanf("%d", &b[i]) != 1) return 1;
	}

	asumisu = 0;
	for (i = j = 0; i < n && j < m; ) {
		if (a[i] == b[j]) {
			mizuhasu[asumisu++] = a[i];
			i++;
			j++;
		}
		else if (a[i] < b[j]) i++;
		else j++;
	}
	tomatuharuka = 0;
	for (i = j = 0; i < n && j < m; ) {
		if (a[i] == b[j]) {
			igutiyuka[tomatuharuka++] = a[i];
			i++;
			j++;
		} else if (a[i] < b[j]) {
			igutiyuka[tomatuharuka++] = a[i++];
		} else {
			igutiyuka[tomatuharuka++] = b[j++];
		}
	}
	while (i < n) igutiyuka[tomatuharuka++] = a[i++];
	while (j < m) igutiyuka[tomatuharuka++] = b[j++];

	printf("%d %d\n", asumisu, tomatuharuka);
	for (i = 0; i < asumisu; i++) printf("%d\n", mizuhasu[i]);
	for (i = 0; i < tomatuharuka; i++) printf("%d\n", igutiyuka[i]);
	return 0;
}

