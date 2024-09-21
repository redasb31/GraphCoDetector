#include <stdio.h>

int sosu(int a)
{
    switch(a){
        case 1 : return  2; break;
        case 2 : return  3; break;
        case 3 : return  5; break;
        case 4 : return  7; break;
        case 5 : return 11; break;
        case 6 : return 13; break;
        case 7 : return 17; break;
        case 8 : return 19; break;
        case 9 : return 23; break;
        case 10: return 29; break;
        case 11: return 31; break;
        case 12: return 37; break;
        case 13: return 41; break;
        case 14: return 43; break;
        case 15: return 47; break;
        case 16: return 53; break;
        case 17: return 59; break;
        case 18: return 61; break;
        case 19: return 67; break;
        case 20: return 71; break;
        case 21: return 73; break;
        case 22: return 79; break;
        case 23: return 83; break;
        case 24: return 89; break;
        case 25: return 97; break;
        default : return 0;
    }
}

int main(void)
{
    int a[24];
    int ans1 = 0; int ans2 = 0; int ans3 = 0;
    int no, n, i, j, k, l, ans;
    scanf("%d",&no);
    ans = 0;
    for(j = 0; j <= 24; j++){
        a[j] = 0;
//        printf("%2d ",j);
    }
    printf("\n");
    for(i = 1; i <= no; i++){
        n = i;
        for (j = 1; j <=25; j++) {
            while(n % sosu(j) == 0){
                a[j - 1] += 1;
                n /= sosu(j);
            }
//            printf("%2d ",a[j-1]);
        }
//        printf("  %2d\n",i);
    }
    for(j = 0; j <= 24; j++){
        for(k = 0; k <= 24; k++){
            for(l = 0; l <= 24; l++){
                if(j < k && j != l && k != l){
                    if(a[j] >= 4 && a[k] >= 4 && a[l] >= 2){
//                        printf("%d^4-%d^4-%d^2\n",sosu(j+1),sosu(k+1),sosu(l+1));
//                        printf("%d %d %d\n",j+1,k+1,l+1);
                        ans1++;
                        ans++;
                    }
                }
            }
            if(j != k){
                if(a[j] >= 14 && a[k] >= 4){
//                    printf("                     %d^14-%d^4\n",sosu(j+1),sosu(k+1));
                    ans++;
                    ans2++;
                }
                else if(a[j] >= 24 && a[k] >= 2){
//                    printf("                     %d^24-%d^2\n",sosu(j+1),sosu(k+1));
                    ans++;
                    ans2++;
                }
            }
        }
        if(a[j] >= 74){
//            printf("                                            %d^74\n",sosu(j+1));
            ans++;
            ans3++;
        }
    }
    printf("%d",ans);
    
    return 0;
}