#include<stdio.h>
#include<string.h>
                         
                        int main(void){
                          int n;
                          int s;
                          scanf("%d/n",&n);
                          char str[];
                          
                          scanf("%s",str);
                          if((n%2)==0){
                            char t[];
                            for(int i=0;i<(n/2);i++){
                            t[i]=str[i];
                            }
                            strcat(t,t);
                            if(str==t){
                             printf("Yes\n");
                               return 0;
                            }
                          }
                          printf("No\n");
                         return 0; 
                        }