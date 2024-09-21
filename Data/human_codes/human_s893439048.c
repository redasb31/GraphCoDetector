// AtCoder165 C

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <memory.h>
#include <malloc.h>
#include <stdlib.h>
#include <ctype.h>

// qsortで用いる比較用関数．*a<*bならaが先になる．
int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int revcompare(const void* a, const void* b) {
    return *(int*)b- *(int*)a;
}

double dmax(double x, double y){
    if(x < y) return y;
    return x;
}

int main() {
    int i,j;
    int n;
    int x;
    int* a;

    scanf("%d %d", &n, &x);
    a = (int*)malloc(sizeof(int) * n);

    for(i = 0; i < n; i++){
        scanf("%d", a+i);
    }

    qsort(a, n, sizeof(int), compare);
    int cnt = 0;
    int distributed = 0;
    for(i = 0;i < n; i++){
        distributed += a[i];
        if(distributed > x) break;
        cnt++;
    }

    if(distributed < x) cnt--;
    printf("%d", cnt);
    return 0;

}