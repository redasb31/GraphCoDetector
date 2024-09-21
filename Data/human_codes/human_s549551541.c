
#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],odd=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]%2==1)odd++;
    }
    if(odd==0)printf("second");
    else printf("first");

    return 0;
}
