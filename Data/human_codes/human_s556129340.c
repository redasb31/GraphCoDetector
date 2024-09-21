#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
	long long int code;
	int steps;
} puzz;

int q[10000000][14],size[30000],size2[30000];
long long int FR,TO,SW;
puzz* hash[30000][100],hash2[30000][100];

void swap (int* x,int* y){
	int z;
	z=*x;
	*x=*y;
	*y=z;
}

long long int convert(int a[]){
	long long int ret=0;
	int i;
	for(i=0;i<13;i++)ret=ret*13+a[i];
	return ret;
}

void hashadd(long long int code,int step){
	int ccc=code%30000;
	puzz* ppp=(puzz*)malloc(sizeof(puzz));
	ppp->code=code;
	ppp->steps=step;
	if(size[ccc]>99){fprintf(stderr,"SIZE OVER!! (%d)\n",ccc);return;}
	hash[ccc][size[ccc]]=ppp;
	size[ccc]++;
}

int hashsearch(long long int code){
	int ccc=code%30000;
	int i=size[ccc];
	for(i--;i>=0;i--){
		if(hash[ccc][i]->code==code)return hash[ccc][i]->steps;
	}
	return -1;
}

void mark(int x,int y){
	int k;
	long long int cd;

	swap(&q[FR][x],&q[FR][y]);
	cd=convert(q[FR]);

	if(SW==1 || hashsearch(cd)<0){
		for(k=0;k<14;k++){q[TO][k]=q[FR][k];}
		q[TO][13]++;
		if(SW==0)hashadd(cd,q[TO][13]);
		TO++;
	}

	swap(&q[FR][x],&q[FR][y]);

}

void check(){
	if(q[FR][0]==0){mark(0,2);}
	if(q[FR][1]==0){mark(1,2);mark(1,5);}
	if(q[FR][2]==0){mark(2,0);mark(2,1);mark(2,3);mark(2,6);}
	if(q[FR][3]==0){mark(3,2);mark(3,7);}
	if(q[FR][4]==0){mark(4,5);}
	if(q[FR][5]==0){mark(5,1);mark(5,4);mark(5,6);mark(5,9);}
	if(q[FR][6]==0){mark(6,2);mark(6,5);mark(6,7);mark(6,10);}
	if(q[FR][7]==0){mark(7,3);mark(7,6);mark(7,8);mark(7,11);}
	if(q[FR][8]==0){mark(8,7);}
	if(q[FR][9]==0){mark(9,5);mark(9,10);}
	if(q[FR][10]==0){mark(10,6);mark(10,9);mark(10,11);mark(10,12);}
	if(q[FR][11]==0){mark(11,7);mark(11,10);}
	if(q[FR][12]==0){mark(12,10);}
}


int main(){
	int i,ans;
	long long int cd;

	for(i=1;i<12;i++)q[0][i]=i;
	q[0][0]=0;q[0][12]=0;q[0][13]=0;

	FR=0;TO=1;SW=0;

	while(FR<TO && q[FR][13]<=13){
		check();
		FR++;
	}

	while(scanf("%d",&q[0][0])*q[0][0]>=0){
		for(i=1;i<13;i++)scanf("%d",&q[0][i]);
		q[0][13]=0;FR=0;TO=1;SW=1;ans=9999;
		//for(i=0;i<30000;i++)size2[i]=0;

		while(FR<TO){
			cd=hashsearch(convert(q[FR]));
			if(cd>=0){
				if(FR>0 && cd!=14)fprintf(stderr,"%d?\n",cd);
				ans=(int)cd+q[FR][13];
				break;
			}
			if(q[FR][13]<6)check();
			FR++;
		}

		if(ans>20)printf("NA\n"); else printf("%d\n",ans);
	}

	return 0;
}