/*
  AOJ 1603
  Title:500 yen saver
  @kankichi573
*/
#include <stdio.h>
#include <string.h>
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))

struct k_inf_st
{
  int change;
  int c500;
  int amount;
} inf[1000],work[1000];
int cnt;
int n ,p[100];

int compare_st(const void *a, const void *b)
{
  int a1,b1;
  a1 = ((struct k_inf_st *)a)->change;
  b1 = ((struct k_inf_st *)b)->change;

  if(a1  >  b1)
    return(1);
  if(a1 <   b1)
    return(-1);

  a1 = ((struct k_inf_st *)a)->c500;
  b1 = ((struct k_inf_st *)b)->c500;

  if(a1  >  b1)
    return(-1);
  if(a1 <   b1)
    return(1);


  a1 = ((struct k_inf_st *)a)->amount;
  b1 = ((struct k_inf_st *)b)->amount;


  if(a1  >  b1)
    return(1);
  if(a1 <   b1)
    return(-1);
  if(a1 ==  b1)
    return(0);
}

void dump(int n)
{
  int i;
  for(i=0;i<n;i++)
    printf("%d [%d][%d]|\n",inf[i].c500,inf[i].change,inf[i].amount);
  printf("--[cnt=%d]--\n",cnt);
}

void shrink()
{
  int i,j,ch,c5,amt;

  for(i=0,j=0,ch=-1;i<cnt;i++)
    if(inf[i].change != ch)
      {
	memcpy(&work[j],&inf[i],sizeof(struct k_inf_st));
	ch = inf[i].change;
	j++;
      }
  cnt=j;
  memcpy(inf,work,sizeof(struct k_inf_st)*cnt);

  for(i=0,j=0,c5=-1;i<cnt;i++)
    if(inf[i].c500 > c5)
      {
	memcpy(&work[j],&inf[i],sizeof(struct k_inf_st));
	c5  = inf[i].c500;
	amt = inf[i].amount;
	j++;
      }
    else if(inf[i].c500 == c5 && inf[i].amount < amt) 
      {
	memcpy(&work[j],&inf[i],sizeof(struct k_inf_st));
	ch  = inf[i].change;
	amt = inf[i].amount;
	j++;
      }

  cnt=j;
  memcpy(inf,work,sizeof(struct k_inf_st)*cnt);
  
 }

void calc(int n)
{
  int ch,i,cnt_old,ch2,c2,pr,pr2;
  
  pr=p[n];
  //printf("no=%d pr=%d\n",n,pr);

  if(pr % 1000 == 0)
    {
      memcpy(&inf[cnt],&inf[0],sizeof(struct k_inf_st)*cnt);
      //dump(cnt*2);
      cnt_old=cnt;
      cnt *= 2;
      for(i=cnt_old;i<cnt_old*2;i++)
	  {
	    inf[i].change = inf[i].change + 500;
	    inf[i].c500 ++;
	    inf[i].amount += pr;
	  }
    }
  else if(pr % 1000 <= 500)
    {
      ch = 500 - (pr % 1000);
      for(i=0;i<=cnt;i++)
	{
	  inf[i].change = max(0,inf[i].change - ch);
	  inf[i].c500 ++;
	  inf[i].amount += pr;
	}
    }
  else
    {
      ch = (pr % 1000) - 500;
      memcpy(&inf[cnt],&inf[0],sizeof(struct k_inf_st)*cnt);
      //dump(cnt*2);
      cnt_old=cnt;
      cnt *= 2;
      for(i=cnt_old;i<cnt_old*2;i++)
	{
	  inf[i].change += ch;
	  ch2 = inf[i].change;

	  c2  = inf[i].c500;
	  inf[i].c500++;

	  inf[i].amount += pr;
	  pr2 = inf[i].amount;

	  //printf("** [%d] [%d]\n",ch,c2);
	  if(ch2 >= 500 && c2 > 0)
	    {
	      memcpy(&inf[cnt],&inf[1],sizeof(struct k_inf_st));
	      inf[cnt].change = ch2 - 500;
	      inf[cnt].c500   = c2;
	      inf[cnt].amount = pr2;
	      cnt ++;
	    }
	  else if(ch2 < 500 && c2 > 0)
	    {
	      memcpy(&inf[cnt],&inf[1],sizeof(struct k_inf_st));
	      inf[cnt].change = 0;
	      inf[cnt].c500   = c2;
	      inf[cnt].amount = pr2;
	      cnt ++;
	    }
	}
      //dump(cnt);
    }
  qsort(inf,cnt,sizeof(struct k_inf_st),compare_st);
  shrink();
  //dump(cnt);
}


main()
{
  int i,ret,ret2;
  

  while(scanf("%d",&n) && n)
    {
      memset(inf,0,sizeof(inf));
      for(i=0;i<n;i++)
	scanf("%d",&p[i]);

      cnt=1;
      
      for(i=n-1;i>=0;i--)
	calc(i);

      printf("%d %d\n",inf[0].c500,inf[0].amount);
    }
  return(0);
}