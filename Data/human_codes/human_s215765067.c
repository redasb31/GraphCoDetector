#include<stdio.h>

void quicksort(int a[], int left, int right){
    int p;
	int L = left, R = right;
	int temp;
	p = a[(left + right) / 2];

	while (1){
		while (a[L] < p) L++; while (a[R] > p)
			R--;
		
		if (L >= R)
			break;

		temp = a[R];
		a[R] = a[L];
		a[L] = temp;

		L++;
		R--;
	}
	if (left < L - 1) quicksort(a, left, L - 1);
     if (right > R + 1)quicksort(a, R + 1, right); 
	
}

int main(){
    int a, b, n, i, j;
    int A[100000];
    int tmp;
    int x = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    quicksort(A, 0, n - 1);
    a = n/2;
    x = A[a] - A[a-1];
    printf("%d\n", x);
    return 0;
}