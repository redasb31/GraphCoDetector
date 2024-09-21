#include <stdio.h>
int main() {
	int a = 0;
	int d = 0;
	int e = 0;
	float b[21];
	float c[21];
    float count = 0;
	scanf("%d", &a);
	scanf("%d", b);
	scanf("%d", c);
  

	for (int i = 0; i<a; i++) {
        count = b[i]/c[i];
        float one = 1.0;
		if (count >= one) {
			d += int(b[i]);
			e += int(c[i]);
		}
	}
	int ans = 0;
    ans = d - e;
	printf("%d", ans);
	return 0;
}
