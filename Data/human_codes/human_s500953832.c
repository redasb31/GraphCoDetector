#include <stdio.h>

int main(void)
{
	int p, q;
	int residue[100];
	int n, n1;
	int i;

	while (scanf("%d%d", &p, &q) != EOF){
		n = 0;
		
		while (1){
			for (i = 0; i < n; i++){
				if (residue[i] == p){
					n1 = i;
					break;
				}
			}
			if (i != n){
				break;
			}

			residue[n++] = p;

			p *= 10;
			printf("%d", p / q);
			p %= q;

			if (p == 0){
				break;
			}
		}
		printf("\n");
		if (p != 0){
			for (i = 0; i < n; i++){
				if (i < n1){
					printf(" ");
				}
				else {
					printf("^");
				}
			}
			printf("\n");
		}
	}
	
	return (0);
}