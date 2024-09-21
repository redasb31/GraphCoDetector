#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char *a,char *b);

int main(void){
  char str[128];
  unsigned short n,*a,*b,dif;
  int i,j,k;
  int len;

  while(scanf("%hu%*c",&n) && n){
    scanf("%s%*c",str);
    a=(unsigned short *)calloc(n,sizeof(unsigned short));
    b=(unsigned short *)calloc(n,sizeof(unsigned short));
    for(i=0;i<n;i++){
      scanf("%hu %hu%*c",a+i,b+i);
      (*(a+i))--;
      (*(b+i))--;
    }
    for(i=n-1;i>=0;i--){
      dif=*(b+i)-*(a+i);
      str[*(a+i)]=((str[*(a+i)]-'a')+dif)%26+'a';
      str[*(b+i)]=((str[*(b+i)]-'a')+dif)%26+'a';
      swap(str+*(a+i),str+*(b+i));
    }
    puts(str);
    free(a);
    free(b);
  }
  return 0;
}

void swap(char *a,char *b){
  char tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}