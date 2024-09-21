#include<stdio.h>
#include<string.h>


int main(void){

  char x[81];
  int i;

  scanf("%[^\n]", x);
  while(1){

    while(1){
      if(strstr(x, "the")!=NULL){
	break;
      }
      
      for(i=0; i<strlen(x); i++){
	if(x[i]!=' ' && x[i]!='.'){
	  x[i]++;
	  if(x[i]>'z') x[i]='a';
	}
      }
      
    }

    printf("%s\n", x);
    if(scanf("%[^\n]", x)!=EOF)break;
  }

  return(0);
}

