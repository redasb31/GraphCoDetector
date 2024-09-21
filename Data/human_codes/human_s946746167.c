#include <stdio.h>
#include <string.h>

int main (void){

	int i=0;
	int number=0;
	int input[100000]={0};
	int count=0;
	int x=0;
	int y=0;
	int flag=0;
	
	scanf("%d",&number);

	for ( i=0; i < number; i++){
		scanf("%d", &input[i]);
		
	}

	i=0;
	x=0;

	while(1){
		flag=0;
		for(x=1; x*x < input[i]; x++){
			if ( (input[i]-x) % (2*x+1) == 0){
				flag=1;
				break;
			}
		}
		
		if(flag){
			count++;
		}
		i++;

		if (i == number){
			break;
		}
	}

	printf("%d\n",number-count );
	

	return 0;
}