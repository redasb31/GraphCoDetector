#include<stdio.h>
int main (void)
{
int a,i,k,temp;
int s[][9]={};
int sec[1000000]={};
int min[1000000]={};
int sumsec[1000000]={}
int sumsec2[1000000]={};

scanf("%d",&a);

do{
for(i=0,i<a;i++)
for(k=0,k<9,k++)
scanf("%d",s[i][k]);

for(i=0,i<a;i++)
sec[i]=s[i][2]+s[i][4]+s[i][6]+s[i][8];
min[i]=(s[i][1]+s[i][3]+s[i][5]+s[i][7])*60;
sumsec[i]=sec[i]+min[i];
sumsec2[i]=sumsec[i];
}

for(i=0;i<a-1;i++)
for(k=0;k<a-1;k++)
if(sumsec[k]>sumsec[k+1]){
temp=sumsec[k];
sumsec[k]=sumsec[k+1];
sumsec[k+1]=temp;

int num[3]={};
int p=0;
for(i=0;i<3;i++)
for(j=0;j<a;j++){
if(sumsec2[j]==sumsec[i]){
num[p]=j;
p++;
}}

for(i=0;i<3;i++)
printf("%d\n",s[num[i]][0]);
scanf("%d",&a);
}while(a!=0);
return 0;
}