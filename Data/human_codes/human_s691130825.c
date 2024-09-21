#include<stdio.h>
#define int long long

int n;
int x[1010],y[1010];
int c[2];
int a[99];
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld%lld",x+i,y+i);
		c[(x[i]+y[i])%2]++;
	}
	if(c[0]&&c[1]){
		puts("-1");
		return 0;
	}
	int flag=!!c[0];
	int N=40;
	printf("%d\n",N+flag);
	for(int i=0;i<N;i++)printf("%lld ",a[i]=1LL<<(N-1-i));
	if(flag)puts("1"),a[N]=1;
	else puts("");
	int cnt=N+flag;
	
	for(int i=0;i<n;i++){
		int xx=x[i]-y[i];
		int yy=x[i]+y[i];
		for(int i=0;i<cnt;i++){
			     if(xx>=0&&yy>=0)putchar('R'),xx-=a[i],yy-=a[i];
			else if(xx>=0&&yy<=0)putchar('D'),xx-=a[i],yy+=a[i];
			else if(xx<=0&&yy>=0)putchar('U'),xx+=a[i],yy-=a[i];
			else if(xx<=0&&yy<=0)putchar('L'),xx+=a[i],yy+=a[i];
		}
		puts("");
	}
}