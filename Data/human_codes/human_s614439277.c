#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT_NODES (100)

int compare(const void *a, const void *b) {
	return ((int*)a)[2] - ((int*)b)[2];
}

int solve(int num_node) {
	int i, k, num_edge, answer, node1, node2;
	char forest[LIMIT_NODES][LIMIT_NODES];

	scanf("%d ", &num_edge);
	int S[num_edge][3];

	for (i = 0; i < num_edge; i++) {
		scanf("%d,%d,%d ", S[i]+0, S[i]+1, S[i]+2);
	}
	qsort(S, num_edge, sizeof(S[0]), compare);

	memset(forest, 0, sizeof(forest[0]) * LIMIT_NODES);
	for (i = 0; i < num_node; i++) {
		forest[i][i] = 1;
	}

	answer = 0;
	for (i = 0; i < num_edge; i++) {
		node1 = node2 = 0;
		for (k = 0; k < num_node; k++) {
			if (forest[k][S[i][0]]) {
				node1 = k;
			}
			if (forest[k][S[i][1]]) {
				node2 = k;
			}
		}
		if (node1 != node2) {
			for (k = 0; k < LIMIT_NODES; k++) {
				forest[node1][k] |= forest[node2][k];
				forest[node2][k] = 0;
			}
			answer += (S[i][2] / 100) - 1;
		}
	}
	return answer;
}

int main(void) {
	int num_node;

	while (1) {
		scanf("%d ", &num_node);
		if (!num_node)
			break;

		printf("%d\n", solve(num_node));
	}
	return 0;
}