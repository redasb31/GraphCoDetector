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
			sscanf(&moziretu[i],"%d",&repeatNum);
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
	for(sekaisencount=0;sekaisencount<5;sekaisencount++) {
		char buffer[500]={0};
		int count=0;
		char* nowpointer;
		for(i=j=0;i<m && j<m;i++) {
			nowpointer=hg_tenkai;
			buffer[j]=sekaisen[sekaisencount][j];
			j++;
			while(j<m) {
				nowpointer=strstr(nowpointer,&buffer[i]);
				if(nowpointer==NULL)break;
				while(j<m && nowpointer[j-i]==sekaisen[sekaisencount][j]) {
					buffer[j]=sekaisen[sekaisencount][j];
					j++;
				}
				buffer[j]=sekaisen[sekaisencount][j];
				j++;
			}
			count+=j-i-1;
		}
		count+=(j-i-1)*(j-i)/2;
		if(count>max) {
			max=count;
			maxsekaisen=sekaisencount;
		}
	}
	printf("%d %d\n",maxsekaisen+1,max);
	return 0;
}