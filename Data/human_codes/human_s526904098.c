#include <stdio.h>

int main()
{
    int i, j, n, x, p, q, r, s, count = 0;
    scanf("%d", &n);
    int A[n];
    for(i = 0; i < n; i++) scanf("%d", &A[i]);
    
    p = 0;
    r = n - 1;
    x = A[r];
    i = p-1;
    for (j = p; j <= r; j++){
     if (A[j] <= x){
       i = i + 1;
        s = A[i];
       A[i] = A[j];
       A[j] = s;
   //s = A[i+1];
   //A[i+1] = A[r];
   //A[r] = s;
     }
    }
    for(i = 0; i < n; i++) if(A[i] == x) count++;
   for(i = 0; i < n - 1; i++){
       if(count == 1) {
           if(A[i] == x) printf("[%d] ", A[i]);
           count = 0;
           continue;
       }
           if(count == 2) {
               if(A[i] == x) count--;
       }
       printf("%d ", A[i]);
   }
   printf("%d\n", A[n - 1]);
    return 0;
}
