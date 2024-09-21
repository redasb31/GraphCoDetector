#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int main()

{
    int n,k,i,j;
    scanf("%d %d",&n,&k);
    int num[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    int swap;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(num[i]<num[j])
            {
                swap=num[i];
                num[i]=num[j];
                num[j]=swap;
            }
        }
    }
    int sum=0;
    for(i=0;i<k;i++)
    {
        sum=sum+num[i];
    }
    printf("%d\n",sum);


    return 0;
}


/*
presented by codeRumi
thanks for watching & being here,thank me later... :)
*/

