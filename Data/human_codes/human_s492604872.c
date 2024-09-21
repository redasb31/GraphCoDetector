#include <stdio.h>

int a[200010];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int d=1;d<=n;d++)if(n%d==0){
		int flag=1;
		for(int i=0;i<n-d;i++)flag&=a[i]==a[i+d];
		if(flag){
			printf("%d\n",n/d);
			return 0;
		}
	}
}
