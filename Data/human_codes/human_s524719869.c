#include <stdio.h>
#include <string.h>

int main()
{
	char s[100];
	scanf("%s",s);
	int size = strlen(s);
	int betw = 0;
	int count = 0;
	int tmp=0;
	for (int i = 0; i < size; ++i)
	{
		if(count==0&&s[i]=='k'){
			count++;
			if(i-tmp >=1){
				betw++;
			}
			tmp = i;
		}else if(count==1&&s[i]=='e'){
			count++;
			if(i-tmp >= 2){
				betw++;
			}
			tmp = i;
		}else if(count==2&&s[i]=='y'){
			count++;
			if(i-tmp >= 2){
				betw++;
			}
			tmp =i;
		}else if(count==3&&s[i]=='e'){
			count++;
			if(i-tmp >= 2){
				betw++;
			}
			tmp = i;
		}else if(count==4&&s[i]=='n'){
			count++;
			if(i-tmp >= 2){
				betw++;
			}
			tmp = i;
		}else if(count==5&&s[i]=='c'){
			count++;
			if(i-tmp >= 2){
				betw++;
			}
			tmp = i;
		}else if(count==6&&s[i]=='e'){
			count++;
			if(i-tmp >= 2){
				betw++;
			}
			if((size-1) - i >=1){
				betw++;
			}
		}
	}
	if(count==7&&betw<=1){
		printf("YES");
	}else{
		printf("NO");
	}
	return 0;
}
