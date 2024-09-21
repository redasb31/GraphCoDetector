#include<stdio.h>
#include<string.h>
char cs[10001]={0};
int L,n;
int f(char s[10001][3]){
  char w[10001]={0};
  int l=0,i,j;
  for(i=0;s[i][0]==0;i++);
  w[0]=s[i][0];
  for(i=0;i<n;i++){
    if(w[l]==s[i][0]){
      if(w[0]==s[i][1])break;
      l++;
      w[l]=s[i][1];
      i=0;
    }
  }
  if(i==n)return 0;
  for(i=0;i<strlen(cs);i++){
    for(j=0;j<strlen(w);j++){
      if(cs[i]==w[j]){
	strcat(cs,w);
	L+=l+1;
	break;
      }
    }
    if(j!=strlen(w))break;
  }
  return 1;
}
int main(){
  char s[34];
  int i,a;
  while(1){
    scanf("%d",&n);
    if(n==0)break;
    char m[10001][3]={{0}};
    for(i=0;i<n;i++){
      scanf("%s",s);
      m[i][0]=s[0];
      m[i][1]=s[strlen(s)-1];
    }
    cs[0]=m[0][0];
    L=0;
    a=1;
    for(i=0;i<n;i++){
      if(cs[L]==m[i][0]){
	if(cs[0]==m[i][1])break;
	L++;
	cs[L]=m[i][1];
	m[i][0]=0;
	i=0;
      }
    }
    if(i==n)a=0;
    else{
      while(n!=L+1){
	if(f(m)==0)break;
      }
    }
    if(n!=L+1)a=0;
    if(a)printf("OK\n");
    else printf("NG\n");
  }
  return 0;
}