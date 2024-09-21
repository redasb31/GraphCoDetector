#include <stdio.h>
#include <inttypes.h>

int N, P;
char S[271828];

int count[12345];

int add(int a, int b) {
	int r = (a % P) + (b % P);
	if (r >= P) r -= P;
	return r;
}

int sub(int a, int b) {
	int bb = b % P;
	return bb == 0 ? a % P : add(a, P - bb);
}

int mul(int a, int b) {
	return ((a % P) * (b % P)) % P;
}

int pou(int a, int b) {
	int r = 1;
	while (b > 0) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}

int inv(int a) {
	return pou(a, P - 2);
}

int dexibu(int a, int b) {
	return mul(a, inv(b));
}

int main(void) {
	int i;
	int asumi = 1, iguti = 0;
	int64_t mizuhasu = 0;
	if (scanf("%d%d", &N, &P) != 2) return 1;
	if (scanf("%271827s", S) != 1) return 1;
	if (P == 2) {
		for (i = 0; i < N; i++) {
			int x = S[i] - '0';
			if (0 <= x && x < 10 && x % 2 == 0) mizuhasu += i + 1;
		}
	} else if (P == 5) {
		for (i = 0; i < N; i++) {
			int x = S[i] - '0';
			if (0 <= x && x < 10 && x % 5 == 0) mizuhasu += i + 1;
		}
	} else {
		count[0] = 1;
		for (i = 0; i < N; i++) {
			int ogura;
			if (S[i] < '0' || '9' < S[i]) continue;
			asumi = mul(asumi, 10);
			iguti = add(mul(iguti, 10), S[i] - '0');
			ogura = dexibu(sub(0, iguti), asumi);
			mizuhasu += count[ogura]++;
		}
	}
	printf("%" PRId64 "\n", mizuhasu);
	return 0;
}

/*

P = 7

  0 1 2

0 0 1 5
1 3 3 4
2 6 5 3
3 2 0 2
4 5 2 1
5 1 4 0
6 4 6 6

(x*10+0)=k1 x=(k1-0)/10
((x*10+0)*10+1)=k2 x=((k2-1)/10)-0)/10
	x*100+(0*10+1)=k2
(((x*10+0)*10+1)*10+2)=k3
	x*1000+(0*100+1*10+2)=k3

各桁ごとにそれぞれの状態(Pで割った余り)の数を数えておいて0になった数をカウントし、
さらに0の状態の数に1を加えたい。
ただし、それぞれの状態の数を毎回コピーしていたら遅い。
コピーの代わりにどこに格納しているかを管理し、
さらに0がどこにあるかだけを管理すればいい。
どうやって？ → 位置の決まり方を考えると、最初の状態をxとし、
xの項と定数項に分けておけば、x*(10**n)+k=0の形になり、
これはすぐ解けるはずである。

*/
