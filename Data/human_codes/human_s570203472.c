#include<stdio.h>
int main(){
int n,k,i,a,b;
int c[1000];
scanf("%d",&n);
scanf("%d",&k);
for(i=0;i<k;i++){
scanf("%d %d",&a,&b);
if(a>b) a=n+1-a;
else if(a<b) b=n+1-b;
if(a>b) c[i]=b%3;
else if(a<b) c[i]=a%3;
else c[i]=a%3;
if(c==0) c[i]=3;
printf("%d\n",c[i]);
}
return 0;
}