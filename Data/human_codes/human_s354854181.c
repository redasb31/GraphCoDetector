#include<stdio.h>
main()
{
  int H,W,i,j,h,w;

 
  while(scanf("%d %d",&H,&W)!=EOF){
    char com[H][W+2];
    h=w=0;
    for(i=0;i<H;i++){
    
      scanf("%s",com[i]);
  
    }
  
    while(com[h][w]!='.' && com[h][w]!='!'){
      if(com[h][w]=='>'){
	com[h][w]='!';
	w++;
      }
      if(com[h][w]=='v'){
	com[h][w]='!';
	h++;
      }
      if(com[h][w]=='<'){
	com[h][w]='!';
	w--;
      }
      if(com[h][w]=='^'){
	com[h][w]='!';
	h--;
      }
    }
    if(com[h][w]=='!'){
      puts("LOOP");
    }else{
      printf("%d %d\n",w,h);
    }
  

  }
  return 0;
}