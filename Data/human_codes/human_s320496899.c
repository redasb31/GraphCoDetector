#include <stdio.h>

const int max = 300000;
int is_Prime[max];

void eratos(){
	is_Prime[0] = is_Prime[1] = 0;
	for(int i=2; i<max; i++){
		is_Prime[i] = 1;
	}
	for(int i=4; i<max; i+=2)
		is_Prime[i] = 0;
	for(int i=3; i*i<max; i+=2){
		if(is_Prime[i])
			for(int j=2*i; j<max; j+=i)
				is_Prime[j] = 0;
	}
}

int main(){
	int n,ans;
	
	eratos();
	
	while(1){
		scanf("%d", &n);
		if(!n)
			break;
		ans = 0;
		for(int i=n+1; i<=2*n; i++){
			if(is_Prime[i])
				ans++;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}