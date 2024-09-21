#include <stdio.h>
#include <string.h>
//Global data section
#define HASHSIZE 20011
char mark[10001][20];
char read_flag[10001];
int N;
int indx;
int next_index;
int reten;
char label[20];
int hash_table[HASHSIZE];
int hash_seed[20]={233,1054,137,1237,1097,1487,1619,1621,431,733,
                   1861,887,251,131,971,601,433,1471,1811,571};
//
int conv(char c)
{
        if(islower(c))
                return(c-'a'+1);
        if(isdigit(c))
                return('z'-'a'+1+c-'0');
}
int hash_func(char * s)
{
        int i;

        int ret;
        ret=0;
        for(i=0;s[i];i++)
                ret += hash_seed[i]*conv(s[i]);
        ret=ret % HASHSIZE;


        return(ret); 
}
int find_hash(char * s)
{
        int h,idx;
        h=hash_func(s);

        while(1)
        {       
                idx=hash_table[h];
#ifdef DEBUG
        printf("HASH*=%s:%d:%d\n",s,h,idx);
#endif

                if(idx==-1)
                        return(-1);

                if(0==strcmp(&mark[hash_table[h]][0],s))
                        break;
                h++;
                if(h>N)
                        return(-1);
        }
        return(h);
}
int regist_hash(char * s,int idx)
{
        int h;
        h=hash_func(s);
        
        while(-1 != hash_table[h])
        {
                h++;
                if(h>N)
                        return(-1);
        }
#ifdef DEBUG
        printf("HASH=%s:%d %d\n",s,h,idx);
#endif
        hash_table[h]=idx;
        return(0);
}
void clear_hash()
{
        int i;

        for(i=0;i<HASHSIZE;i++)
                hash_table[i]=-1;
}
int label_one_p(int idx)
{
        int id;
        char *p,c;
        p=&mark[idx][0];
        id=jump_mark_index(p);
        c=p[strlen(p)-1];
        if(id==1 && c!='v')
                return(-1);
        else
                return(0);
}

int jump_mark_index_label(int idx)
{
        int i,id,l,ret,idxx;
        char buf[20]; //label
        char c;

        i=0;
        while(islower(c=mark[idx][i]))
        {
                buf[i]=c;
                i++;
        }
        //buf[i]=0;
        id=jump_mark_index(&mark[idx][0]);
        sprintf(&buf[i],"%d\0",id+1);

        ret=find_hash(buf);
        if(ret==-1)
                return(-1);
        idxx=hash_table[ret];
#ifdef DEBUG
        printf("LAB=%s:HASH=%d idx=%d\n",buf,ret,idxx);
#endif                 
        return(idxx);
}
int jump_mark_index(char * s)
{
        char *p;
        p=&s[strlen(s)-1];
        if(*p=='v')
                p--;
        while(isdigit(*p))
                p--;
        return(atoi(p+1));
}
int next_char()
{
        char * p;

        if(indx==0)
        {
                while(1)
                {
                        indx++;
                        if(indx>N)
                                return(0);
                        if(label_one_p(indx))
                                return(-1);
                        if(mark[indx][0]=='-')
                                return(-1);
                }
        }
        else
        {
                indx=next_index;
                if(indx>N)
                        return(0);
        }
        return(-1);        
}
int is_reten(int  idx)
{
        char *s;
        s=&mark[idx][0];

        if(s[0]=='v')
                return(-1);
        if(s[strlen(s)-1]=='v')
                return(-1);
        return(0);
}
int is_jump_mark(int idx)
{
        int c;
        c=mark[idx][0];
        if(c!='v' && c!='-')
                return(-1);
        else
                return(0);
}

int calc_next()
{
        char c;

        if(indx>1 && is_reten(indx-1))
        {
                next_index = indx-1;
                return(-1);
        }

        if(is_jump_mark(indx))
        {
                next_index=jump_mark_index_label(indx);
                if(next_index==-1)
                        ;
                else
                        return(-1);
        }

        next_index=indx;
        while(1)
        {
                next_index++;
                if(next_index>N)
                        return(0);
                if(read_flag[next_index])
                        continue;
                if(label_one_p(next_index))
                        return(1);
                if(mark[next_index][0]=='-')
                        return(1);
        }
}
clear()
{
        int i;

        for(i=0;i<10000;i++)
                read_flag[i]=0;
}
main()
{
        int i;


        while(EOF!=scanf("%d",&N) && N)
        {
                clear();
                clear_hash();
                for(i=1;i<=N;i++)
                {
                        scanf("%s",&(mark[i][0]));
                        if(is_jump_mark(i))
                                regist_hash(&(mark[i][0]),i);
                }
                indx=0;
                reten=0;

                while(next_char())
                {
                        read_flag[indx]=-1;
                        printf("%d",indx,&mark[indx][0]);
#ifdef DEBUG
                        printf(":%s",&mark[indx][0]);
#endif
                        printf("\n",indx,&mark[indx][0]);
                        if(!calc_next())
                                break;
                }
        }

return(0);
}