#include<stdio.h>
long long gcd(long long a,long long b){  
    int temp;  
    if(a < b){  
      temp = a;  
      a = b;  
      b = temp;  
    }    
    if(a%b == 0)
	{  
        return b;    
    }else
	{    
        return gcd(b,a%b);    
    }    
} 
int main()
{
	int n;
	long long  gcd(long long a,long long b);
    long long  c[109],sum;
	while(~scanf("%d",&n))
	{
		sum=0;
		for(int i=0;i<n;i++)
		scanf("%lld",&c[i]);
		while(n==1)
		{
			printf("%lld\n",c[0]);
			return 0;
		}
			for(int i=0;i<n-1;i++)
			{	
				sum=(c[i]/gcd(c[i],c[i+1]))*c[i+1];
				c[i+1]=sum;
			}
			printf("%lld\n",sum);
		
	}
}