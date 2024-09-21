#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{   char s[200001];
    scanf("%s",s);
    int l=strlen(s),ht=0,th=0;
    if(l==1){
        printf("1");
        return 0;
    }
    for(int i=0;i<l-1;i++){
        if(s[i]==s[i+1]){
            if(i<l-2&&s[i+1]==s[i+2]){
                ht++;i++;
            }else if(i==l-2){
                ht++;
                i++;
            }else{
                ht+=2;
                i+=2;
            }
        }else{
            ht++;
            if(i==l-2){
                ht++;
            }
        }
    }
    for(int i=l-1;i>0;i--){
        if(s[i]==s[i-1]){
            if(i>1&&s[i-1]==s[i-2]){
                th++;i--;
            }else if(i==1){
                th++;
                i--;
            }else{
                th+=2;
                i-=2;
            }
        }else{
            th++;
            if(i==1){
                th++;
            }
        }
    }
    int ans=ht>th?ht:th;
    printf("%d",ans);

    return 0;
}
