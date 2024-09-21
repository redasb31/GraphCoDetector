#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void no(int *x,int *y,int *z,int *s){
	int n=*x;
	*x=*y;
	*y=7-n;
	*s+=*x;
}
void ea(int *x,int *y,int *z,int *s){
	int n=*x;
	*x=7-*z;
	*z=n;
	*s+=*x;
	return;
}
void we(int *x,int *y,int *z,int *s){
	int n=*x;
	*x=*z;
	*z=7-n;
	*s+=*x;
	return;
}
void so(int *x,int *y,int *z,int *s){
	int n=*y;
	*y=*x;
	*x=7-n;
	*s+=*x;
	return;
}
void ri(int *x,int *y,int *z,int *s){
	int n=*y;
	*y=*z;
	*z=7-n;
	*s+=*x;
	return;
}
void le(int *x,int *y,int *z,int *s){
	int n=*z;
	*z=*y;
	*y=7-n;
	*z=n;
	*s+=*x;
	return;
}

int main(){
	int n,i,j=0,sum,a1,a2,a3,num[1000];
	sum=1;a1=1;a2=2;a3=3;
	char c[6];
	for(;;j++){
		scanf("%d",&n);
		if(n==0) break;	
		while(n>0){
			A:
			scanf("%s",c);
			if(strcmp(c,"North")==0){
				no(&a1,&a2,&a3,&sum);
			}else if(strcmp(c,"East")==0){
				ea(&a1,&a2,&a3,&sum);
			}else if(strcmp(c,"West")==0){
				we(&a1,&a2,&a3,&sum);
			}else if(strcmp(c,"South")==0){
				so(&a1,&a2,&a3,&sum);
			}else if(strcmp(c,"Right")==0){
				ri(&a1,&a2,&a3,&sum);
			}else if(strcmp(c,"Left")==0){
				le(&a1,&a2,&a3,&sum);
			}else{
				printf("error!");
				goto A;
			}			
			n--;
		}
		printf("%d\n",sum);
		sum=1;a1=1;a2=2;a3=3;
		c[0]='\0';
	}
	
	return 0;
}