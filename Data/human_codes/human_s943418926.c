#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	long long int  n,a,b,memo;
	scanf("%lld%lld%lld", &n,&a,&b);
	memo = 0;
	if (b == 1 && a == n) {
		for (int i = 1; i <= n; i++) {
			printf("%lld ", i);
			memo--;
          
		}
		return 0;
	}
	else if (b == n && a == 1) {
		for (int i = 1; i <= n; i++) {
			printf("%lld ", memo);
			memo--;
          
		}
      	return 0;
	}
	else if (a == 1 || b == 1 || a == n || b == n||a+b>n+1||n/2>=a&&n/2>=b) { printf("-1"); return 0; }

	if (a >= b) {
		for (int i = n - a + 1; i <= n; i++) {
			printf("%lld ", i);

		}
		for (int i = b - 1; i <= n - a; i++) {
			printf("%lld ", i);
		}
		for (int i = b - 2; i >= 1; i--){
			printf("%lld ", i);
		}
	}
	else {
		for (int i = b; i >= 1; i--) {
			printf("%lld ", i);
		}
		for (int i = n-a+2; i >= b+1; i--) {
			printf("%lld ", i);
		}
		for (int i = n - a+3; i <= n; i++) {
			printf("%lld ", i);
		}
	}

}
