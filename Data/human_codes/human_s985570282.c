#include <stdio.h>

int main()
{
	int i, N, A[100001];
	long long sum = 0;
	scanf("%d", &N);
	for (i = 0; i <= N; i++) {
		scanf("%d", &(A[i]));
		sum += A[i];
	}
	if (A[0] > 0) {
		printf("-1\n");
		fflush(stdout);
		return 0;
	}
	
	long long tmp = 1, ans = 1;
	for (i = 1; i <= N; i++) {
		tmp = (tmp * 2 < sum)? tmp * 2: sum;
		ans += tmp;
		if (A[i] <= tmp) {
			tmp -= A[i];
			sum -= A[i];
		} else break;
	}
	
	if (i > N) printf("%lld\n", ans);
	else printf("-1\n");
	fflush(stdout);
	return 0;
}