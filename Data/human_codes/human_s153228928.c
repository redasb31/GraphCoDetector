#include<stdio.h>
imt a[1000000];
int cmp(const void *a,const void *b){
return (int *)b-(int *)a;
}
int main(void){
int n,m,k;
int i,j;
while(scanf("%d",&n),n){
m=0;
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
qsort(a,0,n-1,cmp);
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
if(a[i]!=b[i]){
if(m<j-i){
m=j-i;
k=a[i];
}
i=j-1;
break;
}
}
}
if(n/2<m)printf("%d\n",k);
else puts("NO COLOR");
}
return 0;}