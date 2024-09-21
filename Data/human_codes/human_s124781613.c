#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n,m,k;
char hyadainnzugeeto[500];
char sekaisen[5][500];

char hg_tenkai[1000000];
char* now_tenkaisaki;

void moziretu_tenkai(const char* moziretu,int length,int repeat) {
	int i,j;
	char* initial_tenkaisaki=now_tenkaisaki;
	int tenkaiLength,repeatNumModify;
	for(i=0;i<length;i++) {
		if(isalpha(moziretu[i])) {
			*(now_tenkaisaki++)=moziretu[i];
		} else if(isdigit(moziretu[i])) {
			int startPos;
			int kakkoNum;
			int repeatNum;
			for(j=i;isdigit(moziretu[j]);j++);
			startPos=j+1;
			kakkoNum=1;
			for(j=startPos;kakkoNum>0;j++) {
				if(moziretu[j]=='(')kakkoNum++;
				else if(moziretu[j]==')')kakkoNum--;
			}
			while(moziretu[i]=='0')i++;
			if(startPos-i-1>9) {
				repeatNum=10000;
			} else {
				sscanf(&moziretu[i],"%d",&repeatNum);
			}
			moziretu_tenkai(&moziretu[startPos],j-1-startPos,repeatNum);
			i=j-1;
		}
	}

	tenkaiLength=(int)(now_tenkaisaki-initial_tenkaisaki);
	repeatNumModify=(m+tenkaiLength-1)/tenkaiLength;
	if(repeatNumModify<=1)repeatNumModify=2;
	if(repeatNumModify>repeat)repeatNumModify=repeat;
	if(repeatNumModify>1 && tenkaiLength>(m-1)*2+1) {
		char* tenkaisaki_last=now_tenkaisaki;
		strncpy(now_tenkaisaki,initial_tenkaisaki,m-1);
		now_tenkaisaki+=m-1;
		*(now_tenkaisaki++)='*';
		strncpy(now_tenkaisaki,tenkaisaki_last-(m-1),m-1);
		now_tenkaisaki+=m-1;
	} else {
		for(i=1;i<repeatNumModify;i++) {
			strncpy(now_tenkaisaki,initial_tenkaisaki,tenkaiLength);
			now_tenkaisaki+=tenkaiLength;
		}
	}
}

int main(void) {
	int i,j;
	int sekaisencount;
	int max,maxsekaisen;

	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",hyadainnzugeeto);
	for(i=0;i<k;i++)scanf("%s",sekaisen[i]);

	now_tenkaisaki=&hg_tenkai[0];
	moziretu_tenkai(hyadainnzugeeto,n,1);
	*now_tenkaisaki=0;

	max=maxsekaisen=0;
	for(sekaisencount=0;sekaisencount<k;sekaisencount++) {
		char buffer[500]={0};
		int count=0;
		char* nowpointer;
		int complete=0;
		buffer[0]=sekaisen[sekaisencount][0];
		for(i=0,j=1;i<m && !complete;i++) {
			nowpointer=hg_tenkai;
			while(1) {
				nowpointer=strstr(nowpointer,&buffer[i]);
				if(nowpointer==NULL)break;
				while(j<m && nowpointer[j-i]==sekaisen[sekaisencount][j]) {
					buffer[j]=sekaisen[sekaisencount][j];
					j++;
				}
				if(j<m) {
					buffer[j]=sekaisen[sekaisencount][j];
					j++;
				} else {
					complete=1;
					break;
				}
			}
			count+=j-i-1;
			if(complete)count++;
		}
		count+=(j-i)*(j-i+1)/2;
		if(count>max) {
			max=count;
			maxsekaisen=sekaisencount;
		}
	}
	printf("%d %d\n",maxsekaisen+1,max);
	return 0;
}