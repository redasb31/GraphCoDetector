#include <stdio.h>
int yu(int a,int b);

int main(void){
	int n,i,max=0;
	scanf("%d",&n);
	int all[n];
	int h[n+1];
	int m[n+1];
	h[0] = 0; m[n] = 0;
	for(i=0;i<n;i++) scanf("%d",&all[i]);
	for(i=0;i<n;i++) h[i+1] = yu(h[i],all[i]);
	for(i=n;i>=0;i--) m[i] = yu(m[i+1],all[i]);
	
	for(i=0;i<n;i++){
		if(yu(h[i],m[i+1])>=max) max = yu(h[i],m[i+1]);
	}
	printf("%d\n",max);
	return 0;
}
int yu(int a,int b){
	if(a==0) return b;
	else return yu(b%a,a);
}
