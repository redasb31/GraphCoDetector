#include<stdio.h>
#include<string.h>
#define eps 1e-14
double f_pow(double x,int n){
	double res=1;
	while(n--)res*=x;
	return res;
}

struct Man{
	double p,t,v;
	void get(){
		scanf("%lf%lf%lf",&p,&t,&v);
		p/=100;
	}
};
Man man[100];
int N,M;
double L;
double tim[100][51],tsum[100][51];
double rate[100][51];
double C[51][51];
void get_C(){
	int i,j;
	C[0][0]=1;
	C[1][0]=C[1][1]=1;
	for(i=2;i<51;i++){
		C[i][0]=C[i][i]=1;
		for(j=1;j<i;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
		}
	}
}
void get_data(){
	scanf("%d%d%lf",&N,&M,&L);
	int i;
	for(i=0;i<N;i++)man[i].get();
}
void get_tim(){
	int i,j;
	for(i=0;i<N;i++){
		rate[i][0]=f_pow(1-man[i].p,M);
		tim[i][0]=L/man[i].v;
		for(j=1;j<=M;j++){
			if(M-j>=j)rate[i][j]=C[M][j]*f_pow(man[i].p*(1-man[i].p),j)*f_pow(1-man[i].p,M-j-j);
			else rate[i][j]=C[M][j]*f_pow(man[i].p*(1-man[i].p),M-j)*f_pow(man[i].p,j+j-M);
			tim[i][j]=tim[i][j-1]+man[i].t;
		}
		tsum[i][M]=rate[i][M];
		for(j=M-1;j>=0;j--)tsum[i][j]=tsum[i][j+1]+rate[i][j];
	}
}
double bina(int ren,double t){
	int h=M,l=0,mid;
	while(h>l){
		mid=(h+l)>>1;
		if(tim[ren][mid]<t+eps)l=mid+1;
		else h=mid;
	}
	return tsum[ren][h];
}
double get_win(int winner,double t){
	int i;
	double res=1;
	for(i=0;i<N;i++){
		if(i==winner)continue;
		if(tim[i][M]<t+eps)return 0;
		res*=bina(i,t);
	}
	return res;
}
void run(){
	int i,j;
	double sum;
	for(i=0;i<N;i++){
		sum=0;
		for(j=0;j<=M;j++){
			sum+=rate[i][j]*get_win(i,tim[i][j]);
		}
		printf("%.9lf\n",sum);
	}
}
int main(){
	get_C();
	get_data();
	get_tim();

	run();
	return 0;
}