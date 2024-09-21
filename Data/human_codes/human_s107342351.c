#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

//fast(?) Input
#define buf_sz 1<<24
char buf[buf_sz];
unsigned int nextint(){
	static int idx = 0;
	if(idx == 0)read(0, buf, buf_sz);
	unsigned int res = 0;
	while(idx<buf_sz && buf[idx]<'0' || '9'<buf[idx])idx++;
	while(idx<buf_sz && '0'<=buf[idx] && buf[idx]<='9'){
		res *= 10;
		res += buf[idx++] - '0';
	}if(idx>=buf_sz)exit(1);
	return res;
}

long data[1<<19];
void fen_add(int p, long x, int N){
	p++;
	while(p<=N){
		data[p-1] += x;
		p += p & -p;
	}
}
long fen_sum(int r){
	long s = 0;
	while(r > 0){
		s += data[r-1];
		r -= r & -r;
	}
	return s;
}
long fen_range(int l, int r){
	return fen_sum(r) - fen_sum(l);
}

int main(){
	int N = nextint(), Q = nextint();
	for(int i=0; i<N; i++)fen_add(i, nextint(), N);
	while(Q--){
		if(nextint() == 1)printf("%ld\n", fen_range(nextint(), nextint()));
		else fen_add(nextint(), nextint(), N);
	}
	return 0;
}