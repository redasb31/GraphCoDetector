#include<stdio.h>
int main(void){
    int i,j,k;
    int x = 0;
    int count = 1;
    scanf("%d",&k);
    int abc[k-1];
    for(i=0;i<k;i++){
        scanf("%d",&abc[i]);
    }
    for(j=1;j<k;j++){
        if(abc[x] >= abc[j]){
        if ((abc[x] - abc[j])<k){
        count = count + 1;
        x = x + 1;
        }
        else 
        {
            if ((abc[j] - abc[x])<k){
            count = count + 1;
            x = x + 1;
        } 
        }
        
    }
    }
    printf("%d",count);
    return 0;

}