#include <stdio.h>
#include <stdlib.h>
#define PARENT(i) ((i)>>1)
#define LEFT(i)   ((i)<<1)
#define RIGHT(i)  (((i)<<1)+1)
#define QSIZE 300010
int que[QSIZE + 5];
int qsize;

void max_heapify(int i)
{
	int l, r, max;
	int qt;

	l = LEFT(i), r = RIGHT(i);
	if (l < qsize && que[l] > que[i]) 
	{
		max = l;
	}
	else{
		max = i;
	}
	if (r < qsize && que[r] > que[max]) max = r;
	if (max != i) 
	{
		qt = que[i];
		que[i] = que[max];
		que[max] = qt;
		max_heapify(max);
	}
}

void deq()
{
	que[0] = que[--qsize];
	max_heapify(0);
}

void enq(int c)
{
	int i, max;
	int qt;

	i = qsize++;
	que[i] = c;
	while (i > 0 && que[max = PARENT(i)] < que[i]) 
	{
		qt = que[i]; 
		que[i] = que[max];
		que[max] = qt;
		i = max;
	}
}

int c[300010];
int top[300010], sz[300010]; int N;

int main()
{
	int i, k, M;
	unsigned ans;

    scanf("%d", &N);//乗り場
	k = 0;
	for (i = 0; i < N; i++) 
	{
	    scanf("%d", &M);//人数
		sz[i] = M;
		top[i] = k;//先頭
		while (M--) scanf("%d", &c[k++]);//M人分人を並べる
	}
	
	ans = 0;//最大値
	qsize = 0;
	for (i = N - 1; i >= 0; i--) {
		M = sz[i];//その乗り場の人数を再格納
		k = top[i];//その乗り場の先頭を再格納
		while (M--) enq(c[k++]);//キュー配列cにM人分格納
		ans += (unsigned)que[0];
		deq();
	}
	printf("%u\n", ans);
	return (0);
}


