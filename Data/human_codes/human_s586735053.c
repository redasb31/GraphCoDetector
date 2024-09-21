#include <stdio.h>
#include <string.h>

int main(void){
    int n;
    scanf("%d",&n);
    int a[n],a_flag[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        a_flag[i]=0;
    }

    int k=0;
    int count,flag;
    int all=0;
    int pair;
    do{
        count=0;
        for(i=k;i<n;i++){
            if(a[k]==a[i]){
                a_flag[i]=1;
                count++;
            }
        }
        all+=count*(count-1)/2;

        flag=0;
        for(i=k+1;i<n;i++){
            if(a[i]!=a[k] && a_flag[i]==0){
                k=i;
                flag=1;
                break;
            }
        }
    }while(flag==1);


    for(k=0;k<n;k++){
        count=0;
        pair=0;
        for(i=0;i<n;i++){
            if(a[k]==a[i]){
                count++;
            }
        }
        //pair+=count*(count-1)/2;
        printf("%d\n",all-(count-1));
    }

    return 0;
}