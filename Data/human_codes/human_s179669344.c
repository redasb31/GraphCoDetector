#include <float.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define P 1000000007

int comp(const void *a, const void *b){return *(int*)a-*(int*)b;}
int compw(const void *a, const void *b){return (*(int*)a>*(int*)b)-(*(int*)a<*(int*)b);}
int compr(const void *a, const void *b){return *(int*)b-*(int*)a;}

uint32_t nextpint(void){ char c=getchar(); while(c<'0'||'9'<c) c=getchar(); uint32_t x=0; while('0'<=c && c<='9'){ x=x*10+c-'0'; c=getchar(); } return x; }
uint32_t nextstr(char *s){ char c=getchar(); while(c==' '||c=='\n') c=getchar(); uint32_t len=0; while(c!=' '&&c!='\n'){ *s++=c; len++; c=getchar(); } *s='\0'; return len; }

inline int max2(const int a, const int b){return a>b?a:b;}
inline int min2(const int a, const int b){return a>b?b:a;}
inline int dif2(const int a, const int b){return a>b?a-b:b-a;}

#define nextInt nextpint
int main(void){
	int N = nextInt();
	int *A = calloc(N, sizeof(int));
	for(int i=0; i<N; i++){
		A[i] = nextInt();
	}
	qsort(A, N, sizeof(int), comp);
	long answer = 0;
	int l = N/2;
	for(int i=N-1; i>=l; i--){
		answer += A[i]*2;
	}
	for(int i=0; i<l; i++){
		answer -= A[i]*2;
	}
	if(N%2==0){
		answer += A[l-1];
		answer -= A[l];
	}else{
		if(A[l-1]+A[l+1] > A[l]*2){
			answer += A[l-1];
			answer -= A[l]*3;
		}else{
			answer -= A[l]+A[l+1];
		}
	}
	printf("%ld\n", answer);
}
