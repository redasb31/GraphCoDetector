#include <stdio.h>

int main(void) {
	int n,p,x1,y1,z1,w1,x2,y2,z2,w2;
	int t,i,j,k;
	scanf("%d",&n);
	for(p = 1;p <= n;p++){
		scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&z1,&w1,&x2,&y2,&z2,&w2);
		t = x1*x2-y1*y2-z1*z2-w1*w2;
		i = y1*x2+x1*y2-w1*z2+z1*w2;
		j = z1*x2+w1*y2+x1*z2-y1*w2;
		k = w1*x2-z1*y2+y1*z2+x1*w2;
		printf("%d %d %d %d\n",t,i,j,k);
	}
	scanf("%d",&n);
	return 0;
}