#include<stdio.h>
int main(void)
{
	int n,k;
	int x1[50],y1[50],d1[50],x2[50],y2[50],d2[50];
	long long int sum;
	int area[102],flg[102];
	int y[102],d[102];
	int i,j,ii,jj,wk,p,c;
	
	scanf("%d %d",&n,&k);
	
	for(i=0;i<n;i++)	{
		scanf("%d %d %d %d %d %d",&x1[i],&y1[i],&d1[i],&x2[i],&y2[i],&d2[i]);
	}
	sum=0;
	for(i=0;i<n;i++)	{
		y[i]=y1[i];
		y[i+n]=y2[i];
		d[i]=d1[i];
		d[i+n]=d2[i];
	}
	for(i=0;i<n*2-1;i++)	{
		for(j=i+1;j<n*2;j++)	{
			if(y[i]>y[j])	{
				wk=y[i];
				y[i]=y[j];
				y[j]=wk;
			}
		}
	}
	for(i=0;i<n*2-1;i++)	{
		for(j=i+1;j<n*2;j++)	{
			if(d[i]>d[j])	{
				wk=d[i];
				d[i]=d[j];
				d[j]=wk;
			}
		}
	}
	sum=0;
	for(ii=0;ii<n*2;ii++)	{
		for(jj=0;jj<n*2;jj++)	{
			p=0;
			for(i=0;i<n;i++)	{
				if(y[ii]>=y1[i] && y[ii]<y2[i] && d[jj]>=d1[i] && d[jj]<d2[i])	{
					area[p]=x1[i];
					flg[p]=0;
					area[p+1]=x2[i];
					flg[p+1]=1;
					p+=2;
				}
			}
			for(i=0;i<p-1;i++)	{
				for(j=i+1;j<p;j++)	{
					if(area[i]>area[j])	{
						wk=area[i];
						area[i]=area[j];
						area[j]=wk;
						wk=flg[i];
						flg[i]=flg[j];
						flg[j]=wk;
					}
				}
			}
			c=0;
			for(i=0;i<p-1;i++)	{
				if(flg[i]==0)	c++;
				if(flg[i]==1)	c--;
				if(c>=k)	{
					sum+=(long long int)(area[i+1]-area[i])*(y[ii+1]-y[ii])*(d[jj+1]-d[jj]);
				}
			}
		}
	}
	printf("%lld\n",sum);
	return 0;
}
