#include<stdio.h>
int main(void){
     int n,x,y,b,p,i,b1,p1,g;
     scanf("%d",&n);
     for(i=0;i<n;i++){
          scanf("%d %d %d %d",&x,&y,&b,&p);
          g=x*b+y*p;
          if(b==0){
               b1=8*(x*5+y*p)/10;
               if(g>b1)printf("%d\n",b1);
          }
          if(p==0){
               p1=8*(x*b+y*2)/10;
               if(g>p1)printf("%d\n",p1);
          }
          if(b>=5 && p>=2)printf("%d\n",8*g/10);
          if(b<5 && p<2)printf("%d\n",g);
     }
     return 0;
}