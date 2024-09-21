#include <stdio.h>
#include <stdlib.h>
int c[100010],v[100010];
int comp(const void*p,const void*q){
	if(v[*(int*)p]>v[*(int*)q])return -1;
	return 1;
}

int lim[100010];
int idx[100010];
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++)scanf("%d",lim+i);
	for(int i=0;i<n;i++)scanf("%d%d",c+i,v+i),idx[i]=i;
	qsort(idx,n,sizeof(int),comp);
	long ans=0;
	for(int i=0;m>0&&i<n;i++)if(lim[c[idx[i]]-1]-->0)ans+=v[idx[i]],m--;
	printf("%ld\n",ans);
}
