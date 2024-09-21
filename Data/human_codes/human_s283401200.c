#include <stdio.h>

int main(void)
{
	int i, N, T, A, ok;
	long long int Tsum, Asum;
	scanf("%d", &N);

	scanf("%lld%lld", &Tsum, &Asum);
	for (i = 1; i < N; i++) {
		scanf("%d%d", &T, &A);
		if (Asum % A == 0 && Asum / A * T == Tsum) continue;
		ok = 0;
		while (ok == 0) {
			// とりあえずTかAが1の場合は別の処理
			if (T == 1) {
				if (Tsum * A >= Asum)
					Asum = Tsum * A;
				else {
					if (Asum % A != 0)
						Asum = (Asum / A + 1) * A;
					Tsum = Asum / A;
				}
				ok = 1;
			} else if (A == 1) {
				if (Asum * T >= Tsum)
					Tsum = Asum * T;
				else {
					if (Tsum % T != 0)
						Tsum = (Tsum / T + 1) * T;
					Asum = Tsum / T;
				}
				ok = 1;
			} else if (Tsum / T > Asum / A) {
				// 比を満たしているならば
				if (Tsum * A % T == 0 && Tsum / T * A >= Asum) {
					Asum = Tsum / T * A;
					ok = 1;
				} else
					Tsum = (Tsum / T + 1) * T;
			} else if (Tsum / T < Asum / A) {
				if (Asum * T % A == 0 && Asum / A * T >= Tsum) {
					Tsum = Asum / A * T;
					ok = 1;
				} else
					Asum = (Asum / A + 1) * A;
			}
		}
	}

	printf("%lld", Tsum + Asum);
	return 0;
}