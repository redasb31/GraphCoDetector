#include<stdio.h>
struct _list{
	int i;
	int j;
	int k;
	int r;
}typedef _list;
_list d[1005];

void sort(int N){
	int i,j,t;
	for(i=1;i<=N;i++){
		for(j=i;j<=N;j++){
			if(d[i].r<d[j].r){
				t=d[i].i;
				d[i].i=d[j].i;
				d[j].i=t;

				t=d[i].j;
				d[i].j=d[j].j;
				d[j].j=t;

				t=d[i].k;
				d[i].k=d[j].k;
				d[j].k=t;

				t=d[i].r;
				d[i].r=d[j].r;
				d[j].r=t;
			}
		}
	}

}
int main(){

	int aNm,bNm,cNm;
	int N,i,j,k,r,s;
	for(;scanf("%d %d %d",&aNm,&bNm,&cNm)&&(aNm||bNm||cNm);){
		int L[399]={2};
		for(s=1;s<=300;s++)
			L[s]=2;
		scanf("%d",&N);
	//	printf("N:%d\n",N);
		for(s=1;s<=N;s++){
//			printf("s:%d\n",s);
			scanf("%d %d %d %d",&d[s].i,&d[s].j,&d[s].k,&d[s].r);
		}
		sort(N);
		for(s=1;s<=N;s++){
	//		printf("%d %d %d\n",L[d[s].i],L[d[s].j],L[d[s].k]);
			if(d[s].r){
		//		printf("r:1\n");
				L[d[s].i]=1;
				L[d[s].j]=1;
				L[d[s].k]=1;
			}
			else{
			//	printf("r:0\n");
				if(L[d[s].i]==2&&L[d[s].j]==1&&L[d[s].k]==1)L[d[s].i]=0;
				if(L[d[s].j]==2&&L[d[s].i]==1&&L[d[s].k]==1)L[d[s].j]=0;
				if(L[d[s].k]==2&&L[d[s].i]==1&&L[d[s].j]==1)L[d[s].k]=0;
			}
		}
		for(s=1;s<=aNm+bNm+cNm;s++){
			if(L[s]==1)printf("1\n");
			else if(L[s]==0)printf("0\n");
			else printf("2\n");
		}
	}
	return 0;
}