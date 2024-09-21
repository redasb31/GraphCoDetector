#include <stdio.h>
#include <memory.h>
int main(void){
	int n,m,s,k,c,q[10000],l[10000],i,j,max,min;
	while(1){
		scanf("%d %d",&n,&m);
		if(!n) break;
		memset(q,0,sizeof(q));
		memset(l,0,sizeof(l));
		for(i=0;i<m;i++){
			scanf("%d %d",&s,&k);
			for(j=0;j<k;j++){
				scanf("%d",&c);
				q[c-1]+=s;
			}
			if(k==1)
				l[c-1]+=s;
		}
		max=0;
		for(i=0;i<n;i++){
			if(max<q[i])
				max=q[i];
		}
		min=114514;
		for(i=0;i<n;i++){
			if(min>l[i]&&max!=q[i])
				min=l[i];
		}
		printf("%d\n",max-min+1);
	}
	return 0;
}