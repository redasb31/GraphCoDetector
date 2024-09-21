#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	double re, im;
} comp;
comp csum(comp x, comp y){
	return (comp){x.re + y.re, x.im + y.im};
}
comp cprod(comp x, comp y){
	return (comp){x.re*y.re - x.im*y.im, x.re*y.im + x.im*y.re};
}
int bit_rev(int x, int h){
	int res = 0;
	for(int i=0; i<h; i++){
		res <<= 1;
		res |= x&1;
		x >>= 1;
	}
	return res;
}
void bit_rev_perm(comp a[], int h){
	comp *A = (comp*)malloc(sizeof(comp)*(1<<h));
	memcpy(A, a, sizeof(comp)*(1<<h));
	for(int i=0; i<1<<h; i++){
		a[bit_rev(i, h)] = A[i];
	}
	free(A);
	return;
}
void dft(comp a[], int h){
	bit_rev_perm(a, h);
	for(int s=1; s<=h; s++){
		int m = 1<<s;
		comp zeta = (comp){cos(2. * M_PI / (double)m), sin(2. * M_PI / (double)m)};
		for(int k=0; k<1<<h; k+=m){
			comp pow_zeta = (comp){1., 0.};
			for(int j=0; j<m/2; j++){
				comp t = cprod(pow_zeta, a[k+j+m/2]);
				comp u = a[k+j];
				a[k+j] = csum(u, t);
				a[k+j+m/2] = csum(u, cprod((comp){-1.}, t));
				pow_zeta = cprod(pow_zeta, zeta);
			}
		}
	}
	return;
}
void idft(comp a[], int h){
	bit_rev_perm(a, h);
	for(int s=1; s<=h; s++){
		int m = 1<<s;
		comp zeta = (comp){cos(2. * M_PI / (double)m), -sin(2. * M_PI / (double)m)};
		for(int k=0; k<1<<h; k+=m){
			comp pow_zeta = (comp){1., 0.};
			for(int j=0; j<m/2; j++){
				comp t = cprod(pow_zeta, a[k+j+m/2]);
				comp u = a[k+j];
				a[k+j] = csum(u, t);
				a[k+j+m/2] = csum(u, cprod((comp){-1., 0.}, t));
				pow_zeta = cprod(pow_zeta, zeta);
			}
		}
	}
	return;
}

const long mod = 998244353;
int N, M;
comp A[1<<20], B[1<<20];
int main(){
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++)scanf("%lf", &A[i].re);
	for(int i=0; i<M; i++)scanf("%lf", &B[i].re);
	dft(A, 20); dft(B, 20);
	for(int i=0; i<1<<20; i++)A[i] = cprod(A[i], B[i]);
	idft(A, 20);
	for(int i=0; i<N+M-1; i++){
		if(i)putchar(32);
		printf("%ld", (long)round(A[i].re / (double)(1<<20))%mod);
	}putchar(10);
	return 0;
}