#include <stdio.h>


int main(){
	
	int a, b;
	double c;
	char str[1000];
	int n, s;
	
	int i;
	int ret;
	
	while(1){
		
		ret = scanf("%d %d %d", &a, &b, &n);
		
		if(ret == EOF){
			
			break;
			
		}
		
		s = 0;
		c = (double)a/(double)b;
		str[0] = '\0';
		
		snprintf(str, sizeof(str), "%.999f", c);
		puts(str);
		
		for(i=2; i<n+2; i++){
			
			s += (str[i]-'0');
			
		}
		
		printf("%d\n", s);
		
	}
	
}