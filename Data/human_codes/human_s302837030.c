#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int descending_compare(const void *a, const void *b){
    if (*(long long*)a > *(long long*)b){
        return -1;
    }else if (*(long long*)a == *(long long*)b){
        return 0;
    }else{
        return 1;
    }
}

int ascending_compare(const void *a, const void *b){
    if (*(int*)a < *(int*)b){
        return -1;
    }else if (*(int*)a == *(int*)b){
        return 0;
    }else{
        return 1;
    }
}


int lower_bound(int *a, int n, int key){
    int left, mid, right;
    left = 0, right = n;
    mid = (left + right)/2;
    while ((left+1 != mid || mid+1 != right) && mid != left){
        if (key > a[mid]){
            left = mid;
        }else{
            right = mid+1;
        }
        mid = (left + right)/2;
    }
    if (a[left] >= key)return left;
    if (a[mid] >= key)return mid;
    if (a[right] >= key)return right;
    return n;
}

//greatest common divisor
unsigned long gcd(unsigned long x, unsigned long y){
    if (y == 0){ 
        return x;
    }else if (x > y){
        return gcd(y, x % y);
    }else{
        return gcd(x, y % x);
    }
}

unsigned long lcm(unsigned long x, unsigned long y){
    unsigned long g = gcd(x, y);
    return x*y/g;

}



long long factorial(int x){
    long long rtn = 1;
    int i;
    for (i = x; i > 1; i--){
        rtn = (rtn*i);
    }
    return rtn;
}

/*
int struct_ascending_compare(const void *p, const void *q) {
return ((struct_name*)p)->member_name - ((struct_name*)q)->member_name;
}*/

/*unsigned long long pascal[100][100] = {0};
void make_pascal(void){
    for (int i = 0; i < 100; i++){
        pascal[i][0] = 1;
    }
    pascal[1][1] = 1;
    for (int i = 2; i < 100; i++){
        for (int j = 1; j < 100; j++){
           pascal[i][j] = (pascal[i-1][j-1]+pascal[i-1][j]);
        }
    }
}*/
long long mod = 1000000007;

long long mod_pow(long long x, long long n){
    long long res = 1;
    for(int i = 0;i < 60; i++){
        if(n >> i & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

long long digit_sum(long long b, long long n){
    if (n < b) return n;
    return digit_sum(b, n/b) + n % b;
}

int main(void){
    long long n, s;
    scanf("%lld %lld", &n, &s);
    int root_n = sqrtl(n);
    for (int b = 2; b <= root_n; b++){
        if (s == digit_sum(b, n)){
            printf("%d\n", b);
            return 0;
        }
    }

    int root_n_s = sqrtl(n-s);
    for (long long i = root_n_s; i >= 1 ; i--){
        if ((n-s)%i == 0){
            if (s == digit_sum((n-s)/i+1, n)){
                printf("%lld\n", (n-s)/i+1);
                return 0;
            }
        }
    }
    if (n == s){
        printf("%lld", n+1);
        return 0;
    }
    printf("-1\n");

    return 0;
}