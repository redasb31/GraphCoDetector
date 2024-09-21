#include <stdio.h>

int mex(int a,int b){
	int s=0;
	while(((1<<a|1<<b)>>s)&1)s++;
	return s;
}

int main(){
	int k;
	scanf("%d",&k);
	int ans=0;
	while(k--){
		long long a,r;
		scanf("%lld%lld",&a,&r);
		int g[2]={r%2,1^r%2};
		while(!(r/2<a&&a<=r)){
			long long nr=r/2;
			int ng[2];
			ng[nr%2]=mex(g[0],g[(nr+1)%2]);
			ng[(nr%2)^1]=mex(g[0],ng[nr%2]);
			r=nr;
			g[0]=ng[0];
			g[1]=ng[1];
		}
		ans^=g[a%2];
	}
	puts(ans?"mo3tthi":"tubuann");
}
