//Date:03-10-16

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<float.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>
#include<time.h>
#define ll long long
#define For(i,n)	for(i=0;i<n;i++)
#define rep(i ,a ,b)	for(i=(a);i<=(b);i++)
#define mset(a ,value)	memset(a ,value ,sizeof(a))
#define s(a)	scanf("%d" ,&a);
#define ls(a)	scanf("%ld" ,&a)
#define reg(i)	register int i
#define infinite INT_MAX
#define MAX 100001
#define NIL -1
ll min(ll a,ll b){	return (a<b?a:b);	}
ll max(ll a,ll b){	return (a>b?a:b);	}
main(){
	int n ,a ,b ,i ,c=0;
	scanf("%d%d%d" ,&n ,&a ,&b);
	int A[n];
	For(i ,n){
		s(A[i]);
		if(A[i]>=a&&A[i]<b)	c++;
	}
	printf("%d" ,n-c);
	return 0;
}