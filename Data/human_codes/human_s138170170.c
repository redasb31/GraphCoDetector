#include <stdio.h>
#include <stdlib.h>

typedef struct weight_
{
    int Num;
    int Wei;
    double OneNum;
}wgt;

int main()
{
    int N,W;
    double d1,d2,tmp=0;
    scanf("%d %d",&N,&W);
    wgt box;
    wgt *X = malloc(sizeof(wgt)*N);
    for(int i=0;i<N;i++)
    {
        scanf("%lf%lf",&d1,&d2);
        X[i].Num = d1;
        X[i].Wei = d2;
        X[i].OneNum = d1/d2;
    }
    for(int i=0;i<N;i++)
    {
        for(int l=N-1;i<l;l--)
        {
            if(X[l].OneNum>X[l-1].OneNum)
            {
                box = X[l];
                X[l] = X[l-1];
                X[l-1] = box;
            }
    }
    for(int i=0;i<N;i++)
    {
        if(X[i].Wei < W)
        {
            tmp += X[i].Wei * X[i].OneNum;
            W = W - X[i].Wei;
        }
        else
        {
            tmp += X[i].OneNum * W;
            break;
        }
    }
    printf("%lf\n",tmp);
}
