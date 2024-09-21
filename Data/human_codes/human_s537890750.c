#include<stdio.h>
int main(void){
  int i,c;
  int ans[64];

  for (i=0;i<64;i++){
    ans[i]=0;
  }

  while((c=getchar())!=EOF){
    if('A'<=c && c<='Z'){
      c=c+('a'-'A');
    }
    ans[c-'a']++;
    //if(c=='\n')break;
  }

  for(int i=0;i<26;i++){
    printf("%c : %d\n",i+'a',ans[i]);
  }
  return 0;
}
