/*
 * FileName:     bit_flag_sample
 * CreatedDate:  2020-07-27 01:27:23 +0900
 * LastModified: 2020-07-27 20:23:47 +0900
 */

#include <stdio.h>

int main(void){
    unsigned long long int bit = 0;
    int q;scanf("%d", &q);
    for(int i=0; i<q; i++){
        int command;scanf("%d", &command);
        if( 0<=command && command<=3 ){
            int t;scanf("%d", &t);
            if( command==0 ){
                if(bit>>t&1UL)printf("1\n");
                else printf("0\n");
            }
            else if( command==1 ){
                bit |= 1UL<<t;
            }
            else if( command==2 ){
                bit &= ~(1UL<<t);
            }
            else{
                bit ^= (1UL<<t);
            }
        }
        else{
            if( command==4 ){
                printf("%d\n", !(bit+1));
            }
            else if( command==5 ){
                if( bit==0 ){
                    printf("0\n");
                }
                else{
                    printf("1\n");
                }
            }
            else if( command==6 ){
                printf("%d\n", bit==0);
            }
            else if( command==7 ){
                printf("%d\n", __builtin_popcountll(bit));
            }
            else{
                printf("%llu\n", bit);
            }
        }
//        printf("%lld\n", bit);
    }
    return 0;
}

