#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int sort(const void *a, const void *b){return *(long long*)b-*(long long*)a;}
int main(void){
    int n,k,count=0;
    scanf("%d%d",&n,&k);
    int a[n];
    long long b[n*(n+1)/2],ans=0;
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for (int i=0; i<n; i++){
        long long sum=0;
        for (int j=i; j<n; j++){
            sum+=a[j];
            b[count]=sum;
            count++;
        }
    }
    int count2=0,p=0;
    qsort (b,count,sizeof(long long),sort);
    for (p=0; pow(2,p)<b[0]; p++){
    }
    p--;
    for (int i=p; i>=0; i--){
        count2=0;
        for (int j=0; j<count; j++){
            if (b[j]>=pow(2,i)){
                count2++;
            }
        }
        if (count2>=k){
            ans+=pow(2,i);
            for (int j=0; j<count; j++){
                if (b[j]<pow(2,i)){
                    b[j]=0;
                } else {
                    b[j]-=pow(2,i);
                }
            }
        } else {
            for (int j=0; j<count; j++){
                if (b[j]<pow(2,i)){
                } else {
                    b[j]-=pow(2,i);
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}