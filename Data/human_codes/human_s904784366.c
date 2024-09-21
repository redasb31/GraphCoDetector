#include<stdio.h>
#include<limits.h>
int main(){
	int n, m;
	int i, j;
	while(scanf("%d%d", &n, &m), n) {
		int cost[100][100] = {0};
		int determined[100] = {0}, undeterminednodes = n;
		//int mincost[100] = {0};
		int *mincost = cost[0];
		int costsum = 0;
		int minnode, minnodecost, nextminnode;

		for(i = 0; i < n; i ++) {
			for(j = 0; j < n; j ++) {
				cost[i][j] = INT_MAX;
			}
		}
		/*for(i = 0; i < n; i ++) {
			mincost[i] = INT_MAX;
		}*/
		for(i = 0; i < m; i ++) {
			int a, b, d;
			scanf("%d,%d,%d", &a, &b, &d);
			cost[a][b] = cost[b][a] = d/100-1;
		}
		minnode = 0;
		minnodecost = 0;

		while(undeterminednodes > 0) {
			determined[minnode] = 1;
			costsum += minnodecost;
			undeterminednodes --;
			mincost[minnode] = INT_MAX;
			minnodecost = INT_MAX;
			for(i = 0; i < n; i ++) {
				if(!determined[i]) {
					if(cost[minnode][i] < mincost[i])
						mincost[i] = cost[minnode][i];
				}
				if(mincost[i] < minnodecost) {
					nextminnode = i;
					minnodecost = mincost[i];
				}
			}
			minnode = nextminnode;
		}
		printf("%d\n", costsum);
	}
	return 0;
}