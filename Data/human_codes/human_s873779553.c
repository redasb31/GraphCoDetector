#include <stdio.h>
#define N 1000000
int main(void){
    int a[N][1001],n,q,query,x,t,back[N],j;
    scanf("%d",&n);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d %d",&query,&t);
        if(back[t]=='NULL') back[t]=0;
//printf("t=%d:%d ",t,back[t]);
//        printf("q=%d t=%d\n",query,t);
        if(query==2) {
            for(j=0;j<n;j++) a[t][j]='NULL';
        }
        else if(query==1){
            j=0;
            for(;;){

                if(a[t][j]!='NULL') {
                    printf("%d",a[t][j]);
                    if(a[t][j+1]!='NULL') printf(" ");
                }
//                printf("%d\n",a[t][j]);
                j++;
                
                if(j==n||a[t][j]==0) {
                    printf("\n");
                    break;
                }
            }

        }
        else if(query==0){
            scanf("%d",&x);
//            if(back[t]!=0) 
            a[t][back[t]]=x;
//            printf("a[%d][%d]=%d\n",t,back[t],a[t][back[t]]);
            back[t]++;
        }
    }
    return 0;
}

