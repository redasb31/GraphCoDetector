/*
  AOJ 2619
  Title:Thread tree
  @kankichi573
*/
#include <stdio.h>
#include <string.h>
int N;
struct node_st 
{
  char message[51];
  int  link_ch;         
  int  link_br;
} node[1001];

void write_thread(int node_no,int depth)
{
  int i;
  for(i=0;i<depth;i++)
    printf(".");
  printf("%s\n",node[node_no].message);
  if(node[node_no].link_ch>0)
    write_thread(node[node_no].link_ch,depth+1);
  if(node[node_no].link_br>0)
    write_thread(node[node_no].link_br,depth);
}

void set_link(int x,int y)
{
  if(node[x].link_ch==0)
    {
      node[x].link_ch=y;
    }
  else
    {
      x=node[x].link_ch;
      while(node[x].link_br>0)
	{
	  x = node[x].link_br;
	}
      node[x].link_br=y;
    }
}

main()
{
  int i,re;
  
  scanf("%d",&N);
  for(i=1;i<=N;i++)
    {
      scanf("%d",&re);
      if(i>0)
	set_link(re,i);
      scanf("%s",&(node[i].message[0]));
    }
  write_thread(1,0);
  
  return(0);
}