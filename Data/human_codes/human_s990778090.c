/*
AizuOnline A2243
Title step step revolution
*/
#include <stdio.h>
#include <string.h>
#define min(x,y) (((x)<(y))?(x):(y))

#define RIGHT 0
#define LEFT  1
char steps[100000];
int rl;
char prev_l=0,prev_r=0;
int call_cnt=0;
int valid_step(char next,int rl)
{
        int ret,p,n,prev;

        n=next -= '0'; n %= 3;if(n==0)n=3;
        prev=(rl==RIGHT)?prev_l:prev_r;
        p=prev; p %=3;if(p==0)p=3;

#ifdef DEBUG
        printf("N:%d (%d)PL:%d PR:%d=>%d\n",next,n,prev_l,prev_r,p);
        printf("rl%d p<N%d\n",rl==RIGHT,p<n);
#endif
        if(call_cnt==0)
        {
                call_cnt++;
                ret=-1;
        }
        else if(p==n)
                ret=-1;
        else if(rl==RIGHT && (p<n))
                ret=(-1);
        else if(rl==LEFT &&  (p>n))
                ret=(-1);
        else
                ret=(0);
        if((ret && rl==RIGHT) ||(!ret && rl==LEFT))
                prev_r=next;
        else
                prev_l=next;
#if DEBUG
        printf("rl=%s ret=%d\n",rl?"LEFT":"RIGHT",ret);
#endif
        return(ret);
}
int solve(char * steps)
{
        int last_foot,cnt;
        char *p;
 
        p=steps;
        cnt=0;prev_l=prev_r=1;call_cnt=0;
        for(;*p;p++)
        {
                if(valid_step(*p,rl))
                {
                        rl = 1-rl;
                }
                else
                {
                        cnt++;
                }
                //printf("PL:%d PR:%d\n",prev_l,prev_r);
        }
        return(cnt);
}
//
main()
{
        int cnt_r,cnt_l;

        while(scanf("%s",steps) && strcmp("#",steps))
        {
                rl=RIGHT;
                cnt_r=solve(steps);
                rl=LEFT;
                cnt_l=solve(steps);
                printf("%d\n",min(cnt_r,cnt_l));
                memset(steps,'\0',sizeof(memset));
        }
return(0);
}