#include<stdio.h>
#include<string.h>
int main(){
  char s[400];
  int i,m,h,size,sum=0;

  while(1){
    scanf("%s",s);
    if(s[0] == '-') break;
    size = strlen(s);
    for(i=0;i<size;i++){
      s[i+size] = s[i];
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
      scanf("%d",&h);
      sum+=h;
      }
    for(i=0;i<size;i++){
      printf("%c",s[i+sum%size]);
    }
    printf("\n");
  }
  return 0;
}

