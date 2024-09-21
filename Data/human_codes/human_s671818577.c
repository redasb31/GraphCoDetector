#include <stdio.h>

typedef struct {
	int m[50][50];
} MATRIX;

void mulMatVec(int out[50],const MATRIX* m,const int v[50],int n,int modBy) {
	int i,j;
	for(i=0;i<n;i++) {
		out[i]=0;
		for(j=0;j<n;j++) {
			out[i]+=m->m[i][j]*v[j];
		}
		out[i]%=modBy;
	}
}

void mulMatMat(MATRIX* out,const MATRIX* x,const MATRIX* y,int n,int modBy) {
	int i,j,k;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			out->m[i][j]=0;
			for(k=0;k<n;k++)out->m[i][j]+=x->m[i][k]*y->m[k][j];
			out->m[i][j]%=modBy;
		}
	}
}

void powMat(MATRIX* out,const MATRIX* in,int powNum,int n,int modBy) {
	MATRIX resultBuf[2];
	MATRIX mulBuf[2];
	int i,j;
	int resultNo=0;
	int mulNo=0;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			mulBuf[0].m[i][j]=in->m[i][j];
			resultBuf[0].m[i][j]=(i==j?1:0);
		}
	}
	while(powNum>0) {
		if(powNum&1) {
			mulMatMat(&resultBuf[1-resultNo],
				&resultBuf[resultNo],&mulBuf[mulNo],n,modBy);
			resultNo=1-resultNo;
		}
		mulMatMat(&mulBuf[1-mulNo],&mulBuf[mulNo],&mulBuf[mulNo],n,modBy);
		mulNo=1-mulNo;
		powNum>>=1;
	}
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++)out->m[i][j]=resultBuf[resultNo].m[i][j];
	}
}

int main(void) {
	int N,M,A,B,C,T;
	while(scanf("%d%d%d%d%d%d",&N,&M,&A,&B,&C,&T)==6 && (N|M|A|B|C|T)!=0) {
		MATRIX automaton;
		MATRIX automatonStatus;
		int initialStatus[50];
		int resultStatus[50];
		int i,j;
		for(i=0;i<N;i++)scanf("%d",&initialStatus[i]);
		for(i=0;i<N;i++) {
			for(j=0;j<N;j++) {
				switch(i-j) {
					case  1: automaton.m[i][j]=A;break;
					case  0: automaton.m[i][j]=B;break;
					case -1: automaton.m[i][j]=C;break;
					default: automaton.m[i][j]=0;break;
				}
			}
		}
		powMat(&automatonStatus,&automaton,T,N,M);
		mulMatVec(resultStatus,&automatonStatus,initialStatus,N,M);
		for(i=0;i<N;i++) {
			printf("%d%c",resultStatus[i],i+1<N?' ':'\n');
		}
	}
	return 0;
}