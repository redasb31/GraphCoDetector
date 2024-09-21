// AOJ Vol3-0393: Design of a Mansion
// 2018.12.25
 
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int H, A, B, i, ans;

	scanf("%d%d%d", &H, &A, &B);
	for (ans = 0, i = A; i <= B; i++)
		if (H % i == 0) ans++;
	printf("%d\n", ans);
	return 0;
}
