#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;
#define MAX(x,y) ((x>y)?x:y)

int comp(const void *p,const void *q){
	return *(int *)p-*(int *)q;
}
int x[105],y[105],d[105];
int sx[105],sy[105],sd[105];
int c[105][105][105];
int main(){
	int i,j,k,l,n,K;
	int xn,yn,dn;
	long long ans;
	
	scanf("%d%d",&n,&K);
	for(i=0;i<n;i++)scanf("%d%d%d%d%d%d",&x[i*2],&y[i*2],&d[i*2],&x[i*2+1],&y[i*2+1],&d[i*2+1]);
	memcpy(sx,x,sizeof(int)*n*2);
	memcpy(sy,y,sizeof(int)*n*2);
	memcpy(sd,d,sizeof(int)*n*2);
	
	qsort(sx,n*2,sizeof(int),comp);
	qsort(sy,n*2,sizeof(int),comp);
	qsort(sd,n*2,sizeof(int),comp);
	
	xn=yn=dn=1;
	for(i=1;i<n*2;i++)if(sx[i]!=sx[i-1])sx[xn++]=sx[i];
	for(i=1;i<n*2;i++)if(sy[i]!=sy[i-1])sy[yn++]=sy[i];
	for(i=1;i<n*2;i++)if(sd[i]!=sd[i-1])sd[dn++]=sd[i];
	/*
	for(i=0;i<xn;i++)printf("%3d ",sx[i]);printf("\n");
	for(i=0;i<yn;i++)printf("%3d ",sy[i]);printf("\n");
	for(i=0;i<dn;i++)printf("%3d ",sd[i]);printf("\n");
	*/
	memset(c,0,sizeof(c));
	for(i=0;i<n*2;i++){
		x[i]=lower_bound(sx,sx+xn,x[i])-sx;
		y[i]=lower_bound(sy,sy+yn,y[i])-sy;
		d[i]=lower_bound(sd,sd+dn,d[i])-sd;
		//printf("%d %d %d\n",x[i],y[i],d[i]);
		if(i%2==1){
			for(j=x[i-1];j<x[i];j++)
				for(k=y[i-1];k<y[i];k++)
					for(l=d[i-1];l<d[i];l++)c[j][k][l]++;
		}
	}
	ans=0;
	for(i=0;i<xn-1;i++)for(j=0;j<yn-1;j++)for(k=0;k<dn-1;k++){
		if(c[i][j][k]>=K)ans+=(long long)(sx[i+1]-sx[i])*
							  (long long)(sy[j+1]-sy[j])*
							  (long long)(sd[k+1]-sd[k]);
	}
	printf("%lld\n",ans);
	
	
	return 0;
}