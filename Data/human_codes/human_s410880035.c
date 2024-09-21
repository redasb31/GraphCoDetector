#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

struct tree
{
    int wei;
    double l,r,m;
    int is;

}tr[MAX];

double r;
int s,w[7];
int jie[8];

int queen[MAX];
int tail=0;

int  calcw(int rt)
{
    int l=0,r=0;
    if(tr[rt].wei!=0)
    return tr[rt].wei;
    else
    {
        if(tr[2*rt].is==1)
        l=calcw(2*rt);
        if(tr[2*rt+1].is==1)
        r=calcw(2*rt+1);

        tr[rt].wei=l+r;
        return l+r;
    }

}

double calclr()
{
    int i;
    double min=9999999,max=-999999;

    tr[1].m=0;

    for(i=1;i<MAX;++i)
    {

        if(2*i+1<MAX&&tr[i*2].is==1)
        {
            double sum=tr[2*i].wei+tr[i*2+1].wei;

            tr[i].l=tr[i].m-tr[i*2+1].wei/sum;
            tr[i].r=tr[i].m+tr[i*2].wei/sum;
            min=min>tr[i].l?tr[i].l:min;
            max=max>tr[i].r?max:tr[i].r;

            tr[i*2].m=tr[i].l;
            tr[i*2+1].m=tr[i].r;

        }
    }

    return max-min;
}

void in(int n)
{
    int i;
    for(i=tail;i>n;--i)
    {
        queen[i]=queen[i-1];
    }
    queen[n]=queen[n+1]*2;
    queen[n+1]+=queen[n+1]+1;
    tr[queen[n]].is=1;
    tr[queen[n+1]].is=1;

    tail++;
}

int main()
{


    int i,t,j,l;
    double max;
    jie[0]=1;
    for(i=1;i<8;++i)
    jie[i]=jie[i-1]*i;


    scanf("%d",&t);
    for(;t>0;--t)
    {
    max=0;
    scanf("%lf%d",&r,&s);
    for(i=0;i<s;++i)
    scanf("%d",w+i);

        for(i=0;i<jie[s];++i)
        {
            int k=2;
            int pos=i;


            tail=0;
            memset(tr,0,sizeof(tr));
            queen[tail++]=1;
            in(0);

            tr[1].is=1;

            for(;k<s;++k)
            {
                in(pos*jie[k]/jie[s]);
                pos=pos%(jie[s]/jie[k]);


            }



            for(j=0;j<jie[tail];++j)
            {
                int k=tail-1;
                int nhh;
                int pos=j;
                int sub;
                double temp;

                int pailie[6];
                for(nhh=0;nhh<5;++nhh)
                pailie[nhh]=0;

                for(l=0;l<tail;++l)
                {
                    int i;

                    sub=pos/jie[k];
                    for(i=0;sub!=0||pailie[i]==1;)
                    {
                        if(pailie[i]==1)
                        ++i;
                        else if(pailie[i]==0)
                        {
                            --sub;
                            ++i;}

                    }
                    pailie[i]=1;
                    pos=pos%jie[k];
                    --k;
                    tr[queen[l]].wei=w[i];
                }

                calcw(1);
                temp=calclr();
                if(temp<=r)
                max=max>temp?max:temp;



            }





        }

        if(max>0)
        printf("%.16lf\n",max);
        else
        printf("-1\n");

    }
    return 0;
}