#include <stdio.h>

void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

int main(void)
{
	int n, m;
	int q[100000][2];
	int i;
	int edge = 0;
	
	/* ----- input ----- */
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++){
		scanf("%d %d", &q[i][0], &q[i][1]);
		
		if(q[i][0] > q[i][1])
			swap(&q[i][0], &q[i][1]);
	}
	
	/* ----- to do ----- */
	for(i=0; i<n; i++)
		edge += q[i][1]-q[i][0];
	
	/* ----- output ----- */
	if(edge%(n-1) != 0)
		printf("NO\n");
	else
		printf("YES\n");
	
	return 0;
}
