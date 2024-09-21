#include <stdio.h>
#include <string.h>

typedef struct{
	char name[6];
	long num;
	char f;
}product;

int main(void){
	long n=0, i, j, t, count=0;
	char str[6];
	product p[300000];
	
	scanf("%ld", &n);
	for(i=0; i<n; i++){
		int flag=0;
	
		scanf(" %s %ld", str, &t);
		
		for(j=0; j<count; j++){
			if(strcmp(p[j].name, str)==0){
				p[j].num+=t;
				flag=1;
				break;
			}
		}
		
		if(flag==0){
			strcpy(p[count].name, str);
			p[count].num = t;
			count++;
		}	
		
		//printf("count:%ld\n",count);
	}
	
	
	//ここまではおｋ，あとはソート
	for(i=0; i<count; i++){
		for(j=0; j<count; j++){
			if(strcmp(p[i].name, p[j].name) < 0){
				product tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}	
	
	long r=0;

	while(r<6){
		//printf("now: %ld\n", r);
		for(i=0; i<count; i++){
			if(p[i].name[r]=='\0' && p[i].f != 'N'){
				printf("%s %ld\n", p[i].name, p[i].num);
				p[i].f='N';
			}
		}
		r++;
	}

	return 0;
}