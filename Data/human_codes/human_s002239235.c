#include<stdio.h>
#include<stdlib.h>

int main()
{
int N,C,K,B,P,s,F;
int *T
int i,j;

scanf("%d %d %d",&N,&C,&K);
T = (int *)malloc(N * sizeof(int));

B=0;
P=0;

for(i=0;i<N;i++){
scanf("%d",&T[i]);
}

for(i=0;i<N;i++){
for(j=N-1;j>i;j--){
if(T[j]<T[j-1]){
s=T[j];
T[j]=T[j-1];
T[j-1]=s;
}
}
}

F=T[0];
for(i=0;i<N;i++){
if(P<C){
P++;
}else if(P==C || (T[i]-F)>K){
B++;
P=1;
F=T[i];
}
}

printf("%d",B);
free(T);
return 0;
}