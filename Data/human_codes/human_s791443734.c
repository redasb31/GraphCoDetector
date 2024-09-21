#include<stdio.h>
#include<stdlib.h>
int f(int l,int r){//printf("%d %d\n",l,r);
	int a,b;
	if(l+1==r){
		scanf("%d",&a);
		return a;
	}
	a=f(l,(l+r)/2);
	b=f((l+r)/2,r);
	if(a==b)return a;
	return abs(a-b);
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",f(0,1<<n));
	return 0;
}