/*
  AOJ0174 
  Title:Badminton
  @kankichi573
*/
#include <stdio.h>
#include <string.h>

char solve(char buf[])
{
        int i,acnt,bcnt;
        acnt=bcnt=0;
        for(i=1;i<strlen(buf);i++)
        {
                if(buf[i]=='A')
                        acnt++;
                if(buf[i]=='B')
                        bcnt++;           
        }
        if(acnt==10 && bcnt < 10)
                printf("11 %d\n",bcnt);
        else if(bcnt==10 && acnt < 10)
                printf("%d 11\n",bcnt);
        else if(acnt > 10 && acnt > bcnt)
                printf("%d %d\n",acnt+1,bcnt);
        else if(bcnt > 10 && bcnt > acnt)
                printf("%d %d\n",acnt,bcnt+1);

}
main()
{
        int i,ret;
        char buf[100];

        while(scanf("%s",&buf[0]) && buf[0]!='0')
        {
                solve(buf);
        }
  return(0);
}