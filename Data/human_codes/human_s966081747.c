#include<stdio.h>
#include<string>

int main(){
	int n, m, i, j, t, k;
	char a[111][111];
	while(~scanf("%d %d", &n, &m)){
		getchar();
		for(i = 0; i < n; i++)  { gets(a[i]); a[i][m] = '#'; }
		for(i = 0; i < m + 2; i++)  printf("#");
		printf("\n");
		for(i = 0; i < n; i++) { printf("#"); puts(a[i]); }
	    for(i = 0; i < m + 2; i++)  printf("#");
	    printf("\n");
	}
	return 0;
}