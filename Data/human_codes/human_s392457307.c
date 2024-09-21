/*
  AOJ 1217
  Title:Family Tree
  @kankichi573
*/
#include <stdio.h>
#include <string.h>
#define max(x,y) (((x)>(y))?(x):(y))
int n,m;
char person[1000][21];
int level_table[1000];
int level2space[1000];
int parent[1000];
int name2int(char name[])
{
  int i;

  for(i=0;i<n;i++)
    if(0==strcmp(name,&person[i][0]))
      return(i);
  return(-1);
}
int is_child(int n1,int n2)
{
  if(parent[n1]==n2)
    return(-1);
  else
    return(0);
}
int is_parent(int n1,int n2)
{
  return(is_child(n2,n1));
}
int is_descendant(int n1,int n2)
{
  int i,step;
  step=level_table[n1];
  for(i=0;i<step;i++)
    {
      if(parent[n1]==n2)
	return(-1);
      n1=parent[n1];
    }
  return(0);
}
int is_ancestor(int n1,int n2)
{
  return(is_descendant( n2, n1));
}
int is_sibring(int n1,int n2)
{
  if(parent[n1]==parent[n2])
    return(-1);
  else
    return(0);
}
int hanbetu(char person1[],char person2[],char relation[])
{
  int n1,n2;
  n1=name2int(person1);
  n2=name2int(person2);
  if(0==strcmp(relation,"child"))
     return(is_child(n1,n2));
  if(0==strcmp(relation,"parent"))
     return(is_parent(n1,n2));
  if(0==strcmp(relation,"ancestor"))
     return(is_ancestor(n1,n2));
  if(0==strcmp(relation,"sibling"))
     return(is_sibring(n1,n2));
  if(0==strcmp(relation,"descendant"))
     return(is_descendant(n1,n2));
}
void bunkai(char buf[],char person1[],char person2[],char relation[])
{
  char *p;
  p=strtok(buf," ");
  strcpy(person1,p);
  p=strtok(NULL," ");  // is
  p=strtok(NULL," ");  // kansi
  p=strtok(NULL," ");
  strcpy(relation,p);
  p=strtok(NULL," ");   // of
  p=strtok(NULL,".");
  strcpy(person2,p);
}
int count_space(char * ptr)
{
  int ret=0;
  while(*ptr==' ')
    {
      ptr++;
      ret++;
    }
  return(ret);
}
int maxlevel;
void dump()
{
  int i;
  for(i=0;i<n;i++)
    printf("%d)[%d]:%s[%d]\n",i,level_table[i],&person[i][0],parent[i]);
  for(i=0;i<maxlevel;i++)
    printf("[lv=%d]sp=%d\n",i,level2space[i]);
}
main()
{
  int i,j,first,level,spaces,oldspaces,oldlevel,mylevel,ret;
  char buf[70],person1[12],person2[12],relation[11];
  first=1;
  while(scanf("%d %d ",&n,&m) && (n||m))
    {
      spaces=level=oldspaces=maxlevel=0;
      parent[0]=-1;
      for(i=0;i<n;i++)
	{
	  fgets(buf,70,stdin);
	  buf[strlen(buf)-1]='\0';
	  spaces=count_space(buf);
	  if(spaces>oldspaces)
	    {
	      level++;
	      maxlevel=max(maxlevel,level);
	    }
	  else if(spaces<oldspaces)
	    for(j=0;j<maxlevel;j++)
	      if(level2space[j]<spaces && spaces <=level2space[j+1])
		{
		level=j+1;
		//printf("lvup=%d\n",level);
		}
	  level2space[level]=spaces;	
	  level_table[i]=level;
	  strcpy(&person[i][0],&buf[spaces]);
	  mylevel=level_table[i];
	  if(i>0 || mylevel==0)
	    {
	      for(j=i-1;j>=0;j--)
		if(level_table[j]==mylevel-1)
		  {
		    parent[i]=j;
		    break;
		  }
	    }
	  oldspaces=spaces;
	}
#ifdef DEBUG      
      dump();
#else
    
      for(i=0;i<m;i++)
	{
	  fgets(buf,70,stdin);
	  bunkai(buf,person1,person2,relation);
	  ret=hanbetu(person1,person2,relation);
	  printf("%s\n",(ret?"True":"False"));
	}
      printf("\n");
#endif
    }
  return(0);
}