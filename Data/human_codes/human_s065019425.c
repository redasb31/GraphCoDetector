#include <stdio.h>
#include <string.h>
#define mysign(x) (((x)>0)?1:(-1))
#define myabs(x)  (((x)>0)?(x):(-(x)))
int n;
int net[11][11];


void search_pos(int me,int *y,int *x)
{
  int i,j;

  for(i=3;i<8;i++)
    for(j=3;j<8;j++)
      if(net[i][j]==me)
	{
	  *y=i;*x=j;
	  return;
	}
  *x=*y=-1;
}

int ck_rel_pos(int y,int x,int y_,int x_)
{
  int i,j,r;

  if(y+2==y_)
    for(i=-3;i<=3;i++)
      if(x_==x+i)
	    {
	      r=-1;
	      for(j=0;myabs(j)<=myabs(i);j+=mysign(i))
		  r &= (net[y+1][x+j]!=0);

	      if(r)
		return(r);
	    }
  if(x+2==x_)
    for(i=-3;i<=3;i++)
      if(y_==y+i)
	    {
	      r=-1;
	      for(j=0;myabs(j)<=myabs(i);j+=mysign(i))
		{
		  r &= (net[y+j][x+1]!=0);
		}
	      if(r)
		return(r);
	    }
  return(0);
}

int count_dice()
{
  int i,j,r=0;
  for(i=3;i<8;i++)
    for(j=3;j<8;j++)
      if(net[i][j])
	r++;
  return(r);
}


int solve()
{
  int i,r[7];
  int px[7],py[7];

  if(count_dice()!=6)
    return(0);

  for(i=1;i<=6;i++)
    {
      search_pos(i,&py[i],&px[i]);
      if(py[i]==-1)
	return(0);
    }
  for(i=1;i<=6;i++)
    r[i]=ck_rel_pos(py[i],px[i],py[7-i],px[7-i]);
  return((r[1]||r[6]) && (r[2]||r[5]) && (r[3]||r[4]));
}
main()
{
  int i,j,k,ret;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      memset(&net[0][0],0,11*11);
      
      for(j=0;j<5;j++)
	for(k=0;k<5;k++)
	  scanf("%d",&net[j+3][k+3]);

      ret=solve();
      printf("%s\n",ret?"true":"false");
    }
  
  return(0);
}