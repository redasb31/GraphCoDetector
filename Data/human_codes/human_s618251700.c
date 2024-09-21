/*
AizuOnline A1145
Title The Genome Database of All Space Life
 
*/
#include <stdio.h>
#include <string.h>
 
//Global data section
char s[101];
int  idx;
int node_ptr;
struct NODE
{
  int car;
  int cdr;
  char * genum;
  int glen;       // mojiretu no nagasa
  int blen;       // tenkai go no nagasa never .GE. 1000000
  int coef;       // keisuu < 5keta
} Gnode[100];
 
//
int is_under_5digits(char * g)
{
  int i;
 
  for(i=0;i<5;i++)
    if(!isdigit(g[i]))
      return(i);
  
  return(5);
}
int get_close_paren(char * g)
{
  char *p;
  int depth;
#ifdef DEBUG2
  printf("gcp=%s\n",g);
#endif
  depth=0;
  for(p=g;*p;p++)
    {
      if(*p=='(')
    depth++;
      if(*p==')')
    depth--;
      if(depth==0)
    {
#ifdef DEBUG2
  printf("gcpA=%d\n",p-g);
#endif
    return(p-g);
    }
    }
  return(-1);
}
int get_1st(char * g,int l)
{
        int ret;
        int i;
   
        if(isupper(g[0]))
        {
                for(i=0;i<l;i++)
                        if(!isupper(g[i+1]))
                                return(i+1);
                 
                return(l);
        }
        if(ret=is_under_5digits(g))
        {
#if DEBUG2
                printf("NL=%d\n",ret);
#endif
                if(isalpha(g[ret]))
                        return(ret+1);
                if(g[ret]=='(')
                        return(ret+1+get_close_paren(g+ret));
        }
}
int is_single(char * g,int l)
{
        if(l==1)
                return(isupper(g[0]));
        else
                return(isupper(g[0]) && is_single(g+1,l-1));
}
int all_upper(char * g,int len)
{
  int i;
 
  for(i=0;i<len;i++)
          if(!isupper(g[i]))
                  return(0);
   
  return(-1);
}
int get_times(char * g,char len)
{
        int i,c;
  //printf("T:%s %d\n",g,len);
        c=0;
        for(i=0;i<len;i++)
        {
                c*=10;
                c+=(g[i]-'0');
        }
        return(c);
}
 
 
int get_len_recursive(int ndp)
{
        int ret,ret1,ret2;
         
        if(Gnode[ndp].cdr == -1)
        {
                if(Gnode[ndp].car == -1)
                {
                        if(Gnode[ndp].coef != 1)
                                ret=Gnode[ndp].coef;
                        else
                                ret=Gnode[ndp].glen;
                        //printf("Le:%d\n",ret);
                        Gnode[ndp].blen=ret;
                        return(ret);
                }
                else
                {
                        ret=get_len_recursive(Gnode[ndp].car);
                        if(ret!=-1)
                        {
                                ret*=Gnode[ndp].coef;
                                if(ret>1000000)
                                        ret= -1;
                        }
                        Gnode[ndp].blen=ret;
                        return(ret);
                }
        }
        else
        {
                ret1=get_len_recursive(Gnode[ndp].car);
                ret2=get_len_recursive(Gnode[ndp].cdr);
                if(ret1==-1 || ret2==-1)
                        ret=-1;
                else
                {
                        ret=ret1+ret2;
                        if(ret>1000000)
                                ret= -1;
                }
                Gnode[ndp].blen=ret;
                return(ret);
        }
}
 
void print_all_node()
{
        int i;
 
        printf("SEQ:COEF:LEN:CAR:CDR:STRING\n");
        for(i=0;i<=node_ptr;i++)
        {      
                print_1_node(i);
                printf("\n");
        }
}
print_1_node(int i)
{
        int j;
 
          printf("%d:",i);
          printf("[%d]",Gnode[i].coef);
          printf("(%d)",Gnode[i].blen);
          if(Gnode[i].car>0)
                  printf("%d:",Gnode[i].car);
          else
                  printf("*:");
          if(Gnode[i].cdr>0)
                  printf("%d:",Gnode[i].cdr);
          else
                  printf("*:");
           
          for(j=0;j<Gnode[i].glen;j++)
          {
                  printf("%c",Gnode[i].genum[j]);
          }
}
 
 
void set_node(int n,char * g,int len)
{
  int ret;
  //printf("G:%d %s %d\n",n,g,len);
  Gnode[n].car = -1;
  Gnode[n].cdr = -1;
 
  Gnode[n].genum = g;
  Gnode[n].glen = len;
}
 
int get_new_node()
{
  node_ptr++;
  Gnode[node_ptr].car=-1;
  Gnode[node_ptr].cdr=-1;
  Gnode[node_ptr].genum=NULL;
  Gnode[node_ptr].glen=0;
  Gnode[node_ptr].blen=0;
  Gnode[node_ptr].coef=1;
  return(node_ptr);
}
int init_node()
{
  int i;
 
  for(i=0;i<100;i++)
    {
      Gnode[i].car=-1;
      Gnode[i].cdr=-1;
      Gnode[i].genum=NULL;
      Gnode[i].glen=0;
      Gnode[i].blen=0;
      Gnode[i].coef=1;
    }
}
 
void set_nodes_recursive(int ndp,char * g,int gl)
{
        int l1,carp,cdrp,ret;
     
  //printf("g %s gl %d\n",g,gl);
        set_node(ndp,g,gl);
   
        l1=get_1st(g,gl);
 
        if(l1 < gl)
        {
                carp=Gnode[ndp].car = get_new_node();
                cdrp=Gnode[ndp].cdr = get_new_node();
                set_nodes_recursive(carp,g,l1);
                 
                set_nodes_recursive(cdrp,&g[l1],gl-l1);
        }
        else if(ret=is_under_5digits(g))
        {
                Gnode[ndp].coef=get_times(g,ret);
                if(g[ret]=='(')
                {
                        carp=Gnode[ndp].car = get_new_node();
                        Gnode[ndp].cdr = -1;
                        //printf("tims %d\n",get_times(g,ret));
                        set_nodes_recursive(carp,g+ret+1,gl-ret-2);
                }
                else
                {
                        Gnode[ndp].car = -1;
                        Gnode[ndp].genum +=ret;
                        Gnode[ndp].glen  -=ret;
                }
        }
}
void set_all_node()
{
  set_nodes_recursive(0,s,strlen(s));
}
 
void get_len_all()
{
  get_len_recursive(0);
}
char get_bunsi(int ndp,int id)
{
        struct NODE *np;
        int car_len;

        np=&Gnode[ndp];
#ifdef DEBUG1 
        print_1_node(ndp);
        printf("\t:I=%d\n",id);
#endif
        if(np->car > 0)
                car_len=Gnode[np->car].blen;
        else
                car_len=0;
        
        if(np->blen==-1)
        {                
                if(np->cdr == -1)
                {
                        if(car_len != -1)
                                return(get_bunsi(np->car,id % car_len));
                        else
                                return(get_bunsi(np->car,id));
                }
                else
                {
                        if(car_len > id || car_len== -1)
                                return(get_bunsi(np->car,id));
                        else
                                return(get_bunsi(np->cdr,id-car_len));
                }       
        }
        else
        {
                if(np->blen <= id)
                        return('0');
                if(np->cdr == -1)
                {
                        if(np->car == -1)
                        {
                                if(np->coef > 1) // number*terminal
                                {
                                        return(np->genum[0]);
                                }
                                else             // terminal...
                                        return(np->genum[id]);
                        }
                        else
                                return(get_bunsi(np->car,id % car_len));
                }
                if(car_len > id)
                        return(get_bunsi(np->car,id));
                else
                        return(get_bunsi(np->cdr,id-car_len));
        }
}
main()
        {
  while(EOF!=scanf("%s %d",s,&idx) && !(s[0]=='0' && s[1]=='\0' && idx==0))
    {
      init_node();
      node_ptr=0;
      set_all_node();
      get_len_all();
#ifdef DEBUG1
      print_all_node();
      printf("--trace inf------------\n");
#endif
      printf("%c\n",get_bunsi(0,idx));
    }
 
return(0);
}