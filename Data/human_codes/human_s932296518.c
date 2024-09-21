#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char input[100];
    char *tp;
    int n,q,x,y,t;
    int i,j;
    int **s;
    int *start_p, *end_p;

    if(fgets(input,sizeof input, stdin)!=NULL){
        tp=strtok(input," ");
        n=atoi(tp);
        tp=strtok(NULL," ");
        q=atoi(tp);
    }

    s=malloc(sizeof(int *) * n);
    for(i=0;i<n;i++)s[i]=malloc(sizeof(int)*1000000);

    start_p=calloc(n,sizeof(int));
    end_p=calloc(n,sizeof(int));

    for(i=0;i<q;i++){
        if(fgets(input,sizeof input, stdin)!=NULL){
            tp=strtok(input," ");
            y=atoi(tp);
            tp=strtok(NULL," ");
            t=atoi(tp);
            switch(y){
                case 0: tp=strtok(NULL," ");
                        x=atoi(tp);
                        s[t][end_p[t]]=x;
                        end_p[t]++;
                    break;
                case 1:
                    if(start_p[t]<end_p[t])printf("%d\n",s[t][start_p[t]]);
                    break;
                case 2:
                    if(start_p[t]<end_p[t])start_p[t]++;
                    break;
                default: break;
            }
        }
    }

    for(i=0;i<n;i++)free(s[i]);
    free(s);
    free(start_p);
    free(end_p);
    
    return 0;
}
