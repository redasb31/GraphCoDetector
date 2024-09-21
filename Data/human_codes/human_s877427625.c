#include <stdio.h>
#include <string.h>

#define UP		(0)
#define DOWN	(1)

int main(void)
{
	int c;
	int N;
	int matrix[12][12];
	int x, y;
	int n;
	int direc;
	
	c = 1;
	while (1){
		scanf("%d", &N);
		if (N == 0){
			break;
		}
		
		memset(matrix, -1, sizeof(matrix));
		for (y = 1; y <= N; y++){
			for (x = 1; x <= N; x++){
				matrix[y][x] = 0;
			}
		}
		
		x = y = 1;
		n = 1;
		matrix[y][x] = n;
		direc = UP;
		while (n < N * N){
			if (direc == UP){
				if (matrix[y - 1][x + 1] == 0){
					x++;
					y--;
				}
				else {
					if (matrix[y][x + 1] == 0){
						x++;
					}
					else {
						y++;
					}
					direc = DOWN;
				}
			}
			else {
				if (matrix[y + 1][x - 1] == 0){
					x--;
					y++;
				}
				else {
					if (matrix[y + 1][x] == 0){
						y++;
					}
					else {
						x++;
					}
					direc = UP;
				}
			}
			matrix[y][x] = ++n;
//printf("(%d %x=%d)", x, y, n);
		};
		
		printf("Case %d:\n", c++);
		for (y = 1; y <= N; y++){
			for (x = 1; x <= N; x++){
				printf("%3d", matrix[y][x]);
			}
			printf("\n");
		}
		
	}
	
	return (0);
}