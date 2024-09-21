#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct {
	int x, y;
} zahyo_t;

typedef struct gain_t_tag {
	int id;
	struct gain_t_tag* next;
} gain_t;

gain_t* sort_gain(gain_t* target) {
	gain_t* lists[2] = {NULL, NULL};
	gain_t** out;
	int select;
	if (target == NULL || target->next == NULL) return target;
	select = 0;
	while (target != NULL) {
		gain_t* next = target->next;
		target->next = lists[select];
		lists[select] = target;
		select = 1 - select;
		target = next;
	}
	lists[0] = sort_gain(lists[0]);
	lists[1] = sort_gain(lists[1]);
	target = NULL;
	out = &target;
	while (lists[0] != NULL || lists[1] != NULL) {
		if (lists[0] == NULL) {
			select = 1;
		} else if (lists[1] == NULL) {
			select = 0;
		} else {
			select = lists[0]->id <= lists[1]->id ? 0 : 1;
		}
		*out = lists[select];
		lists[select] = lists[select]->next;
		(*out)->next = NULL;
		out = &(*out)->next;
	}
	return target;
}

int AN, BN, R;
zahyo_t zahyo[200000];
int init[200000];

gain_t *gain_data[200000];

void add_gain(int target, int which) {
	gain_t* new_node = malloc(sizeof(gain_t));
	if (new_node == NULL) exit(1);
	new_node->id = which;
	new_node->next = gain_data[target];
	gain_data[target] = new_node;
}

void direct_solve(const int* data, int num) {
	int i, j;
	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			if ((zahyo[data[i]].x - zahyo[data[j]].x) * (zahyo[data[i]].x - zahyo[data[j]].x) +
			(zahyo[data[i]].y - zahyo[data[j]].y) * (zahyo[data[i]].y - zahyo[data[j]].y) <= (4 * R) * (4 * R)) {
				if (data[i] < AN && AN <= data[j]) {
					add_gain(data[i], data[j]);
				} else if (data[j] < AN && AN <= data[i]) {
					add_gain(data[j], data[i]);
				}
			}
		}
	}
}

void search(const int* data, int num) {
	int next_data_num[4];
	int* next_data[4];
	if (num <= 100) {
		direct_solve(data, num);
	} else {
		int i;
		int minx = zahyo[data[0]].x, miny = zahyo[data[0]].y;
		int maxx = zahyo[data[0]].x, maxy = zahyo[data[0]].y;
		int mx[2], my[2];
		for (i = 1; i < num; i++) {
			int x = zahyo[data[i]].x, y = zahyo[data[i]].y;
			if (x < minx) minx = x;
			if (x > maxx) maxx = x;
			if (y < miny) miny = y;
			if (y > maxy) maxy = y;
		}
		mx[0] = minx + (maxx - minx) / 3;
		mx[1] = minx + (maxx - minx) * 2 / 3;
		my[0] = miny + (maxy - miny) / 3;
		my[1] = miny + (maxy - miny) * 2 / 3;
		if (mx[1] - minx <= 4 * R || maxx - mx[0] <= 4 * R || my[1] - miny <= 4 * R || maxy - my[0] <= 4 * R) {
			direct_solve(data, num);
			return;
		}
		for (i = 0; i < 4; i++) {
			next_data[i] = malloc(sizeof(int) * num);
			if (next_data[i] == NULL) exit(1);
			next_data_num[i] = 0;
		}
		for (i = 0; i < num; i++) {
			int x = zahyo[data[i]].x, y = zahyo[data[i]].y;
			if (x <= mx[1] && y <= my[1]) next_data[0][next_data_num[0]++] = data[i];
			if (mx[0] <= x && y <= my[1]) next_data[1][next_data_num[1]++] = data[i];
			if (x <= mx[1] && my[0] <= y) next_data[2][next_data_num[2]++] = data[i];
			if (mx[0] <= x && my[0] <= y) next_data[3][next_data_num[3]++] = data[i];
		}
		for (i = 0; i < 4; i++) {
			search(next_data[i], next_data_num[i]);
			free(next_data[i]);
		}
	}
}

int main(void) {
	int i;
	uint64_t answer = 0;
	while (scanf("%d%d%d", &AN, &BN, &R) == 3 && (AN | BN | R) != 0) {
		for (i = 0; i < AN + BN; i++) {
			if (scanf("%d%d", &zahyo[i].x, &zahyo[i].y) != 2) return 1;
			init[i] = i;
		}
		search(init, AN + BN);
		for (i = 0; i < AN; i++) {
			gain_t* data = sort_gain(gain_data[i]);
			int prev_id = -1;
			while (data != NULL) {
				gain_t* next = data->next;
				if (prev_id != data->id) answer++;
				prev_id = data->id;
				free(data);
				data = next;
			}
			gain_data[i] = NULL;
		}
		printf("%"PRIu64"\n", answer);
	}
	return 0;
}