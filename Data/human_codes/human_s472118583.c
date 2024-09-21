/*
AizuOnline A2020
Title Princess's Japanese
@kankichi573
*/
#include <stdio.h>
#include <string.h>
//char buf[101]="hottokouhii";
//char flag[101]={0,0,0,0,1,0,0,0,0,0,0};
char buf[102];
char flag[101];
//
int is_musei(char c)
{
        return(c=='k'||c=='s'||c=='h'||c=='t'||c=='p');
}
int is_boin(char c)
{
        return(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
int is_sokuon(char * s)
{
        if(!*s)
                return(0);
        return(!is_boin(*s) && *s==*(s+1));
}
char next_boin(char * s)
{
        int i;
        char c;

        for(i=1;i<4;i++)
        {
                if(!s[i])
                        return(0);
                if(is_boin(c=s[i]))
                return(c);
        }
        return(0);
}
int prev_boin_museika(char * s)
{
        s--;
        while(s >= buf)
        {
                if(is_boin(*s))
                        return(flag[s-buf]);
                s--;
        }
        return(0);
}
int is_musei_prev(char *s)
{
        if(s > buf && is_musei(s[-1]))
                return(1);
        if(s > buf+1 && is_musei(s[-2]) && (s[-1]=='y'))
                return(1);
        return(0);
}
int is_musei_next(char *s)
{
        if(!s[1])
                return(1);
        if(is_musei(s[1]))
                return(1);
}
int is_musei_hasami(char *s)
{
        return(is_musei_prev(s) && is_musei_next(s));
}
void solve()
{
        char *p,*f,c;
        p=buf+1;f=flag+1;

        while((c=*p))
        {
                //printf("C= %c\n",c);

                if(c=='i'||c=='u')
                         if(is_musei_hasami(p) &&
                           !prev_boin_museika(p))
                                *f=1;
                if(c=='a'||c=='o')
                {
                         if(is_musei_hasami(p) &&
                            !prev_boin_museika(p) &&
                            !is_sokuon(p+1))
                                if(c==next_boin(p))
                                        *f=1;
                }
                p++;f++;
        }
}
void write_result()
{
        char *p,*q,c;

        p=buf;q=flag;

        while(c=*p)
        {
                if(*q)
                        printf("(%c)",c);
                else
                        printf("%c",c);
                p++;q++;
        }
        printf("\n");
}

main()
{
        while(EOF!=scanf("%s",buf) && buf[0]!='#')
        {
                
                memset(flag,0,102);
                solve();
                write_result();
        }
        return(0);
}