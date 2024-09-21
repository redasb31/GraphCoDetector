#include<stdio.h>

int game(int n, int p){
	int x[50]={0};
	int loop = 0;
	int stones = p;
	while(1){
		if(loop == n)
			loop = 0;
		if(stones > 0){
			x[loop]++;
			stones--;
			if(x[loop] == p)
				return loop;
		}
		else if(x[loop] != 0){
				stones = x[loop];
				x[loop] = 0;
		}
		loop++;
	}
}

int main(){
	int n, p;
	scanf("%d %d",&n ,&p);
	while((n!=0)||(p!=0)){
		printf("%d\n", game(n, p));
		scanf("%d %d",&n ,&p);
	}
	return 0;
}