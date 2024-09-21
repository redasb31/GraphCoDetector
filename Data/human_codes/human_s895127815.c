#include <stdio.h>
int main(void){
    int H,W,moji,sum=0;
   scanf("%d%d",&H,&W);
   for(int i=0;i<H+1;i++) //ここはよくわかってない
   {
   for(int j=0;j<W;j++){
       moji = getchar();
       if(moji=='#')sum++;
   }
      
   }
   if(sum==H+W-1){
       printf("Possible");
   }
   else{
       printf("Impossible");
   }
   
   printf("%d",sum);
   return 0;

    
}