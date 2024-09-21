/*
AizuOnline A2335
10-Year-Old Dynamic Programming
*/
#include <stdio.h>
#define MAXHASH 1600000
int W,H,K;

struct {
  short x;
  short y;
  long long ways;} hash[MAXHASH];
int hashcnt;
struct {
  short x;
  short y;
  short z;
  long long ways;} hash2[MAXHASH];
int hash2cnt;

int init_hash()
{
  int i;
  for(i=0;i<MAXHASH;i++)
    {
      hash[i].x = 0;
      hash[i].y = 0;
      hash[i].ways = -1LL;
    }
  hashcnt=0;
}

int hashfunc (int x,int y)
{
  return((x*31371 + y*2689) % MAXHASH);
}

int regist_hash(int x,int y,long long ways)
{
  int ptr,ptr1;

  if(hashcnt >= MAXHASH/2)
    return(-1);

  ptr = hashfunc(x,y);
  ptr1 = ptr;
  // printf("REGS0 %d %d:%lld (%d)\n",x,y,ways,ptr);
  for(;ptr<MAXHASH;ptr++)
    {
      if(hash[ptr].x == x && hash[ptr].y == y)
	return(-2);
      if(hash[ptr].ways == -1LL)
	goto REG;
    }
  for(ptr=0;ptr<ptr1;ptr++)
    {
      if(hash[ptr].x == x && hash[ptr].y == y)
	return(-2);
      if(hash[ptr].ways == -1LL)
	goto REG;
    }
 REG:
  // printf("REGS1 %d %d:%lld (%d)\n",x,y,ways,ptr);
  hash[ptr].x = x;
  hash[ptr].y = y;
  hash[ptr].ways = ways;
  hashcnt++;
  return(ptr);
}

long long find_hash(int x,int y)
{
  int ptr;

  ptr = hashfunc(x,y);
 
  while(1)
    {
      if(hash[ptr].x == x && hash[ptr].y == y)
	{
	  // printf("FIND %d %d:%lld\n",x,y,hash[ptr].ways);
	  return(hash[ptr].ways);      
	}
      if(hash[ptr].ways == -1)
	return(-1LL);
      ptr++;
      if(ptr >= MAXHASH)
	ptr=0;
    }
}
/**HASH 2**/

int init_hash2()
{
  int i;
  for(i=0;i<MAXHASH;i++)
    {
      hash2[i].x = 0;
      hash2[i].y = 0;
      hash2[i].z = 0;
      hash2[i].ways = -1LL;
    }
  hashcnt=0;
}

int hashfunc2 (int x,int y,int z)
{
  return((x*31371 + y*2689 + z*16711) % MAXHASH);
}

int regist_hash2(int x,int y,int z,long long ways)
{
  int ptr,ptr1;

  if(hash2cnt >= MAXHASH/2)
    return(-1);

  ptr = hashfunc2(x,y,z);
  ptr1 = ptr;
  // printf("REGS0 %d %d:%lld (%d)\n",x,y,ways,ptr);
  for(;ptr<MAXHASH;ptr++)
    {
      if(hash2[ptr].x == x && hash2[ptr].y == y && hash2[ptr].z == z)
	return(-2);
      if(hash2[ptr].ways == -1LL)
	goto REG;
    }
  for(ptr=0;ptr<ptr1;ptr++)
    {
      if(hash2[ptr].x == x && hash2[ptr].y == y && hash2[ptr].z == z)
	return(-2);
      if(hash2[ptr].ways == -1LL)
	goto REG;
    }
 REG:
  // printf("REGS1 %d %d:%lld (%d)\n",x,y,ways,ptr);
  hash2[ptr].x = x;
  hash2[ptr].y = y;
  hash2[ptr].z = z;
  hash2[ptr].ways = ways;
  hash2cnt++;
  return(ptr);
}

long long find_hash2(int x,int y,int z)
{
  int ptr;

  ptr = hashfunc2(x,y,z);
 
  while(1)
    {
      if(hash2[ptr].x == x && hash2[ptr].y == y && hash2[ptr].z == z)
	{
	  // printf("FIND %d %d:%lld\n",x,y,hash[ptr].ways);
	  return(hash2[ptr].ways);      
	}
      if(hash2[ptr].ways == -1)
	return(-1LL);
      ptr++;
      if(ptr >= MAXHASH)
	ptr=0;
    }
}

long long combi(int n,int r)
{
  long long ret;
  if((ret=find_hash(n,r)) > 0)
    return(ret);
  if(r==0 || r==n)
    return(1);
  ret=(combi(n-1,r)+combi(n-1,r-1)) % 1000000007;
  regist_hash(n,r,ret);
  return(ret);
}

int f(int nu,int nd,int x)
{
  int ret;
  //printf("%d %d %d\n", nu, nd, x);
  if((ret=find_hash2(nu,nd,x)) > 0)
    return(ret);

  if (x < 0) 
    return(0);
  if (0 == nu)
    if(x >= nd)
      return(1);
    else
      return(0);
  else if (1 == nd)
    if(0 == x)
      return(nu);
    else
      return(1 + nu);
  else
    {
      ret = (f(nu-1, nd ,x+1) + f(nu,nd-1,x-1)) % 1000000007;
      regist_hash2(nu,nd,x,ret);
      return(ret);
    }
}

int f1(int N,int K1 )
{
  if ( K1 == 0)
    return(1);
  else
    return( f( N- K1, K1, 0));
}


long long f2335 (int W,int H, int K)
{ long long sum,product;
  int x;

  sum = 0LL;
  for(x=0;x<=K;x++)
    {
    product = (combi(W+H+2*K,W+x*2)*f1(W+2*x,x)) % 1000000007LL;
    sum += (product*f1(H+(K-x)*2,K-x)) % 1000000007LL;
    sum %= 1000000007LL;
    // printf("%lld\n",sum);
    }
  return(sum);
		}

main()
{
  init_hash();
  init_hash2();
  scanf("%d %d %d",&W,&H,&K);
  printf("%lld\n",f2335(W,H,K));
  printf("%d %d\n",hashcnt,hash2cnt);

return(0);
}