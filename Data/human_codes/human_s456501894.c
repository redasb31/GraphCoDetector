#include<stdio.h>
#include<string.h>
int main()
{
    long n,m,a[100000],r1,r2,t;
    char s[100000][4];
    long f[100000];  //记录每个录入的情况
    char f2[100000][4];
    while(scanf("%ld%ld",&n,&m)!=EOF)
    {
        int i,j,flag,k;
        memset(f,0,n*sizeof(long));

        r1=r2=0;
        for(i=0; i<m; ++i)
        {
            scanf("%ld",&a[i]);
            scanf("%s",s[i]);

        }
        k=0;
        for(i=0; i<m; ++i)
        {
            flag=0;
            for(j=0; j<k; ++j)
            {
                if(f[j]==a[i] && strcmp(f2[j],s[i])==0)  //如果存在flag=1
                {
                    flag=1;
                    //printf("***");
                }

            }
            if(flag==0)  //flag=0时说明没计入
            {
                if(strcmp("AC",s[i])==0)
                    r1++;
                if(strcmp("WA",s[i])==0)
                    r2++;
                f[k]=a[i];
                strcpy(f2[k],s[i]);  //flag=1说明计入
                k++;
            }

        }
        printf("%d %d\n",r1,r2);
    }
    return 0;
}


