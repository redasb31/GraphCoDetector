/*
  AOJ 2519
  Title:Eglish
  @kankichi573
*/
#include <stdio.h>
#include <string.h>
#define max(x,y) (((x)>(y))?(x):(y))
#define myabs(x) (((x)>0)?(x):(-(x)))
int N,T;
char word[100][9];
char length[100];
int score[100];
int  hist[100];
char line[4][4];
char alpha_pos[26][16][2];
char count[26];
int dp[10001];
int dp2[10001];

int search_word2(char word[],int y,int x,int len,short flag)
{
  int i,x1,y1,ret;
  char c;

  //printf("[%s] %d %d [%d]\n",word,y,x,len);

  if(flag & (1<<(4*y+x)))
    return(0);
  if(len==0)
    return(1);
  flag |= 1<<(4*y+x);

  c=word[0]-'A';
  for(i=ret=0;i<count[c];i++)
    {
      y1=alpha_pos[c][i][0];
      x1=alpha_pos[c][i][1];
      if(myabs(x1-x)<2 && myabs(y1-y)<2 && !(x==x1 && y==y1))
	ret+=search_word2(word+1,y1,x1,len-1,flag);
    }
  return(ret);
}

int search_word(char word[],int len)
{
  int i,x,y,ret;
  short flag=0;
  char c;

  c=word[0]-'A';
  for(i=ret=0;i<count[c];i++)
    {
      y=alpha_pos[c][i][0];
      x=alpha_pos[c][i][1];
      //printf("[%s][%d] %d %d",word,i,y,x);
      ret+=search_word2(word+1,y,x,len-1,flag);
    }
  return(ret);
}


void search_word_all()
{
  int i,len;
  char *p;
  

  for(i=0;i<N;i++)
    {
      p=&word[i][0];
      len=strlen(p);
      hist[i]=search_word(p,len);
    }
}

dump()
{
  int i,j;
  for(i=0;i<26;i++)
    if(count[i])
    {
      printf("%c|",i+'A');
      for(j=0;j<count[i];j++)
	printf("%d %d|",alpha_pos[i][j][0],alpha_pos[i][j][1]);
      printf("\n");
    }
}
dump2()
{
  int i;

  for(i=0;i<N;i++)
    printf("%d) %s [%d] %d\n",i,&word[i][0],length[i],hist[i]);
}
solve()
{
  int i,j,k,pos,ret;
  
  for(i=0;i<N;i++)
    {
      memcpy(dp2,dp,sizeof(int)*(1+T));
      for(j=0;j<=T;j++)
	if(j==0||dp2[j])
	  for(k=1;k<=hist[i];k++)
	    {
	      pos=j+k*length[i];
	      if(pos>T)
		break;
	      dp[pos] = max(dp[pos],dp2[j]+k*score[i]);
	    }
    }
  for(i=T,ret=0;i>=1;i--)
    ret=max(ret,dp[i]);
  return(ret);
}
main()
{
  int i,j,ret;
  char c;

  scanf("%d",&N);

  for(i=0;i<N;i++)
    {
      scanf("%s %d",&word[i][0],&score[i]);
      length[i]=strlen(&word[i][0]);
    }
  for(i=0;i<4;i++)
    {
      scanf("%s",&line[i][0]);
      for(j=0;j<4;j++)
	{
	  c=line[i][j]-'A';
	  alpha_pos[c][count[c]][0]=i;
	  alpha_pos[c][count[c]][1]=j;
	  count[c]++;
	}
    }
  //dump();
  //printf("%d\n",search_word("abcd",4));
  scanf("%d",&T);
  search_word_all();
  //dump2();
  ret=solve();
  printf("%d\n",ret);
  return(0);
}