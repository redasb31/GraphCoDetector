#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 300

int qsc(const void *x, const void *y) {
	int a = *((const int *) x);
	int b = *((const int *) y);
	if (a > b) return 1;
	if (a < b) return -1;
	return 0;
}

typedef struct {
	int l, t, r, b;
} rect_t;

typedef struct {
	int num;
	int data[MAX_SIZE];
} za_t;

za_t za_x, za_y;

void za_init(za_t *za) {
	za->num = 0;
}

void za_reg(za_t *za, int coord) {
	za->data[za->num++] = coord;
}

void za_setup(za_t *za) {
	int in, out;
	qsort(za->data, za->num, sizeof(int), qsc);
	for (in = 1, out = 0; in < za->num; in++) {
		if (za->data[in] != za->data[out]) {
			za->data[++out] = za->data[in];
		}
	}
	za->num = out + 1;
}

int za_get(za_t *za, int coord) {
	int left, right, mid;
	left = 0;
	right = za->num - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (za->data[mid] == coord) return mid;
		else if (za->data[mid] < coord) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

char field[MAX_SIZE][MAX_SIZE];

void field_init(void) {
	memset(field, 0, sizeof(field));
}

/* (sx == dx && sy < dy) || (sx < dx && sy == dy) */
void field_line(int sx, int sy, int dx, int dy) {
	int i;
	if (sx == dx) {
		for (i = sy; i <= dy; i++) field[i][sx] = 0xff;
	} else {
		for (i = sx; i <= dx; i++) field[sy][i] = 0xff;
	}
}

void field_paint(int sx, int sy) {
	static int queue[MAX_SIZE * MAX_SIZE][2];
	int queue_begin, queue_end;
	static const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int i;
	if (sx < 0 || MAX_SIZE <= sx || sy < 0 ||
	MAX_SIZE <= sy || field[sy][sx]) return;
	queue_begin = 0;
	queue_end = 1;
	queue[0][0] = sy;
	queue[0][1] = sx;
	field[sy][sx] = 0xff;
	while (queue_begin < queue_end) {
		int y = queue[queue_begin][0];
		int x = queue[queue_begin][1];
		queue_begin++;
		for (i = 0; i< 4; i++) {
			int ny = y + d[i][0];
			int nx = x + d[i][1];
			if (0 <= ny && ny < MAX_SIZE &&
			0 <= nx && nx < MAX_SIZE && !field[ny][nx]) {
				field[ny][nx] = 0xff;
				queue[queue_end][0] = ny;
				queue[queue_end][1] = nx;
				queue_end++;
			}
		}
	}
}

int solve(void) {
	int n;
	int i, j;
	rect_t rects[50];
	int count;
	if (scanf("%d", &n) != 1 || n == 0) return 0;
	za_init(&za_x);
	za_init(&za_y);
	za_reg(&za_x, -2000000);
	za_reg(&za_x, 2000000);
	za_reg(&za_y, -2000000);
	za_reg(&za_y, 2000000);
	for (i = 0; i < n; i++) {
		if (scanf("%d%d%d%d", &rects[i].l, &rects[i].t,
		&rects[i].r, &rects[i].b) != 4) return 0;
		za_reg(&za_x, rects[i].l);
		za_reg(&za_x, rects[i].r);
		za_reg(&za_y, rects[i].t);
		za_reg(&za_y, rects[i].b);
	}
	za_setup(&za_x);
	za_setup(&za_y);
	field_init();
	for (i = 0; i < n; i++) {
		int l = za_get(&za_x, rects[i].l) * 2;
		int r = za_get(&za_x, rects[i].r) * 2;
		int t = za_get(&za_y, rects[i].t) * 2;
		int b = za_get(&za_y, rects[i].b) * 2;
		field_line(l, t, r, t);
		field_line(l, b, r, b);
		field_line(l, b, l, t);
		field_line(r, b, r, t);
	}
#if 0
	for (i = 0; i < MAX_SIZE; i++) {
		for (j = 0; j < MAX_SIZE; j++) {
			printf("%d",-field[i][j]);
		}
		puts("");
	}
#endif
	count = 0;
	for (i = 0; i < MAX_SIZE; i++) {
		for (j = 0; j < MAX_SIZE; j++) {
			if (!field[i][j]) {
				count++;
				field_paint(j, i);
			}
		}
	}
	printf("%d\n", count);
	return 1;
}

int main(void) {
	while (solve());
	return 0;
}