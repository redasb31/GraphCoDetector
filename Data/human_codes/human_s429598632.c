#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD_BY 1000000009ULL

typedef unsigned long long ull;

typedef struct {
	int x;
	ull y;
} xy_t;

ull matrix[64][75][75];

void matrix_mul(ull in1[75][75],ull in2[75][75],ull out[75][75],int n) {
	ull result[75][75];
	int i,j,k;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			result[i][j]=0;
			for(k=0;k<n;k++) {
				result[i][j]+=(in1[i][k]*in2[k][j])%MOD_BY;
			}
			result[i][j]%=MOD_BY;
		}
	}
	memcpy(out,result,sizeof(result));
}

void matvec_mul(ull mat[75][75],ull vec[75],ull out[75],int n) {
	ull result[75];
	int i,j;
	for(i=0;i<n;i++) {
		result[i]=0;
		for(j=0;j<n;j++) {
			result[i]+=(mat[i][j]*vec[j])%MOD_BY;
		}
		result[i]%=MOD_BY;
	}
	memcpy(out,result,sizeof(result));
}

void make_matrix(int n) {
	int i;
	for(i=0;i<n;i++) {
		if(i>0)matrix[0][i][i-1]=1;
		matrix[0][i][i]=1;
		if(i<n-1)matrix[0][i][i+1]=1;
	}
	for(i=1;i<64;i++)matrix_mul(matrix[i-1],matrix[i-1],matrix[i],n);
}

void matrix_kaizyo(ull out[75][75],int n,ull kai) {
	int i;
	for(i=0;i<n;i++)out[i][i]=1;
	for(i=0;i<64;i++) {
		if(kai & (1ULL<<i))matrix_mul(matrix[i],out,out,n);
	}
}

/* syo-zyun */
int qsort_comp(const void* x,const void* y) {
	const xy_t* a=(const xy_t*)x;
	const xy_t* b=(const xy_t*)y;
	if((a->y)>(b->y))return 1;
	if((a->y)<(b->y))return -1;
	if((a->x)>(b->x))return 1;
	if((a->x)<(b->x))return -1;
	return 0;
}

int main(void) {
	int case_num;
	int w,n;
	ull h;
	int i;
	ull now[75];
	ull now_pos;
	xy_t noentry[30];
	ull now_matrix[75][75];
	for(case_num=1;;case_num++) {
		scanf("%d%llu%d",&w,&h,&n);
		if(w==0 && h==0 && n==0)break;
		for(i=0;i<n;i++)scanf("%d%llu",&noentry[i].x,&noentry[i].y);
		qsort(noentry,n,sizeof(xy_t),qsort_comp);
		make_matrix(w);
		now_pos=1;
		memset(now,0,sizeof(now));
		now[0]=1;
		for(i=0;i<n;i++) {
			if(noentry[i].y>now_pos) {
				memset(now_matrix,0,sizeof(now_matrix));
				matrix_kaizyo(now_matrix,w,noentry[i].y-now_pos);
				matvec_mul(now_matrix,now,now,w);
				now_pos=noentry[i].y;
			}
			now[noentry[i].x-1]=0;
		}
		if(now_pos<h) {
			memset(now_matrix,0,sizeof(now_matrix));
			matrix_kaizyo(now_matrix,w,h-now_pos);
			matvec_mul(now_matrix,now,now,w);
		}
		printf("Case %d: %llu\n",case_num,now[w-1]);
	}
	return 0;
}