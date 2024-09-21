#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int a=0,b=0,q,i,j,k,kind=-1,pNum;
	char str[1001],meirei[10],tmp[1000];
	char print_str[]="print",reverse_str[]="reverse",replace_str[]="replace";
	
	scanf("%s",str);
	scanf("%d",&q);
	//puts("--以下命令--");
	
	for(i=0;i<q;i++){
		scanf("%s",meirei);
		scanf("%d %d",&a,&b);
		if(strcmp(print_str,meirei)==0){
			for(j=a;j<=b;j++){
				printf("%c",str[j]);
			}
			printf("\n");
			//puts("\nprint終");
		}
		if(strcmp(reverse_str,meirei)==0){
			//printf("tmp:");
			for(j=a;j<=b;j++){
				tmp[j-a]=str[j];
				//printf("%c",tmp[j-a]);
			}//printf("\n");
			pNum=b-a+1;
			k=0;
			for(j=b;j>=a;j--){
				str[j]=tmp[k];
				k++;
			}
			//puts("reverse終了");
		}
		if(strcmp(replace_str,meirei)==0){
			//puts("replaceします");
			scanf("%s",tmp);
			pNum=strlen(tmp);
			//printf("len=%d",pNum);
			for(j=a;j<=b;j++){
				str[j]=tmp[j-a];
			}
			//puts("replace終了");
		}
		
		
		a=0;b=0;
	}
	
	
return 0;
}