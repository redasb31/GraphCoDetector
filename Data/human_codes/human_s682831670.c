/*
AizuOnline A2374
Title Rabbit Lunch
13/8/3 TLE 10/35
*/
#include <stdio.h>
int M,N,m0,n0,md,nd;
int m[2500000];
int n[2500000];
//
void test_parameter()
{
        M=N=3;
        m[0]=n[0]=3;
        m[1]=n[1]=3;
        m[2]=n[2]=3;
}
void make_parameter()
{
        int i;

        m[0]=m0;
        n[0]=n0;

        for(i=0;i<M-1;i++)
        {
                m[i+1]=(m[i]*58 + md)%(N+1);
        }

        for(i=0;i<N-1;i++)
        {
                n[i+1]=(n[i]*58 + nd)%(M+1);
        }
}
int compare(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}
int solve()
{
        int i,j,ret,c,p1,p2;

        qsort(n,N,sizeof(int),compare);
#ifdef DEBUG
        for(j=0;j<N;j++)
                printf("%d:",n[j]);
        printf("\n");
#endif                        
 
        ret=0;
        for(i=0;i<M;i++)
        {
                c=0;
                if(m[i]<N)
                        c=n[m[i]];
                for(j=0;j<m[i];j++)
                {
                        if(n[j]==0)
                                break;
                        else
                        {
                                n[j]--;
                                ret++;
#ifdef DEBUG
                                printf("(%d-%d)",i,j);
#endif
                        }
                }
#ifdef DEBUG
                        for(j=0;j<N;j++)
                                printf("%d:",n[j]);
#endif                        
                if(c>0)
                {
                        for(j=m[i]-1,p1=0;j>=0;j--,p1++)
                                if(n[j]!=c-1)
                                        break;
                        for(j=m[i],p2=0;j<N;j++,p2++)
                                if(n[j]!=c)
                                        break;
#ifdef DEBUG
                        printf("c=%d P1=%d P2=%d\n",c,p1,p2);
#endif
                        if(p2>0)
                                qsort(n+(m[i]-p1),p1+p2,sizeof(int),compare);
                }
#ifdef DEBUG
                        for(j=0;j<N;j++)
                                printf("%d:",n[j]);
                        printf("\n");
#endif                        
        }
        return(ret);
}
main()
{

#ifdef DEBUG1
        test_parameter();
#else
        scanf("%d %d %d %d %d %d",&M,&N,&m0,&md,&n0,&nd);
        make_parameter();
#endif
        printf("%d\n",solve());
return(0);
}