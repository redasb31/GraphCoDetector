#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int p;
	int q;
} ship;

int comp(const void *p1,const void *p2);

int main(void){
	int i,j;
	ship *map;
	int *index;
	int n,m,tmp,flg=0;
	scanf("%d%d",&n,&m);
	map=(ship *)calloc(m,sizeof(ship));
	index=(int*)calloc(n+1,sizeof(int));
	for(i=0;i<m;i++){
		scanf("%d%d",&map[i].p,&map[i].q);
	}
	
	qsort(map,m,sizeof(ship),comp);
	
	//for(i=0;i<m;i++) printf("%d %d\n",map[i].p,map[i].q);
	tmp=0;
	for(i=0;i<=n;i++) index[i]=0;
	for(i=0;i<m;i++){
		if(map[i].p>tmp){
			tmp=map[i].p;
			index[map[i].p]=i;
		}
	}
	index[n]=m;
	
	for(i=1;i<=n;i++){
		//printf("%d%c",index[i],(i==n)?'\n':' ');
	}
	for(i=0;i<index[2];i++){
		for(j=index[map[i].q];map[j].p!=map[i].p;j++){
			//printf("%d %d -> %d\n",i,j,map[j].q);
			if(map[j].q==n){
				flg=1;
				break;
			}
		}
		if(flg==1) break;
	}
	
	if(flg==1) puts("POSSIBLE");
	else puts("IMPOSSIBLE");
	free(map);
	return 0;
}

int comp(const void *p1,const void *p2){
	const ship *d1,*d2;
	d1=(const ship *)p1;
	d2=(const ship *)p2;
	if(d1->p==d2->p) return d1->q-d2->q;
	else return d1->p-d2->p;
}