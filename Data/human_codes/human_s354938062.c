#include<stdio.h>
void sort(void);
int right(int);
int left(int);
int min(int,int);
int N,M,p,cost=0;
int d[10000];

int right(int i)
{
	return d[i] - p;
}

int left(int i)
{
	return N - d[i] + p;
}

int min(int x,int y)
{
	if(x < y){
		return x;
	}
	else{
		return y;
	}
}

void sort(void)
{
	int i,j,T;
	for(i=0;i<M-1;i++){
		for(j=i+1;j<M;j++){
			if(d[i] > d[j]){
			T = d[i];
			d[i] = d[j];
			d[j] = T;
			}
		}
	}
}

int main(void)
{
	int i;
	scanf("%d %d %d",&N,&M,&p);
	for(i=0;i<M;i++) scanf("%d",&d[i]);
	sort();
	for(i=0;i<M;i++){
		cost = cost + min(right(i),left(i));
		p = d[i];
	}
	printf("%d\n",cost*100);	
	return 0;
}