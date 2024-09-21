#include <stdio.h>
#include <math.h>
typedef long long LL;

int main() 
{
	LL p, q, k, i, t, s, x, y;
	
	scanf("%lld%lld", &p, &q);
	if(q > p){
		puts("-1");
		return 0;
	}
	if(q == p){
		printf("%lld\n", p + 1);
		return 0;
	}
	for(i = 2, k = sqrt(p); i <= k; i++){
		t = p, s = 0;
		while(t){
			s += t % i;
			t /= i;
		}
		if(s == q){
			printf("%lld\n", i);
			return 0;
		}
	}
	for(t = p - q, i = sqrt(t); i > 0; i--){
		if(t % i) continue;
		x = t / i + 1;
		y = p - x * i;
		if(y >= 0 && y < x){
			printf("%lld\n", x);
			return 0;
		}
	}
	puts("-1");
	
	return 0;
}