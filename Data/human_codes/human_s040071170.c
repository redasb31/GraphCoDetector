#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main(){
  int n=0;
  char c[20002];
  int height[20002];//i番目のマスの左の高さは、height[i-1]。右の高さはheight[i]。height[0]=0
  height[0]=0;//基準の高さ
  int flood[20002];//水の体積。1オリジン
  int floodnum=0;//池の数
  int sum=0;

  
  while(1){
    scanf("%c",&c[n+1]);
    if(c[n+1]=='\n') break;
    if(c[n+1]=='\\') height[n+1]=height[n]-1;
    else if(c[n+1]=='/') height[n+1]=height[n]+1;
    else height[n+1]=height[n];
    n+=1;
  }//読み込み。nが文字の数を表す。cは１オリジン。


  int i;//処理中のマスを表す。
  i=1;
  int j,k;//繰り返し用
  int max;//右の壁となるマス目の番号
  while(1){
    if(c[i]=='\\'){
      j=i+1;
      while(j<=n){
        if(height[i-1]==height[j]) break;
        j+=1;
      }
      
      if(j<=n){
        floodnum+=1;
        flood[floodnum]=0;
        for(k=i;k<=j;k++) flood[floodnum]+=height[i-1]-height[k];
        i=j+1;//次に調べるマスの更新
      }//左側の壁のほうが低い池
       
      else{
        max=-1;
        for(j=i+1;j<=n;j++){
          if(c[j]=='/'){
            if(max==-1) max=j;
            else if(height[max]<= height[j]) max=j;
          }
        }
        if(max==-1) i=n+1;
        else{
          floodnum+=1;
          flood[floodnum]=0;
          for(j=i;j<=max;j++){
            if(height[max]-height[j]>0) flood[floodnum]+=height[max]-height[j];
          }
          i=max+1;
        }
      }//右側の壁のほうが低い池
    }
    else i+=1;
    if(i>n) break;
  }

  for(i=1;i<=floodnum;i++) sum+=flood[i];  
  printf("%d\n",sum);
  printf("%d",floodnum);
  for(i=1;i<=floodnum;i++) printf(" %d",flood[i]);
  printf("\n");
  return 0;
}



//  \を出力、入力したい場合は\\で表す



