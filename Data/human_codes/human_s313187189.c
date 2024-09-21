#include<stdio.h>
int main(){
	int n,m,a,b,i=1,d[100010]={0,1,1};
	scanf("%d %d",&n,&m);
	while(m--){
		scanf("%d %d",&a,&b);
		if(a==i||b==i)i=a+b-i;
		d[i-1]=d[i]=d[i+1]=1;
	}
	for(i=a=0;i<n;i++)a+=d[i+1];
	printf("%d\n",a);
	return 0;
}