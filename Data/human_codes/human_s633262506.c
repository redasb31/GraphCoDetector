#include <stdio.h>

int main(void){
    
    int c1, c2, c3;
    int sum, cnt=0;
    
    scanf("%d %d %d", &c1, &c2, &c3);
    sum = c1+c2;
    
    for(int i=1; i<=10; i++){
        if( (i != c1)&&(i != c2)&&(i != c3) ){
            if( (sum+i) < 21 ) cnt++;
        }
    }
    
    if(cnt >= 4) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}