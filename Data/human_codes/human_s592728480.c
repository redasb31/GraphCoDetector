#include <stdio.h>
int main (void)
{
	int m, f, r;
	
	while(1){
		scanf("%d %d %d",&m,&f,&r);
		if(m==-1 && f==-1 && r==-1) break;
		
		if(m==-1 || f==-1) printf("F");
		
		if(m+f>=80) printf("A");
		else if(m+f>=65 && m+f<80) printf("B");
		else if(m+f>=50 && m+f<65) printf("C");
		else if(m+f>=30 && m+f<50) 
			if(r>=50) printf("C");
			else	  printf("D");
		else printf("F");
		
	}
	printf("\n");
	return 0;
}