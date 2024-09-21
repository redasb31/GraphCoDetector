#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
   
struct edge_t
{
  int from;
  int to;
  int cost;
};
 
typedef struct edge_t Edge;
   
int main(void)
{
  int num, i, k, from, to, cost, update;
  int nedge = 0;
  int dis[10000];
  Edge *edges, *p;
   
  edges = malloc(sizeof(Edge) * 500000);
   
  scanf("%d", &num);
   
  for (i = 0; i < num; i++)
    {
      scanf("%d %d", &from, &k);
   
      while(k--)
	{
	  scanf("%d %d", &to, &cost);
   
	  p = &edges[nedge++];
	  p -> from = from;
	  p -> to = to;
	  p -> cost = cost;
        }
      dis[i] = INT_MAX;
    }
  dis[0] = 0;
   
  update = 1;
  while(update)
    {
      update = 0;
      for(i = 0; i < nedge; i++)
	{
	  from = edges[i].from;
	  to = edges[i].to;
	  cost = edges[i].cost;
	    
	  if(dis[from] < INT_MAX && dis[to] > cost + dis[from])
	    {
	      dis[to] = cost + dis[from];
	      update = 1;
            }
        }
    }
  for(i = 0; i < num; i++)
    {
      printf("%d %d\n", i, dis[i]);
    }
  return 0;
}