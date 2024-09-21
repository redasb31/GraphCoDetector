#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX(x,y) (((x)<(y))?(y):(x))
#define MIN(x,y) (((x)>(y))?(y):(x))


int nowmax=0;
char input[1024];

void solve(void);
int calc(char *str,int bad);
int max(char *str1,char *str2,char *last,int bad);
int min(char *str1,char *str2,char *last,int bad);

int main(void){
  int Q;
  scanf("%d%*c",&Q);
  while(Q--) solve();
  return 0;
}

void solve(void){
  int num;
  nowmax=0;
  scanf("%s%*c",input);
  if(input[0]=='_' || input[0]=='^') num=calc(input,-1);
  else{
    nowmax=1;
    num=strtol(input,NULL,0);
  }
  printf("%d %d\n",num,nowmax+1);
}

int calc(char *str,int bad){
  int blaces=1,ans,i;
  char *str1,*str2,*last;
  for(i=2;str[i]!='\0' && blaces>0;i++){
    if(str[i]=='(') blaces++;
    else if(str[i]==')') blaces--;
    if(blaces==1 && str[i]==',') str2=str+i+1;
  }
  last=str+i-1;

  //str2=strchr(str,',')+1;
  str1=str+2;

  if(str[0]=='_') ans=min(str1,str2,last,bad);
  else if(str[0]=='^') ans=max(str1,str2,last,bad);
  return ans;
}

int max(char *str1,char *str2,char *last,int bad){
  //printf("max str1=%d\tstr2=%d\n",str1-input,str2-input);
  int first,second;
  if(str1[0]!='_' && str1[0]!='^'){
    char tmp[3];
    strncpy(tmp,str1,2);
    first=strtol(str1,NULL,0);
  }
  else first=calc(str1,bad);

  if(bad!=-1 && bad>=100 && first>=bad/100){
    nowmax=MAX(nowmax,str1+1-input);
    return first;
  }

  if(first==99){
    nowmax=MAX(nowmax,str2-2-input);
    return first;
  }else if(first>=10 && isdigit(str2[0]) && str2[0]-'0'<first/10){
    nowmax=MAX(nowmax,str2-input);
    return first;
  }

  if(str2[0]!='_' && str2[0]!='^'){
    char tmp[3];
    strncpy(tmp,str2,2);
    second=strtol(tmp,NULL,0);
    nowmax=MAX(nowmax,str2+1-input);
  }else{
    second=calc(str2,first);
  }
  //printf("first=%d VS second=%d -> WIN=%d\n",first,second,MAX(first,second));
  
  return MAX(first,second);
}

int min(char *str1,char *str2,char *last,int bad){
  //printf("min str1=%d\tstr2=%d\n",str1-input,str2-input);
  int first,second;
  if(str1[0]!='_' && str1[0]!='^'){
    char tmp[3];
    strncpy(tmp,str1,2);
    first=strtol(tmp,NULL,0);
  }
  else first=calc(str1,bad);

  if(bad!=-1 && bad<=99 && first<=bad){
    nowmax=MAX(nowmax,str1+1-input);
    return first;
  }

  if(first==0){
    nowmax=MAX(nowmax,str2-2-input);
    return first;
  }else if (first<10 && isdigit(str2[0]) && str2[0]-'0'>=first){
    nowmax=MAX(nowmax,str2-input);
    return first;
  }

  if(str2[0]!='_' && str2[0]!='^'){
    char tmp[3];
    strncpy(tmp,str2,2);
    second=strtol(str2,NULL,0);
    nowmax=MAX(nowmax,str2+1-input);
  }else{
    second=calc(str2,first*100);
  }
  // printf("first=%d VS second=%d -> WIN=%d\n",first,second,MIN(first,second));
  
  return MIN(first,second);
}
