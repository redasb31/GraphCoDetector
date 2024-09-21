#include<stdio.h>
int main()
{
    long long int A,B;
    char C;

    scanf("%lli %c %lli", &A , &C, &B);

    if(C=='+')
        printf("%d\n",A+B);
    else if(C=='-')
        printf("%d\n",A-B);
        else
            return;
}
