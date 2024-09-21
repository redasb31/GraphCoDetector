#include <stdio.h>
#define INF 100001

int main (void){
    int N;
    int a,b;
    int count[INF]={};//???????????°???????§????????????????????????£?????????????????°
    int i,max=0;
    
    scanf("%d", &N);
    while(N){
        scanf("%d %d",&a ,&b);
        for(a--;a!=b;a++){
           // printf("%d %d\n", a, b);
            count[a]++;
        }
    
        N--;
    }
    for(i=0;i<INF;i++){
        if(count[i] > i)
            count[i] = i;
        if(count[i] < i)
            count[i] = 0;
    }
    
    
    max = count[0];
    for(i=1;i<INF;i++){
        //if(i<10) printf("%d",count[i]);
        if(count[i] > max){
            max = count[i];
        }
    }
    
    printf("%d\n",max);
    return 0;
}