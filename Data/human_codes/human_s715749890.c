#include <stdio.h>
#define max(p,q)((p)>(q)?(p):(q))

int h[100010];
int tate[100010],yoko[100010],cnt;

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",h+i);
	cnt=1;
	long ans=0;
	for(int i=0;i<=n;i++){
		if(h[i]>tate[cnt-1]){
			tate[cnt]=h[i];
			yoko[cnt]=i;
			cnt++;
		}
		if(h[i]<tate[cnt-1]){
			while(tate[cnt-1]>h[i]){
				ans=max(ans,1LL*tate[cnt-1]*(i-yoko[cnt-1]));
				cnt--;
			}
			tate[cnt]=h[i];
			cnt++;
		}
	}
	printf("%ld\n",ans);
}
