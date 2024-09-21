#include <stdio.h>
#define J(A) (A<0?A*-1:A)
#define SIZE 31

int N;
long long out, D, MON[SIZE], PER[SIZE];

long  long a(int i,long long mon0,long long per0, long long mon1, long long per1) {
	if (i == N) {
		if (J(mon0-mon1) > D) return -1;
		if (out < (per1-per0)) {
			out = per1-per0;
		}// printf("%d\n", per1-per0);
		return per1-per0;
	}
	a(i+1,mon0+MON[i],per0+PER[i],mon1,per1);
	a(i+1,mon0,per0,mon1+MON[i],per1+PER[i]);
	a(i+1,mon0,per0,mon1,per1);
	return 0;
}

int main() {
	int i;
	scanf("%d%lld", &N, &D);
	for (i=0; i < N ;i++) {
		scanf("%lld%lld", &MON[i], &PER[i]);
	}
	out = 0;
	a(0,0,0,0,0);
	printf("%lld\n", out);
	return 0;
}