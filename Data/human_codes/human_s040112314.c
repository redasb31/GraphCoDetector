#include <stdio.h>

int current;

void pushBack(int x, int *A);
void randomAccess(int p, int *A);
void popBack(int *A);

int main(void)
{
    int q;
    int a,b;
    
    scanf("%d\n",&q);
    int A[q];

    while(scanf("%d",&a) != -1){
        
        if(a == 0 || a == 1){
            scanf("%d", &b);
        }
        switch(a){
            case 0:
            pushBack(b, A);
            current++;
            break;
            
            case 1:
            randomAccess(b, A);
            break;
            
            case 2:
            popBack(A);
            current--;
            break;
            
        }
    }

	return 0;
}

void pushBack(int x, int *A){
    A[current] = x;
}

void randomAccess(int p, int *A){
    printf("%d\n",A[p]);
}

void popBack(int *A){
    A[current - 1] = '\0';
}

