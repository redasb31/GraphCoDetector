#include <stdio.h>
#define printArray(array, alen) \
    do{ \
        for(int i = 0; i < alen; i++){ \
            fprintf(stderr, "%d ", array[i]); \
        } \
        fprintf(stderr, "\n"); \
    }while(0)

void QSort(int x[ ], int left, int right);
void Swap(int x[ ], int i, int j);


void QSort(int x[ ], int left, int right)
{
    int i, j;
    int pivot;

    i = left;                      /* ソートする配列の一番小さい要素の添字 */
    j = right;                     /* ソートする配列の一番大きい要素の添字 */

    pivot = x[(left + right) / 2]; /* 基準値を配列の中央付近にとる */

    while (1) {                    /* 無限ループ */

        while (x[i] < pivot)       /* pivot より大きい値が */
            i++;                   /* 出るまで i を増加させる */

        while (pivot < x[j])       /* pivot より小さい値が */
            j--;                   /*  出るまで j を減少させる */
        if (i >= j)                /* i >= j なら */
            break;                 /* 無限ループから抜ける */

        Swap(x, i, j);             /* x[i] と x[j]を交換 */
        i++;                       /* 次のデータ */
        j--;
    }

    if (left < i - 1)          \
        QSort(x, left, i - 1); 
    if (j + 1 <  right) 
        QSort(x, j + 1, right);
}

void Swap(int x[ ], int i, int j)
{
    int temp;

    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}

int ncmp(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        if(a[i] != b[i])
            return 1;
    }
    return 0;
}

int main() {
    int a,b;
    scanf("%d %d", &a, &b);
    int p[a];
    for (int i = 0; i < a; i++) {
        scanf("%d", &p[i]);
    }
    int ans = 0;
    
    for (int i = 0; i+b-1 < a; i++) {
        int def[b];
        for (int j = 0; j < b; j++)
            def[j] = p[i+j];
        int sorted[b];
        for (int j = 0; j < b; j++)
            sorted[j] = p[i+j];
        printArray(sorted, b);

        QSort(sorted, 0, b);
        printArray(sorted, b);

        ans += ncmp(def, sorted, b);
    }

    printf("%d\n", ans);
}
