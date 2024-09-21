
/*
  AOJ 1078
  Title:SAT-EN-3
  @kankichi573
*/
#include <stdio.h>
#include <string.h>
char exp_[501];
char literal[3][250];
int lit_cnt;

int x_and_not_x(char e1[],char e2[])
{
        //printf("e1e2=%s %s\n",e1,e2);


        if(e1[0]=='~')
                return(0==strcmp(&e1[1],e2));
        if(e2[0]=='~')
                return(0==strcmp(e1,&e2[1]));
        return(0);
}
int check()
{
        int i,j;

        if(lit_cnt<=1)
                return(1);
        for(i=0;i<lit_cnt-1;i++)
                for(j=i+1;j<lit_cnt;j++)
                        if(x_and_not_x(&literal[i][0],&literal[j][0]))
                                return(0);
        return(1);
}



int satis_clause(char exp_[])
{
        char *p;
        char buf[500];

        strcpy(buf,exp_);
        lit_cnt=3;

        if(buf[strlen(buf)-1]==')')
                buf[strlen(buf)-1]='\0';
        //printf("S1:%s\n",buf);

        sscanf(buf,"%[^&]&%[^&]&%s",&literal[0][0],&literal[1][0],&literal[2][0]);
        //printf("*>%s:%s:%s\n",&literal[0][0],&literal[1][0],&literal[2][0]);
        
        return(check());
}

int satisfiable(char exp_[])
{
        char *p;
        int ret;

        if(NULL==strchr(exp_,'|'))
                return(satis_clause(exp_+1));
        p=strtok(exp_,"|");
        do
        {
                //printf("s0=%s\n",p);

                ret=satis_clause(p+1);

                //printf("ret=%d\n",ret);

                if(ret)
                        return(1);

        }
        while(p=strtok(NULL,"|"));

        return(0);
}

main()
{
        while(EOF!=scanf("%s",&exp_[0]) && exp_[0]!='#')
        {
                printf("%s\n",satisfiable(exp_)?"yes":"no");
        }
  return(0);
}