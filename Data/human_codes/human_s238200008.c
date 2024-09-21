#include<stdio.h>

int main(){
	int k;
	int i, x = 1;
	long long rnrn[100005] = {0};

	scanf("%d", &k);

	for(i=1; i<10; i++) rnrn[i] = (long long)i;
	while(1){
		if(i > k){
			break;
		}

		int j;
		for(j=-1; j<=1; j++){
			int d = rnrn[x] % 10 + j;

			if(d < 0 || d > 9){
				continue;
			}

			rnrn[i] = rnrn[x]*10 + d;
			i++;
		}
		x++;
	}

	printf("%lld", rnrn[k]);
	return 0;
}
