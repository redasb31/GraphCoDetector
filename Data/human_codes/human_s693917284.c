#include<stdio.h>

int main(void){
	
	int i,sum,a,b,c;
	int top,topn;
	char topc;
	
	i = 1;
	top = 0;
	
	while(1){
		
		scanf(" %d %d",&a,&b);
		
		if(a == 0 && b == 0){
			break;
		}
		
		c = a + b;
		
		if(top > c){
			top = c;
			topn = i;
		}
		
		i++;
		
		if(i==5){
			switch(topn){
				case 1:
					topc = "A";
					break;
				case 2:
					topc = "B";
					break;
				case 3:
					topc = "C";
					break;
				case 4:
					topc = "D";
					break;
				case 5:
					topc = "E";
					break;
			}
			i = 1;
			printf("%c %d",topc,top);
		}
	}
	
	return(0);
	
}