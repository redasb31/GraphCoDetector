/*
AizuOnline A1203
Title
*/
#include <stdio.h>
// Select Below
//#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include <float.h>
//#include <math.h>
//#include <limits.h>
//Global data section
#define MAX_INPUT 1024
char input_s[MAX_INPUT+1];
char input_s2[MAX_INPUT+1];
int out_p;
char *out[MAX_INPUT/3];
int  out_len[MAX_INPUT/3];

int cnt;
//
int is_parin0(char * s,int len,int flag)
{
       if(len==0 || len==1)
                return(flag);
 
        if(s[0]==s[len-1])
                return(is_parin0(s+1,len-2,-1));
        else
                return(0);
}
void regist_string(char *s,int len)
{
        int i;

#ifdef DEBUG
        printf("\np%d %d:",len,out_p);
        for(i=0;i<len;i++)
                printf("%c",s[i]);
#endif
        for(i=0;i<out_p;i++)
                if(0==strncmp(s,out[i],len) && len == out_len[i])
                {
#ifdef DEBUG
                        printf("ALREADY REG\n");
#endif            
                        return;
                }
        out[out_p]=s;
        out_len[out_p]=len;
        out_p++;
}

not_reject(char * s,int len)
{
        int i,j;
        char buf[MAX_INPUT+1];
        char buf2[MAX_INPUT+1];
        char *p;

       for(i=0;i<len;i++)
                buf[i]=s[i];
        buf[len]='\0';

        for(i=0;i<out_p;i++)
        {
                if(len > out_len[i]-2)
                        continue;
                for(j=0;j<out_len[i];j++)
                        buf2[j]=out[i][j];
                buf2[j]='\0';

                p=strstr(buf2+1,buf);
                if(p==NULL)
                        continue;
                if((p-buf2)*2==out_len[i]-len) 
                        return(0);
                else
                        continue;
        }
        return(-1);

}
void print_result()
{
        int i,j,flag=0;

        for(i=0;i<out_p;i++)
        {

                        
                if(not_reject(out[i],out_len[i]))
                {
                        if(flag)
                                printf(" ");
                        for(j=0;j<out_len[i];j++)
                        {
                                printf("%c",toupper(out[i][j]));
                        }
                        flag=-1;
                }
        }
        printf("\n");


}
void find_parin(char *s,int len)
{
        char *sp,*nextp;

        if(len==1)
                return;
        sp=s+1;
        while(1)
        {
                nextp=strchr(sp,s[0]);
                if(!nextp)
                        return;
                if(is_parin0(s,nextp-s+1,0))
                {
                                regist_string(s,nextp-s+1);
                }
                sp=nextp+1;
        }
}
void erase_sp(char * s,char * d)
{
        int i,j;

        for(i=0,j=0;s[i];i++)
                if(isalpha(s[i]))
                        d[j++]=s[i];
        d[i]='\0';
}
main()
{
        int i,len;
        while(NULL!=fgets(input_s,MAX_INPUT+1,stdin))
                {
                        erase_sp(input_s,input_s2);
                        len=strlen(input_s2);
                        cnt=0;out_p=0;
                        for(i=0;input_s2[i];i++)
                        {
                                find_parin(input_s2+i,len-i);
                        }
                        print_result();
                        memset(input_s,'\0',MAX_INPUT+1);
                        memset(input_s2,'\0',MAX_INPUT+1);
                }

return(0);
}