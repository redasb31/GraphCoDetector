#include <stdio.h>

#define N 100001

int main(void)
{
	int i;
	int n, l;
	int turara[N];
	int nextTurara[N];
	int f_check;
	int count = 0;
	
	scanf("%d %d", &n, &l);
	
	for (i = 0; i < n; i++){
		scanf("%d", turara + i);
	}
	
	do {
		f_check = 0;
		
		for (i = 0; i < n; i++){
			int flag = 1;
			
			nextTurara[i] = turara[i];
			
			if (i != n - 1){
				if (turara[i] < turara[i + 1]) flag = 0;
			}
			if (i != 0){
				if (turara[i] < turara[i - 1]) flag = 0;
			}
			
			if (flag == 1 && turara[i] != 0){
				nextTurara[i]++;
				
				if (nextTurara[i] >= l) nextTurara[i] = 0;
			}
		}
		
		for (i = 0; i < n; i++){
			turara[i] = nextTurara[i];
			if (turara[i] != 0) f_check = 1;
		}
		count++;
		
	} while (f_check == 1);
	
	printf("%d\n", count);
	
	return (0);
}