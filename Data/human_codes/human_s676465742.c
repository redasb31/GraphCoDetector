#include <stddio.h>

int main(void)
{
	int n,min,a[1000];
	int i,j,s;
	
	 while(scanf("%d",&n)){
        if(n==0)
        break;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
	min=0;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                s=a[i]-a[j];
                if(s<min)
                min=s;
            }
        }
        if(min==0)
        printf("0\n");
        else
        printf("%d\n",min);
		
		return 0;
    }
}
