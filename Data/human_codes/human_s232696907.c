#include <stdio.h>
struct a{
  char name[2];
  int score[10],win,lose;
};
main(){
  int n,j,i,top=0,b,con=0;
  while(1){
    scanf("%d",&n);
    if(n==0) break;
    struct a p[10];
    for(i=0;i<n;i++){
      p[i].win=0;
      p[i].lose=0;
      scanf("%s",p[i].name);
      for(j=0;j<n-1;j++){
	scanf("%d",&p[i].score[j]);
	if(p[i].score[j]==0) p[i].win+=1;
	else if(p[i].score[j]==1) p[i].lose+=1; 
      }
    }

    for(i=0;i<n;i++){
      b=100;
      for(j=0;j<n;j++){
	if(top<p[j].win){
	  top=p[j].win;
	  con=j;
	}
	else if((top==p[j].win&&b>p[j].lose)||(top==p[j].win&&b==100)){
	  b=p[j].lose;
	  con=j;
	}
      }
      printf("%s\n",p[con].name);
      p[con].win=-1;
      for(j=0;j<n;j++){
	if(p[j].win!=-1){
	  top=p[j].win;
	  con=j;
	  break;
	}
      }

    }
  } 
  return 0; 
}