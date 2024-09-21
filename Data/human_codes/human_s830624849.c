/*
  AOJ 2588
  Title:
  @kankichi573
*/
#include <stdio.h>

int e1,e2;
char op[2];

main()
{
        scanf("%d ",&e1);
        while(1)
        {    
                scanf("%s",op);

                if(*op=='=')   
                {
                        printf("%d\n",e1);
                        break;
                }
                scanf("%d",&e2);

                if(*op=='+')
                        e1+=e2;
                if(*op=='-')
                        e1-=e2;
                if(*op=='*')
                        e1*=e2;
                if(*op=='/')
                        e1/=e2;
        }
  return(0);
}