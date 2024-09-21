#include <stdio.h>
#include <stdlib.h>

int main(void){
    int count = 0;
    int i=0;
    char text[9]={'\0'};
    scanf("%c", &text[i]);
    if(text[i]=='\n'){
        printf("No");
        return 0;
    }
    i++;
    while(text[i-1]!='\n'){
        scanf("%c", &text[i]);
        i++;
        if(i==10){
            break;
        }
    }
    for(int j = 0; j<10; j++){
        if(text[j]=='h'){
            if(text[j+1]=='i'&&text[j+1]!='\0'){
                if(text[j+2]!='\0'){
                    if(text[j+2]!='i'){
                        count++;
                        break;
                    }
                }
            }
        }
    }
    if(count == 1){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}