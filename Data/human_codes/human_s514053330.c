#include<stdio.h>
#include<stdlib.h>

int check(char *str,int num)
{
  int i;
  if(str[num]=='c')return 0;

  else
  {
    for(i=num-1;i>=0;i--)
    {
      if(str[i]=='c')return (num-i);
    }
  }
  return -1;
}

int main()
{
  int h,w;
  int i,j;
  int **joi;
  char *cloud;
  scanf("%d %d",&h,&w);
  
  joi=(int **)malloc(sizeof(int *)*w);
  for(i=0;i<h;i++)joi[i]=(int *)malloc(sizeof(int)*h);
  cloud=(char *)malloc(sizeof(char)*(w+1));

  for(i=0;i<h;i++)
  {
    scanf("\n%s",cloud);

    for(j=0;j<w;j++)joi[i][j]=check(cloud,j);
  }

  for(i=0;i<h;i++)
  {
    for(j=0;j<w;j++)printf("%d ",joi[i][j]);
    //printf("\n");
  }

  for(i=0;i<h;i++)free(joi[i]);
  free(joi);free(cloud);
 
  return 0; 
}