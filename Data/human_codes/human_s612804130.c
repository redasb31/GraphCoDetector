#include<stdio.h>


int main(void)
{

    int n,i,a,b,c,d,e,j;

    scanf("%d",&n);

    int P[n][3];

    e=0;

    for(i=0;i<n;i++){

        a=0;

        b=0;

        c=0;

        scanf("%d %d %d",&a,&b,&c);

        P[i][0]=a;

        P[i][1]=b;

        P[i][2]=c;

        if(a>b){

            d=P[i][0];

            P[i][0]=P[i][1];

            P[i][1]=d;

        }

        if(a>c){

            d=P[i][0];

            P[i][0]=P[i][2];

            P[i][2]=d;

        }

        if(b>c){

            d=P[i][1];

            P[i][1]=P[i][2];

            P[i][2]=d;

        }

    }

    for(i=0;i<n;i++){

        for(j=i+1;j<n;j++){

            if(P[i][0]==P[j][0]){

                if(P[i][1]==P[j][1]){

                    if(P[i][2]==P[j][2]){

                        e++;

                        P[i][0]='\0';

                    }

                }

            }

        }

    }

    printf("%d",e);

    return(0);

}