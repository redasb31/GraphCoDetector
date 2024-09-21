#include<stdio.h>
int main(){
int n;
long long int l,t;
scanf("%d %lld %lld ",&n,&l,&t);
long long int x[n];
int w[n];
int a;
for(a=0;a<n;a++)
 scanf("%d %d",&x[a],&w[a]);

long long int c;
for(a=0;a<n;a++){
 printf("\nx[%d]=%lld\n",a+1,x[a]);
 if(w[a]==1){
  x[a]+=t;}
 if(w[a]==2){
  x[a]-=t;}
 printf("x[%d]=%lld\n",a+1,x[a]);
}

int m;
for(m=0;m<n;m++)
 for(a=1;a<n;a++){
  if(x[a-1]<x[a]){
  c=x[a];x[a]=x[a-1];x[a-1]=c;}
  }

for(a=0;a<n;a++){
 x[a]=x[a]%l;
 if(x[a]<0)x[a]+=l;}

for(a=0;a<n;a++)
printf("%lld\n",x[a]);


return 0;}