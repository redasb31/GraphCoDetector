#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
int compare(const void *a,const void *b){
    if(*(long long *)a>*(long long *)b)return 1;
    return -1;
}
int main()
{   int n,x;
    scanf("%d%d",&n,&x);
    int s[n];
    for(int i=0;i<n;i++){
    scanf("%d",&s[i]);
    }
    qsort(s,n,sizeof(int),compare);
    
    long long preans[200][200]={0};
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<i;j++){
            int cpy=x;
            cpy%=s[j];
            preans[i][j]=cpy%s[i];
            //printf("preans[%d][%d]=%lld",i,j,preans[i][j]);
        }
        preans[i][i]=x%s[i];
        printf("\n");
    }
    long long ans=0;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i;j++){
            if(j>0){
                int k=j;
                while(k>0){
                    preans[i][j]*=k;
                    preans[i][j]&=1000000007;
                    k--;
                }
            }
            if(i<n-1){
                int k=i;
                while((n-1)-k>0){
                    preans[i][j]*=((n-1)-k);
                    preans[i][j]%=1000000007;
                    k++;
                }
            }
        }
    }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<i;j++){   
        ans+=preans[i][j];
        ans%=1000000007;
        //printf("ans=%d\n",ans);
        }
    }
    printf("%lld",ans);
    return 0;
}
