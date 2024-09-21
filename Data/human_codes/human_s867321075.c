#include <stdio.h>

int main(){
int y,m,d;
char s[10];
while(scanf("%s%d%d%d",s,&y,&m,&d)==4){
    if(s=="#"){
        break;
    }
    else
    {
        if(y<=30){
            printf("%s %d %d %d\n","HEISEI",y,m,d);
        }
        else if(y==31 && m>=5){
            printf("%c %d %d %d\n",'?',y-30,m,d);
        }
        else if(y>31){
            printf("%c %d %d %d\n",'?',y-30,m,d);
        }
        else{
             printf("%s %d %d %d\n","HEISEI",y,m,d);
        }
    }
}
    return 0;
}
