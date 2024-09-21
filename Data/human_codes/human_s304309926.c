#include<stdio.h>

void swap(int*a, int* b){
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
}

int equal(int a[], int b[]){
        return a[0]==b[0] && a[1]==b[1] && a[2]==b[2];
}

int main(void){
        int n;
        scanf("%d", &n);

        int i, j, size = 0, prgn[n][3];

        for(i=0; i<n; i++){
                int a, b, c;
                scanf("%d %d %d", &a, &b, &c);
                if(a>b) swap(&a, &b);
                if(b>c) swap(&b, &c);
                if(a>b) swap(&a, &b);
                int tp[] = {a, b, c};

                int new = 1;
                for(j=0; j<size; j++){
                        if(equal(tp, prgn[j])) new = 0;
                }
                if(new){
                        prgn[size][0] = a;
                        prgn[size][1] = b;
                        prgn[size][2] = c;
                        size++;
                }
        }

        printf("%d\n", n-size);
        return 0;
}
