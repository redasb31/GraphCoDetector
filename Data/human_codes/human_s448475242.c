#include<stdio.h>
int N;
long data[] = {[0 ... 1<<19] 0};
void fen_add(int p, long x){
	p++;
	while(p <= N){
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

int Q;
int main(){
	scanf("%d%d", &N, &Q);
	for(int i=0; i<N; i++){
		int a;
		scanf("%d", &a);
		fen_add(i, a);
	}
	while(Q--){
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if(t) printf("%ld\n", fen_range(x, y));
		else fen_add(x, y);
	}
	return 0;
}