#include<stdio.h>
int main(){
char ch[10001];
int i=0,joi=0,ioi=0;
while(scanf("%s\n",&ch)!=EOF){
while(1){
if(ch[i]=='\0') break;
if(ch[i]=='J'&&ch[i+1]=='O'&&ch[i+2]=='I')joi++;
if(ch[i]=='I'&&ch[i+1]=='O'&&ch[i+2]=='I')joi++;
i++;
}
i=0;
printf("%d\n%d\n",joi,ioi);
}
return 0;
}