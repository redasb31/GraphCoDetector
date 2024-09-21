#include <stdlib.h>
#include <stdio.h>

int main(){
    
    int i,n,a[100],q;
    int sum=0;
    int b[100],c[100];
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);

    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&b[i]);
        scanf("%d",&c[i]);
    
    }
    for(i=0;i<n;i++){
        if(a[i]==b[0]){
            a[i]=c[0];
        }
        sum +=a[i];
    }
        printf("%d\n",sum);           
        sum=0;    
    for(i=0;i<n;i++){
        if(a[i]==b[1]){
            a[i]=c[1];
        }
        sum +=a[i];
        }
        printf("%d\n",sum);
        sum=0;        
    for(i=0;i<n;i++){
        if(a[i]==b[2]){
            a[i]=c[2];
        }
        sum +=a[i];
    }    
    printf("%d\n",sum);

    return 0;
}
