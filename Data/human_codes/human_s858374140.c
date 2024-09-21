/*
AizuOnline A2403
Title
*/
#include <stdio.h>
#include <string.h>
#define MAXCOUNTRY 40
#define NAMELENGTH 16
#define max(x,y) (((x)>(y))?(x):(y))
//Global data section
int n;
char name_table[MAXCOUNTRY][NAMELENGTH+1];
int  strength[MAXCOUNTRY];
char  neighbor[MAXCOUNTRY][MAXCOUNTRY];
char  readbuffer[MAXCOUNTRY][1000];
char  doumei[MAXCOUNTRY];
int total_strength;
int select_count;
//
void clear_neighbor()
{
        int i,j;
        for(i=0;i<MAXCOUNTRY;i++)
                for(j=0;j<MAXCOUNTRY;j++)
                        neighbor[i][j]=0;
        for(i=0;i<MAXCOUNTRY;i++)
                doumei[i]=0;
}
int get_county_num(char * name)
{
        int i;
        for(i=0;i<MAXCOUNTRY;i++)
                if(0==strcmp(name,name_table[i]))
                        return(i);
        return(-1);
}
void regist_country_name_and_strength()
{
        int i;

        for(i=0;i<n;i++)
        {
                sscanf(&readbuffer[i][0],"%s %d",&name_table[i][0],
                       &strength[i]);
        }
}
void regist_neighbor()
{
        int i,j,m,neib;
        char *p;

        for(i=0;i<n;i++)
        {
                p=strtok(&readbuffer[i][0]," ");  //skip country name
                p=strtok(NULL," ");               //skip strength
                p=strtok(NULL," "); //get number of neighbor countries
                m=atoi(p);
                for(j=0;j<m;j++)
                {
                        p=strtok(NULL," \r\n");
                        neib=get_county_num(p);
                        neighbor[i][neib]=neighbor[neib][i]=-1;
                }
        }
}
void dump()
{
        int i,j;
        for(i=0;i<n;i++)
        {
                printf("%2d|",i);
                for(j=0;j<n;j++)
                        printf("%c",neighbor[i][j]?'+':'-');
                printf("|(%s:%d)\n",&name_table[i][0],strength[i]);
        }
}
int is_doumei_neighbor(int country_num)
{
        int i;

        for(i=0;i<n;i++)
                if(neighbor[i][country_num] && doumei[i])
                        return(-1);
        return(0);
}
int  max_sum_strength2(int start,int total)
{
        int ret1,ret2,c;
#ifdef DEBUG
        printf("st,t=%d %d\n",start,total);
#endif
        if(start >= n)
                return(total);
        c=start;
        while(is_doumei_neighbor(c))
                c++;
        if(c >= n)
                return(total);
        ret1=max_sum_strength2(c+1,total);
        doumei[c]=-1;
        ret2=max_sum_strength2(c+1,total+strength[c]);
        return(max(ret1,ret2));
}
int  max_sum_strength()
{
        doumei[0]=-1;
        total_strength=strength[0];
        select_count=1;
        return(max_sum_strength2(1,total_strength));
}
int main()
{
        int i,ret;

        while(EOF!=scanf("%d ",&n) && n)
        {
                clear_neighbor();
                for(i=0;i<n;i++)  
                        fgets(&readbuffer[i][0],1000,stdin);
      
                regist_country_name_and_strength();
                regist_neighbor();
#ifdef DEBUG
                dump();
#endif

                ret=max_sum_strength();
                printf("%d\n",ret);

        }

return(0);
}