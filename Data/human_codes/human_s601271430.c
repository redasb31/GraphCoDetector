#include<stdio.h>
#define SIZE 100000
typedef struct{
  int x;
  int y;
}Zahyo;
Zahyo  z[SIZE];
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
main(){
  int h,w;
  char maps[30][30];
  int i,j;
  while(1){
  scanf("%d %d",&w,&h);
  if(w == 0 && h == 0) break;
  int cnt=0;
    int head=0;
    int tail=0;
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      scanf("%c",&maps[i][j]);
      if(maps[i][j]=='@'){
	z[0]=(Zahyo){j,i};
	tail=(tail+1)%SIZE;
      }
    }
  }
  while(head != tail){
    int x = z[head].x; int y = z[head].y; head = (head+1) % SIZE;
    if(0 <= x && 0 <= y && x < w && y < h && maps[y][x] != '#'){
      maps[y][x] = '#';
      cnt++;
      for(i=0;i<4;i++){
	int nx = x + dx[i]; int ny = y + dy[i];
	z[(tail+i) % SIZE] = (Zahyo){ nx,ny };
      }
      tail = (tail+4) % SIZE;
    }
  }
  printf("%d\n",cnt);
  }
  return 0;
}