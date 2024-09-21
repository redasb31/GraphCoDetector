/*
  AOJ 2135
  Title:Reverse a Road
  @kankichi573
*/
#include <stdio.h>
#include <string.h>

int N,S,T,M;
int from[10001],to[10001];
char road[1001][1001];
int distance[2][1001];   // distance from start,end

int dist_all;

void calc_distance(int start,int d,int dist[])
{
  int i;

  //printf("c_d__ %d %d\n",start,d);

  if(dist[start]==-1 || dist[start]>d)
    {
      dist[start]=d;
      if(start==T)
	dist_all=d;
    }
  else
    return;

  for(i=1;i<=1000;i++)
    if(road[start][i])
      calc_distance(i,d+1,dist);
}

void calc_distance_r(int start,int d,int dist[])
{
  int i;

  //printf("c_d_r %d %d\n",start,d);

  if(dist[start]==-1 || dist[start]>d)
    {
      dist[start]=d;
      //if(start==T)
      //dist_all=d;
    }
  else
    return;

  for(i=1;i<=1000;i++)
    if(road[i][start])
      calc_distance_r(i,d+1,dist);
}

solve()
{
  int i,shortcut,min_,min_r,min_road,d1,d2;
  
  for(i=1,min_=dist_all,min_r=0;i<=M;i++)
    {
      d1=distance[1][from[i]];
      d2=distance[0][to[i]];
      //printf("%d:%d %d [%d %d %d]\n",i,from[i],to[i],d1,d2,d1+d2+1);

      if(d1 + d2 +1  <dist_all && d1>=0 && d2>=0)
	{
	  shortcut=(d1+d2+1);
	  if(shortcut<min_)
	    {
	      //printf("*+\n");
	      min_=shortcut;
	      min_r=i;
	    }
	}
    }
  if(min_ < dist_all)
    printf("%d %d\n",min_, min_r);
  else
    printf("%d 0\n",dist_all);

}

main()
{
  int i,ret,a,b;
  

  while(scanf("%d",&N)  && (N))
    {
      memset(distance,-1,sizeof(distance));
      memset(road,0,sizeof(road));
      scanf("%d %d",&S,&T);
      scanf("%d",&M);
      for(i=1;i<=M;i++)
	{
	  scanf("%d %d",&a,&b);
	  from[i]=a;
	  to[i]=b;
	  road[a][b]=1;
	}
      calc_distance(S,0,&distance[0][0]);
      calc_distance_r(T,0,&distance[1][0]);
      //printf("dall=%d\n",dist_all);
      solve();
    }
  return(0);
}