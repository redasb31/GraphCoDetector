#include<stdio.h>
int main(){
  char s[1001];
  int i,n1,n2;
  while(fgets(s,1000,stdin)!=NULL){
   int n[1000]={0};
   int sum=0,c=0;
    for(i=0;s[i]!='\0';i++){
      c++;
      if(s[i]=='I')	n[i]=1;
      if(s[i]=='V')	n[i]=5;
      if(s[i]=='X')	n[i]=10;
      if(s[i]=='L')	n[i]=50;
      if(s[i]=='C')	n[i]=100;
      if(s[i]=='D')	n[i]=500;
      if(s[i]=='M')	n[i]=1000;
    }
    n1=n[0];
    for(i=1;i<c;i++){
      n2=n[i];
      if(n1>=n2){
	sum+=n1;
	n1=n2;
      }
      else{
	sum+=n2-n1;
	i++;
	n1=n[i];
      }
    }
    printf("%d\n",sum);
  }
}