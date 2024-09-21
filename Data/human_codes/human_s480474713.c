/*
AizuOnline A2336
spring tiles
*/
#include <stdio.h>
#include <float.h>
#define GETA 0
#define OFF 9999
int W,H;
char tiles[500][501];
int dist_goal[500][501];
int dist_spring[500][501];


print()
{
  int i,j,c;
  for(i=0;i<H;i++)
    printf("%s\n",&(tiles[i][0]));
  printf("\n"); 
  for(i=0;i<H;i++)
    {
      for(j=0;j<W;j++)
	{
	  c=dist_goal[i][j];
	  if(c >0 && c<10)
	    printf("%d",c);
	  else
	    printf(".");
	}
      printf("\n");
    }
  printf("\n"); 
  for(i=0;i<H;i++)
    {
      for(j=0;j<W;j++)
	{
	  c=dist_spring[i][j];
	  if(c >0 && c<10)
	    printf("%d",c);
	  else
	    printf(".");
	}
      printf("\n");
    }
}

init()
{
  int i,j;

  scanf("%d %d",&W,&H);
  for(i=0;i<H;i++)
    scanf("%s",&(tiles[i][0]));
  for(i=0;i<H;i++)
    for(j=0;j<W;j++)
      {
	dist_goal[i][j]=OFF;
	dist_spring[i][j]=OFF;
      }
}
void find_dist_1(int y,int x)
{ 
  extern void find_dist_1a(int,int,int);
  find_dist_1a(y,x,0);
}
void find_dist_1a(int y,int x,int d)
{ 
  //printf("finddist %d %d %d %c\n",y,x,d,tiles[y][x]);

  if(tiles[y][x]=='.' ||tiles[y][x]=='s'||tiles[y][x]=='g')
    if(dist_goal[y][x]==OFF || dist_goal[y][x] > GETA+d)
      {
	dist_goal[y][x]=GETA+d;
    
      if(y>0)
	find_dist_1a(y-1,x,d+1);
      if(y<H-1)
	find_dist_1a(y+1,x,d+1);
      if(x>0)
	find_dist_1a(y,x-1,d+1);
      if(x<W-1)
	find_dist_1a(y,x+1,d+1);
    }
}
void find_goal(int * y,int * x)
{
  int i,j;

  for(i=0;i<H;i++)
    for(j=0;j<W;j++)
      if(tiles[i][j]=='g')
	{*y = i;*x =j;
	  return;
	}
}
void calc_dist_goal()
{
  int gx,gy;  
  find_goal(&gy,&gx);
  //printf("find %d %d\n",gy,gx);
  find_dist_1(gy,gx);
}
int find_spring(int * y,int * x)
{
  int i,j,js;

  js = *x+1;
  if(js >= W){*y++;js=0;}
  for(i=*y;i<H;i++)
    {
      if(i>*y)
	js=0;
      for(j=js;j<W;j++)
	if(tiles[i][j]=='*')
	  {
	    *y = i;*x =j;
	    return(1);
	}
    }
  return(0);
}

void calc_dist_spring_1(int y,int x)
{ 
  extern void find_dist_spring_1a(int,int,int);
  find_dist_spring_1a(y,x,0);
}
void find_dist_spring_1a(int y,int x,int d)
{ 
  //printf("finddist %d %d %d %c ",y,x,d,tiles[y][x]);
  //printf("finddist %d \n",dist_spring[y][x]);

  if(tiles[y][x]=='.' ||tiles[y][x]=='s'||tiles[y][x]=='g'||tiles[y][x]=='*')
    if(dist_spring[y][x]==OFF || dist_spring[y][x] > GETA+d)
      {
	dist_spring[y][x]=GETA+d;
    
      if(y>0)
	find_dist_spring_1a(y-1,x,d+1);
      if(y<H-1)
	find_dist_spring_1a(y+1,x,d+1);
      if(x>0)
	find_dist_spring_1a(y,x-1,d+1);
      if(x<W-1)
	find_dist_spring_1a(y,x+1,d+1);
    }
}


void calc_dist_spring()
{
  int y=0,x=0;

  while(find_spring(&y,&x))
    {
      // printf("SP %d %d\n",y,x);
      calc_dist_spring_1(y,x);
   }
}
double calc_kitaichi()
{
  int i,j,k;
  int tobisaki,bunsi,spring_tikai;
  double result;
  int a,b;

  tobisaki=0;
  for(i=0;i<H;i++)
    for(j=0;j<W;j++)
      if(tiles[i][j]=='.'||tiles[i][j]=='s')
	tobisaki++;
  for(k=0;k<1000;k++)
    {
      bunsi = 0;
      spring_tikai=0;
      for(i=0;i<H;i++)
	for(j=0;j<W;j++)
	  {
	    a = dist_spring[i][j] ;
	    b = dist_goal[i][j]   ;
	    // printf("%d %d %d %d %d\n",a,b,k,bunsi,spring_tikai);
	    if(a == OFF)
	      {
		if(b == OFF)
		;
		else
		  {
		    bunsi +=(b - GETA );
		  }
	      }
	    else
	      if(b == OFF)
	      {
		bunsi +=(a - GETA);
		if(a != GETA)
		  spring_tikai++;
		
	      }
	      else
		{
		  //printf("%c %c %d %d\n",a,b,k,a+k<b);
		  spring_tikai += (a+k < b)?1:0;
		  if(a+k < b)
		    {
		      bunsi +=(a - GETA);
		    }
		  else
		    {
		      //printf("*");
		      //spring_tikai++;
		      bunsi +=(b - GETA);		      
		    }
		}
	  }
      //printf("::%d:%d:%d\n",bunsi,tobisaki,spring_tikai);
      result = ((float)bunsi)/(tobisaki-spring_tikai);
      if(result >= (float)k && result < (float)(k+1))
      	break;
    }
  return(result);
}
void search_start(int * y,int * x)
{
  int i,j;

  for(i=0;i<H;i++)
    for(j=0;j<W;j++)
      if(tiles[i][j]=='s')
	{*y = i;*x =j;
	  return;
	}
}
#define min(x,y) ((x)>(y))?(y):(x)

main()
{
  int x,y;
  double ret;

  init();
  //print();
  calc_dist_goal();
  calc_dist_spring();
  //print();
  ret=calc_kitaichi();
  search_start(&y,&x);
  printf("%.10lf\n",min(dist_spring[y][x],dist_goal[y][x])+ret);
  //printf("%d %d %d %d\n",y,x,dist_spring[y][x],dist_goal[y][x]);
  //print();
return(0);
}