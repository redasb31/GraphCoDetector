#include<stdio.h>
#include<string.h>

int main() {
    long long int i, met, sum;
    long long int min, Max = 0, we = 1, number, x[100000], dx[100000];
    double reb;

    scanf("%lld", &number);

    min = number - 1;

    for(i=0;i<number;i++){
        scanf("%lld", &x[i]);
        if(i!=0) {
            met = x[0] - x[i];
            Max = Max - met;
            we = we * (i);
        }
    }

    for(i=min;i<=Max;i++) {
        sum = sum + i;
    }

    reb = (double)sum / (double)(number - 1) * we;

    printf("%d", (int)reb % 1000000007);

    return 0;

}
