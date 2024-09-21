#include <stdio.h>
#include <string.h>

#define Q_MAX (400000)

typedef struct {
	char block[10][11];
    int num[3];
	int time;
} COLOR;

int head, tail;
COLOR queue[Q_MAX];

void enq(COLOR t)
{
	queue[tail++] = t;
	if (tail == Q_MAX) tail = 0;
}

void deq(COLOR *t)
{
	*t = queue[head++];
	if (head == Q_MAX) head = 0;
}

int conv(char c)
{
    return ((c > 'B') + (c > 'G'));
}

int x, y;

void dfs(COLOR *exm, char c, char change, int p, int q)
{
	int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
	int mx, my;
	int i;
	
    exm->num[conv(exm->block[q][p])]--;
    exm->num[conv(c)]++;
	exm->block[q][p] = c;
	
	for (i = 0; i < 4; i++){
		mx = p + dx[i];
		my = q + dy[i];
		if (0 <= mx && mx < x && 0 <= my && my < y && exm->block[my][mx] == change){
			dfs(exm, c, change, mx, my);
		}
	}
}

void check(COLOR p, char col)
{
	if (p.block[0][0] != col){
		p.time++;
		dfs(&p, col, p.block[0][0], 0, 0);
		enq(p);
	}
}

int main(void)
{
	COLOR puzzle, temp;
	int i, j;
	char c;
    
	while (1){
		scanf("%d%d", &x, &y);
		
		if (x + y == 0){
			break;
		}
        memset(puzzle.num, 0, sizeof(puzzle.num));
		
		for (i = 0; i < y; i++){
			for (j = 0; j < x; j++){
				do {
					c = puzzle.block[i][j] = getchar();
				} while (c != 'R' && c != 'G' && c != 'B');
                puzzle.num[conv(c)]++;
			}
		}
		memset(queue, 0, sizeof(queue));
		head = tail = 0;
		puzzle.time = 0;
		enq(puzzle);
        
		while (1){
			deq(&temp);
			
			if (temp.num[0] == x * y || temp.num[1] == x * y || temp.num[2] == x * y){
				break;
			}
			
			check(temp, 'R');
			check(temp, 'G');
			check(temp, 'B');
		}
		
		printf("%d\n", temp.time);
	}
	
	return (0);
}