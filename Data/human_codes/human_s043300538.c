#include<stdio.h>
#include<string.h>
int main(void){
  int h,w,i,j,sum=0,up,side;
  scanf("%d %d",&h,&w);
  char str[h][w];
  for(i=0;i<h;i++){
    scanf("%s",&str[i]);
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(str[i][j]=='.'){
        sum=0;
        for(up=-1;up<=1;up++){
          for(side=-1;side<=1;side++){
            if(str[i+up][j+side]=='#'){
              sum++;
            }
          }
        }
        str[i][j]='0'+sum;
      }
    }
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      printf("%c",str[i][j]);
    }
    printf("\n");
  }
  return 0;
}