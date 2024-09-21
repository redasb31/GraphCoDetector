#include<stdio.h>
long t[150001],u[150000],v[150000];
int main(int argc, char const *argv[]){
	long n,i,s,e;
	scanf("%ld",&n);
	for(i=0;i<n-1;i++){
		scanf("%ld %ld",&u[i],&v[i]);
	}
	t[u[0]]=0;
	t[v[0]]=1;
	s=u[0];
	e=v[0];
	for(i=1;t[e]-t[s]+1<n;i++){
		if(u[i]==s || v[i]==s){
			t[(u[i]==s)?v[i]:u[i]]=t[s]-1;
			s=(u[i]==s)?v[i]:u[i];
			i=1;
		}else if(u[i]==e || v[i]==e){
			t[(u[i]==e)?v[i]:u[i]]=t[e]+1;
			e=(u[i]==e)?v[i]:u[i];
			i=1;
		}
	}
	for(i=1;i<=n;i++){
		if(s==i || e==i){
			printf("%f\n",(double)(n-1));
		}else{
			printf("%f\n",(n-1)/2.0);
		}
	}
	return 0;
}