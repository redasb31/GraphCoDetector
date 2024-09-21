#include<stdio.h>
int main(){
  int n,i,j,k,m=0,p;
  char s[100010]={};
  scanf("%d %s",&n,s+1);
  for(i=1;i<=n;i++){
    if(s[i]-'.')continue;
    for(j=i-1;s[j]=='W';j--);
    for(k=i+1;s[k]=='W';k++);
    if(s[j]=='B'&&s[k]=='B')continue;
    for(j=i-1;s[j]=='B';j--);
    for(k=i+1;s[k]=='B';k++);
    p=0;
    if(s[j]=='W')p+=(i-j-1);
    if(s[k]=='W')p+=(k-i-1);
    if(m<p)m=p;
  }
  printf("%d\n",m);
  return 0;
}

