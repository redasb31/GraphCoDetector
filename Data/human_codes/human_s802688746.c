#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int main(){
  int n,i,d[100010]={};
  int b[30];
  char s[1000010];
  for(i=0;i<30;i++)b[i]=-1;
  for(i=1;i<100010;i++)d[i]=1e9;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",s);
    if(i)d[i]=d[i-1]+1;
    if(b[s[0]-'a']+1)d[i]=MIN(d[i],d[b[s[0]-'a']]);
    b[s[0]-'a']=i;
  }
  //for(i=0;i<n;i++)printf("%d\n",d[i]);
  printf("%d\n",d[n-1]+1);
  return 0;
}

