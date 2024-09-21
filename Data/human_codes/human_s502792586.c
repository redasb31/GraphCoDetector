#include <stdio.h>

#define MOD_BY 1000000007
#define BUFFER_SIZE 100

char A[BUFFER_SIZE];
char B[BUFFER_SIZE];
char C[BUFFER_SIZE];

/* [pos][carry] */
int memo[BUFFER_SIZE][2];

int search(int pos,int carry) {
	int ret=0;
	int a,b;
	int amin,amax,bmin,bmax;
	if(pos<0)return (carry==0?1:0);
	if(memo[pos][carry]>0)return memo[pos][carry]-1;
	if(A[pos]=='?'){amin=0;amax=9;} else amin=amax=A[pos]-'0';
	if(B[pos]=='?'){bmin=0;bmax=9;} else bmin=bmax=B[pos]-'0';
	for(a=amin;a<=amax;a++) {
		for(b=bmin;b<=bmax;b++) {
			int c=a+b+carry;
			int cv=c%10,cc=c/10;
			/* zero at first digit is not arrowed */
			if(pos==0 && (a==0 || b==0 || cv==0))continue;
			if(C[pos]=='?' || C[pos]==cv+'0') {
				ret+=search(pos-1,cc);
				if(ret>=MOD_BY)ret-=MOD_BY;
			}
		}
	}
	memo[pos][carry]=ret+1;
	return ret;
}

int main(void) {
	while(scanf("%s",A)==1) {
		int i;
		if(A[0]=='0')break;
		if(scanf("%s%s",B,C)!=2)break;
		for(i=0;i<BUFFER_SIZE;i++) {
			memo[i][0]=memo[i][1]=0;
		}
		for(i=0;A[i]!='\0';i++);
		printf("%d\n",search(i-1,0));
	}
	return 0;
}