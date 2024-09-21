#include <stdio.h>

int main(void)
{
	char r[8], a[8];
	
	while (scanf("%s %s", r, a) * r[1] != 0){
		int i, j;
		int hit, blow;
		
		hit = blow = 0;
		for (i = 0; i < 4; i++){
			for (j = 0; j < 4; j++){
				if (r[i] == a[j]){
					i == j ? hit++ : blow++;
				}
			}
		}
		printf("%d %d\n", hit, blow);
	}
	
	return 0;
}