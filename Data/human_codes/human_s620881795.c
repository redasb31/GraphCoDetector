#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void *arg1, const void *arg2){
	return(strcmp(*(char **)arg1, *(char **)arg2));
}

int main(){
	char s[5001];
	int k,g=0,i,j,c=0,l;
	scanf("%s%d",s,&k);
	while(s[g]!=0)g++;
	char ss[25000][6];
	int num[25000];
	for(i=0;i<25000;i++)num[i]=i;
	for(i=0;i<g;i++){
		for(j=0;j<5&&i+j<g;j++){
			for(l=0;l<=j;l++)ss[c][l]=s[i+l];
			ss[c][5]='\0';
			c++;
		}
	}
//	for(i=0;i<c;i++)printf("%s\n",ss[i]);
//	qsort((void*)ss,c,sizeof(char*),compare);
	for(i=0;i<c;i++){
		for(j=0;j<i;j++){
			if(strcmp(ss[num[i]],ss[num[j]])<0){
/*				char tmp[7]={0};
				strcpy(tmp,ss[i]);
				for(l=0;l<5;l++)ss[i][l]='\0';
				strcpy(ss[i],ss[j]);
				for(l=0;l<5;l++)ss[j][l]='\0';
				strcpy(ss[j],tmp);
*/			
			int tmp=num[i];
			num[i]=num[j];
			num[j]=tmp;
			}
		}
	}
//	for(i=0;i<c;i++)printf("%s\n",ss[i]);
	int count=0;
	for(i=0;i<c;i++){
		if(count==k-1){
			printf("%s\n",ss[num[i]]);
			return 0;
		}
		if(strcmp(ss[num[i]],ss[num[i+1]])<0)count++;
	}
}