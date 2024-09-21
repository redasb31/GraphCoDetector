/*
  AOJ 2420
  Title:Anipero 2012
  @kankichi573
*/
#include <stdio.h>
#include <limits.h>

#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define max3(x,y,z) max(max(x,y),z)
int m,n,a[50],b[50],c[50];
int memo[51][9][50];     //step,lv1,zan more than 8 => 8

int fold0,foldrem,fold8,foldmax;


void solve_all()
{
  int step,zan,zan_1,lv2,lv2_1,lv1,ret1,ret2,ret,ret_z;
  int fold;
  
  for(step=n-1;step>=0;step--)
    for(zan=0;zan<=m;zan++)
	{
	  ret_z=c[step]+memo[step+1][0][zan];  // do nothing
	  for(lv2=0;lv2<=8;lv2++)
	    {
	      /*
	      printf("SZL=%d %d %d:",
	            step,zan,lv2);
	      */
	      if(zan==0 && lv2==0)   //no sailium
		  ret=INT_MIN;
	      else if(a[step]<=0 && b[step]<=0)
		{
		  if(zan>0)
		    ret1=a[step]+memo[step+1][1][zan-1];
		  else
		    ret1=INT_MIN;
		  if(lv2>0)
		    ret2=b[step]+memo[step+1][0][zan];
		  else
		    ret2=INT_MIN;
		  ret=max(ret1,ret2);
		}
	      else if(a[step]<=0)
		{
		  if(lv2>0)
		    ret2=lv2*b[step]+memo[step+1][0][zan];
		  else
		    ret1=INT_MIN;
		  ret=max(ret1,ret2);
		}
	      else
		{
		  ret=INT_MIN;
		  for(fold=0;fold<=min(8,zan);fold++)
		    {
		    if(a[step]>=b[step])
		      {
			if(b[step]>0)
			  {
			  ret1=fold*a[step]+min(8-fold,lv2)*b[step]+memo[step+1][fold][zan-fold];
			  }
			else
			  ret1=fold*a[step]+memo[step+1][fold][zan-fold];
			//printf("r1:=%d\n",ret1);	      	  		
		      }
		    else 
		      {
			//printf("***\n");
			if(a[step]>0)
			  ret1=min(fold,8-lv2)*a[step]+lv2*b[step]+memo[step+1][fold][zan-fold];
			else
			  {
			   
			    ret1=lv2*b[step]+memo[step+1][fold][zan-fold];
			  }
		      }
		    ret=max(ret,ret1);
		    }
		}
	      //printf("r:=%d\n",ret);	      	  		
	      ret=max(ret,ret_z);
	      //printf("r==%d\n",ret);	      	  		
	    memo[step][lv2][zan]=ret;
	  }
    }
}
void solve()
{
  int i,j;

  for(i=0;i<=8;i++)
    for(j=0;j<50;j++)
	memo[n][i][j]=0;

  solve_all();
}


main()
{
  int i,ret,l2;

#ifdef DEBUG
  scanf("%d %d %d",&n,&m,&l2);
#else
  scanf("%d %d",&n,&m);
#endif
  //printf("%d %d %d\n",n,m,l2);
  for(i=0;i<n;i++)
    {
      scanf("%d %d %d",&a[i],&b[i],&c[i]);
    }
  solve();
#ifdef DEBUG
  ret=memo[0][l2][m];
#else
  ret=memo[0][0][m];
#endif
  printf("%d\n",ret);
  return(0);
}