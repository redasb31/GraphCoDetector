/*
A0410.c Akabeko 20
2019/11/08 rte
 */
#include <stdio.h>
#include <string.h>

#define max(x,y) (((x)>(y))?(x):(y))

int m,n,n2,q[41],p[20];
int  from[8000];
char to[8000];
int cntr; //割り切れる順列の数
int primes[]={2,3,5,7,11,13,17,19,23,29,31,37};
char gt_[20][12]; //２０個（まで）の引数をゲーデル表記に変換

int gcd(int a, int b)
{       int c;
        while (b > 0) {
                c = a % b;
                a = b;
                b = c;
        }
        return a;
}
void dump(int mask,int m2)
{ int i,j;

  for(i=0,j=1;i<n;i++,j<<=1)
    {
      if(j & mask)
	printf("%d,",p[i]);
    }
  printf(":%d\n",p[m2]);
}
int check(int x)
{
  int i,f,t,mask;
  
  for(i=0;i<cntr;i++)
    {
      mask=from[i];
      t   =to[i];
      //dump(mask,t);
      if((x & mask)==mask && (x & (1<<t))==0)
	{
	  return(0);
	}
    }
  return(1);
}


int solve()
{
  int i,ret;
  for(i=1,ret=0;i<(1<<n);i++)
  {
      
    if(check(i))
      ret++;
  }
  return(ret);

}
void dump_fact(char gt[])
{
  int i;
  for(i=0;i<12;i++)
    if(gt[i]>0)
      printf("%d[%d]:",primes[i],gt[i]);
    printf("\n------\n");
}
void factorize(int num,char gt[])
{
  int i;

  memset(gt,0,12);
  while(num>1)
    {
      for(i=0;i<12;i++)
	if((num % primes[i])==0)
	{
	    gt[i]++;
	    num /= primes[i];
	}
    }
  //dump_fact(gt);
}

int lcm(char outgt[],char gt[],char gt2[])
{
  int i;
  //dump_fact(gt);
  //dump_fact(gt2);
  for(i=0;i<13;i++)
    {
      outgt[i]=max(gt[i],gt2[i]);
      //if(outgt[i]>0)
	//printf("%d[%d]%d\n",i,primes[i],gt[i]);
    }
}
int divisor(char gt[],char gt2[])
{  int i,ret;
  
  //dump_fact(gt);
  //dump_fact(gt2);

  
  for(i=0;i<12;i++)
    if(gt[i]>gt2[i])
       return(0);
  //printf("*!*");
  return(1);
}


void make_gt()
{
  int i;
  
  for(i=0;i<20;i++)
    factorize(p[i],&gt_[i][0]);
}

void prepare()
{ int i,j,k,l,mask;
  char gt[13],gt2[13],gt3[13];
  
  cntr=0;

  for(i=0;i<n;i++)
  {  
    memcpy(gt,&(gt_[i][0]),sizeof(gt));
    for(j=i;j<n;j++)
    {
      lcm(gt2,gt,&(gt_[j][0]));
      {
	for(k=j;k<n;k++)
	{
	  lcm(gt3,gt2,&(gt_[k][0]));
	  for(l=0;l<n;l++)
	  {
	    if(l!=i && l!=j && l!=k && divisor(&gt_[l][0],gt3))
	    {
		from[cntr]=mask=(1<<i)|(1<<j)|(1<<k);
		to  [cntr]=l;
		cntr++;
		//dump(mask,l);
	    }
	    
	  }
	}
      }
    }
  }
}
void dump_gt()
{
  int i;
  for(i=0;i<n;i++)
  {
    dump_fact(&gt_[i][0]);

  }
}
void dump1()
{
  int i;
  printf("n=%d\n",n);
  for(i=0;i<n;i++)
    printf("%d ",p[i]);
  printf("\n",n);
}

int main()
{
  int i,j,k,ret,c;
  
  
  scanf("%d",&n2);
  n=0;
  for(i=0;i<n2;i++)
  {
        scanf("%d",&c);
	  q[c]++;
	   
	  
  }
  for(i=2,n=0;i<=40;i++)
    {
      if(q[i]>0)
	{
	  p[n]=i;
	  n++;
	}
    }
  //dump1();
  make_gt();
  //dump_gt();
  
  if(n<=1)
    { if(q[1]==n2 || q[1]==0)  // 1種類だけのとき
	ret=1;
      else          //　１と他１種だけのとき
	ret=2;
    }
  else
  {
    prepare();
    //printf(":cntr=%d\n",cntr);  
    ret=solve();
    if(q[1]>0)
      ret++;
  }
  printf("%d\n",ret);
  
  return(0);
}


