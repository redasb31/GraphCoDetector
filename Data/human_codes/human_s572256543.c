#include <stdio.h>
#include <string.h>
char s[100000];
int alphabet[26];
int len;
int check(int x){
  int i;
  for(i=0;i<26;i++){
    if(alphabet[i]>x/2)return 1;
  }
  return 0;
}
void clear(){
  int i;
  for(i=0;i<26;i++)alphabet[i]=0;
}

void aa(){
  int i;
  for(i=0;i<26;i++)printf("%d ",alphabet[i]);
  printf("\n");
}
int main(){
  int i,j,k;
  scanf("%s",s);
  len=strlen(s);
  if(len>100)return 0;
  for(i=0;i<len-1;i++){
    for(j=i+1;j<len;j++){
      clear();
      for(k=i;k<=j;k++){
	alphabet[s[k]-97]++;
      }
      //aa();
      if( check(j-i+1) ){
	printf("%d %d\n",i+1,j+1);
	return 0;
      }
    }
  }
  printf("-1 -1\n");
  return 0;
}
