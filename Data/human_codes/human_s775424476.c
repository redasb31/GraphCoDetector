#include <stdio.h>

int main(void) {
	int t;
	double kitaiti[11];
	double kakuritu_sum;
	int n,m;
	int v;
	double r;
	int i,j;
	scanf("%d",&t);
	for(i=0;i<=t;i++) {
		scanf("%d%d",&n,&m);
		kitaiti[i]=0;
		kakuritu_sum=0;
		for(j=0;j<m;j++) {
			scanf("%d%lf",&v,&r);
			kitaiti[i]+=v*r;
			kakuritu_sum+=r;
		}
		kitaiti[i]/=kakuritu_sum;
	}
	for(i=0;i<t;i++) {
		if(kitaiti[i]>kitaiti[t]+0.0000001)break;
	}
	puts(i<t?"YES":"NO");
	return 0;
}