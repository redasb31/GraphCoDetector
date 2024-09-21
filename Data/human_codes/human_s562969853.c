#include <stdio.h>
typedef long double ld;
int main(){
	ld v;
	while(scanf("%Lf",&v)!=EOF){
		ld t=v/9.8;
		ld h=4.9*t*t;
		int n=(h+4.0)/5.0+1.0;
		printf("%d\n",n);
	}
	return 0;
}