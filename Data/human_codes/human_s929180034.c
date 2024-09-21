#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#ifdef __cplusplus
#include <bits/stdc++.h>
#endif

bool arr[101];

uint32_t nextpint(void){ char c=getchar_unlocked(); while(c<'0'||'9'<c) c=getchar_unlocked(); uint32_t x=0; while('0'<=c && c<='9'){ x=x*10+c-'0'; c=getchar_unlocked(); } return x; }
void printint(uint32_t x){ if(x<0){x=-x; putchar_unlocked('-');}else if(x==0){putchar_unlocked('0');} int d=0; char s[10]; while(x){ s[d]='0'+x%10; x/=10; d++; } for (int i=d-1; i>=0; i--) putchar_unlocked(s[i]); putchar_unlocked('\n'); }

uint32_t h[100000];
bool is[100000];

int main(void){
	uint32_t n=nextpint();
	uint32_t m=nextpint();
	for(uint32_t i=0; i<n; i++){
		h[i]=nextpint();
	}
	for(uint32_t i=0; i<m; i++){
		uint32_t a=nextpint()-1;
		uint32_t b=nextpint()-1;
		if(h[a]>h[b]){
			is[b]=true;
		}else if(h[a]<h[b]){
			is[a]=true;
		}else{
			is[a]=true;
			is[b]=true;
		}
	}
	uint32_t ans=0;
	for(uint32_t i=0; i<n; i++){
		if(!is[i]) ans++;
	}
	printint(ans);
}
