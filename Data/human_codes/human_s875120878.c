#include<stdio.h>
int main(void){
	char all[10];
	int a,cnt=0,max=0;
	scanf("%s",all);
	for(a=0;a<10;a++){
		if(all[a]=='A'){
			cnt++;
			if(a==9){
				if(max<cnt){
					max=cnt;
				}
			}
		}
		else if(all[a]=='T'){
			cnt++;
			if(a==9){
				if(max<cnt){
					max=cnt;
				}
			}
		}
		else if(all[a]=='G'){
			cnt++;
			if(a==9){
				if(max<cnt){
					max=cnt;
				}
			}
		}
		else if(all[a]=='C'){
			cnt++;
			if(a==9){
				if(max<cnt){
					max=cnt;
				}
			}
		}
		else{
			if(max<cnt){
				max=cnt;
				cnt=0;
			}else{
				cnt=0;
			}
		}
	}
	printf("%d",max);
return 0;
}