#include<stdio.h>
int main()
{
	int n,k,i,j,c,e,d,f,t,a,b;
	scanf("%d %d",&n,&k);
	e=n/2;
	f=n%2;
	for(i=0;i<k;i++){
		scanf("%d %d",&a,&b);
		if(f==0){
		if(a==e){
			c=n-a;
			c=c%3;
		}
		else if(b==e){
			c=n-b;
			c=c%3;
		}
		}
		if(a<e && b<e){
			c=min(a,b);
			c=c%3;
		}
		else if(a>e && b<e){
			c=min(a,b);
			c=c%3;
		}
		else if(a<e && b>e){
			c=max(a,b);
			t=n-c;
			t=t+1;
			c=t%3;
		}
		else if(a>e && b>e){
			c=max(a,b);
			t=n-c;
			t=t+1;
			c=t%3;
		}
		if(c==0){
			c=3;
		}
		printf("%d\n",c);
	}
	return 0;
}
int max(int a,int b)
{
	int c;
	if(a<b){
		c=b;
	}
	else{
		c=a;
	}
	return c;
}
int min(int a,int b)
{
	int c;
	if(a<b){
		c=a;
	}
	else{
		c=b;
	}
	return c;
}
