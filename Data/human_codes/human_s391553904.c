#include <stdio.h>

int main()
{
	int a[4], b[4], i, j, hit, blow;

	while(scanf("%d %d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &b[0], &b[1], &b[2], &b[3]) != EOF){
		hit = 0;
		blow = 0;

		for(i = 0; i < 4; i++){
			for(j = 0; j < 4; j++){
				if(a[i] == b[j]) blow++;
			}
		}

		for(i = 0; i < 4; i++){
			if(a[i] == b[i]) {hit++; blow--;}
		}

		printf("%d %d\n", hit, blow);
	}

	return 0;
}