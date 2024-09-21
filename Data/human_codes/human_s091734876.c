#include<stdio.h>
int d[30][200010]={};
int f[30][200010],c[30],i,j,k,l,a,mi;
int main(){
  char s[100010],w[100010];
  scanf("%s",w);
  for(l=0;w[l];l++);
  for(i=0;w[i];i++)s[i]=w[l-i-1];
  s[l]=0;
  for(i=0;i<26;i++)d[i][0]=1;
  for(i=0;s[i];i++){
    a=s[i]-'a';
    c[a]=i;
    for(j=0;j<26;j++){
      if(a==j){
	d[j][i+1]=d[j][i]+1;
	f[j][i+1]=i;
      }
      else{
	d[j][i+1]=d[j][i];
	if(d[a][i+1]>d[j][i]+1){
	  d[a][i+1]=d[j][i]+1;
	  f[a][i+1]=c[a];
	}
      }
    }
  }
  for(i=mi=0;i<26;i++){
    if(d[mi][l]>d[i][l])mi=i;
  }
  for(i=0;s[i];i++){
    if(s[i]==mi+'a'){
      printf("%c",s[i]);
      mi=f[mi][i];
    }
  }
  printf("%c\n",mi+'a');
  
  return 0;
}
