#include<stdio.h>
typedef struct{
  int x;
  int y;
}position;

int main(){
  int h=0;
  int w=0;
  int i=0;
  int j=0;
  char str[100][100] = {};
  int kakutei[100][100] = {};
  position stack[30000] = {};
  int sstart = 0;
  int slast = 0;
  int slastf = 0;
  int movef = 0;
  int depth = 0;
  int wcnt = 0;
  
  scanf("%d %d",&h,&w);
  for(i=0;i<h;i++){
    scanf(" %s",str[i]);
  }
  for(i=0;i<h;i++){
    //printf("%s\n",str[i]);
    for(j=0;j<w;j++){
      kakutei[i][j] = -1;
    }
  }
  
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(str[i][j] == '#'){
        wcnt++;
      }
    }
  }
  //printf("***%d***",wcnt);
  kakutei[0][0] = 0;
  depth = 0;
  stack[0].x = 0;
  stack[0].y = 0;
  sstart = 0;
  slastf = -1;
  slast = 0;
  while(kakutei[h-1][w-1] == -1){
    //printf("*");
    depth++;
    sstart = slastf+1;
    slastf = slast;
    movef = 0;
    for(i=sstart;i<=slastf;i++){
      if( stack[i].x+1 < w && str[stack[i].y][stack[i].x+1] == '.' && kakutei[stack[i].y][stack[i].x+1] == -1){
        kakutei[stack[i].y][stack[i].x+1] = depth;
        movef = 1;
        slast++;
        stack[slast].x = stack[i].x+1;
        stack[slast].y = stack[i].y;

      }
      if(stack[i].x-1 >= 0 && str[stack[i].y][stack[i].x-1] == '.' && kakutei[stack[i].y][stack[i].x-1] == -1){
        kakutei[stack[i].y][stack[i].x-1] = depth;
        movef = 1;
        slast++;
        stack[slast].x = stack[i].x-1;
        stack[slast].y = stack[i].y;
        
      }
      if(stack[i].y+1 < h && str[stack[i].y+1][stack[i].x] == '.' && kakutei[stack[i].y+1][stack[i].x] == -1){
        //printf("_");
        kakutei[stack[i].y+1][stack[i].x] = depth;
        movef = 1;
        slast++;
        stack[slast].x = stack[i].x;
        stack[slast].y = stack[i].y+1;
        
      }
      if(stack[i].x+1 >= 0 && str[stack[i].y-1][stack[i].x] == '.' && kakutei[stack[i].y-1][stack[i].x] == -1){
        kakutei[stack[i].y-1][stack[i].x] = depth;
        movef = 1;
        slast++;
        stack[slast].x = stack[i].x;
        stack[slast].y = stack[i].y-1;
        
      }
    }
    if(!movef){
      break;
    }
  }
  /*for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      printf("%d",kakutei[i][j]);
    }
    printf("\n");
  }*/
  
  if(kakutei[h-1][w-1] == -1){
    printf("-1");
  }else{
    printf("%d",(h*w)-(kakutei[h-1][w-1]+1)-wcnt);
  }
  return 0;
}
        
    
  
  