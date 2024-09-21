#include <stdio.h>

int main(int argc, char const *argv[])
{
	double left, right;
	int cntleft[4] = {0};
	int cntright[4] = {0};
	// A:0, B:1, C:2, D:3
	int i;
	while(scanf("%lf %lf", &left, &right) != EOF) {
		if(left >= 1.1)
			cntleft[0]++;
		else if(left >= 0.6)
			cntleft[1]++;
		else if(left >= 0.2)
			cntleft[2]++;
		else
			cntleft[3]++;
		if(right >= 1.1)
			cntright[0]++;
		else if(right >= 0.6)
			cntright[1]++;
		else if(right >= 0.2)
			cntright[2]++;
		else
			cntright[3]++;
	}
	for(i = 0; i < 4; ++i) {
		printf("%d %d\n", cntleft[i], cntright[i]);
	}
	return 0;
}