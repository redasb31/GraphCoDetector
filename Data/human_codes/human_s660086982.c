#include <stdio.h>
#include <inttypes.h>

#define MOD_BY 998244353

int add(int a, int b) {
	return a + b - MOD_BY * (a + b >= MOD_BY);
}

int mul(int a, int b) {
	return (int)(((int64_t)a * b) % MOD_BY);
}

#define KI_MAX (1 << 19) /* 524288 */

int ki[KI_MAX * 2 - 1], ki_mul_all[KI_MAX * 2 - 1], ki_add_all[KI_MAX * 2 - 1];

int ki_get_i_i(int idx, int mult) {
	return add(mul(ki[idx], ki_mul_all[idx]), mul(ki_add_all[idx], mult));
}

void ki_addmul_i(int idx, int qs, int qe, int ss, int se, int mul_value, int add_value) {
	if (qe <= ss || se <= qs) { /* 完全に外れている */
		/* nop */
	} else if (qs <= ss && se <= qe) { /* セグメントがクエリに完全に含まれる */
		ki_mul_all[idx] = mul(ki_mul_all[idx], mul_value);
		ki_add_all[idx] = add(mul(ki_add_all[idx], mul_value), add_value);
	} else {
		int sm = ss + (se - ss) / 2;
		int lidx = idx * 2 + 1, ridx = idx * 2 + 2;
		ki_mul_all[lidx] = mul(ki_mul_all[lidx], ki_mul_all[idx]);
		ki_add_all[lidx] = add(mul(ki_add_all[lidx], ki_mul_all[idx]), ki_add_all[idx]);
		ki_mul_all[ridx] = mul(ki_mul_all[ridx], ki_mul_all[idx]);
		ki_add_all[ridx] = add(mul(ki_add_all[ridx], ki_mul_all[idx]), ki_add_all[idx]);
		ki_mul_all[idx] = 1;
		ki_add_all[idx] = 0;
		ki_addmul_i(lidx, qs, qe, ss, sm, mul_value, add_value);
		ki_addmul_i(ridx, qs, qe, sm, se, mul_value, add_value);
		ki[idx] = add(ki_get_i_i(lidx, sm - ss), ki_get_i_i(ridx, se - sm));
	}
}

void ki_addmul(int qs, int qe, int mul_value, int add_value) {
	if (qs < qe) ki_addmul_i(0, qs, qe, 0, KI_MAX, mul_value, add_value);
}

int ki_get_i(int idx, int qs, int qe, int ss, int se) {
	if (qe <= ss || se <= qs) { /* 完全に外れている */
		return 0;
	} else if (qs <= ss && se <= qe) { /* セグメントがクエリに完全に含まれる */
		return ki_get_i_i(idx, se - ss);
	} else {
		int sm = ss + (se - ss) / 2;
		int left = ki_get_i(idx * 2 + 1, qs, qe, ss, sm);
		int right = ki_get_i(idx * 2 + 2, qs, qe, sm, se);
		int target_left = qs < ss ? ss : qs, target_right = qe < se ? qe : se;
		return add(mul(add(left, right), ki_mul_all[idx]), mul(ki_add_all[idx], target_right - target_left));
	}
}

int ki_get(int qs, int qe) {
	return qs < qe ? ki_get_i(0, qs, qe, 0, KI_MAX) : 0;
}

int main(void) {
	int N, Q;
	int i;
	for (i = 0; i < KI_MAX * 2 - 1; i++) ki_mul_all[i] = 1;
	if (scanf("%d%d", &N, &Q) != 2) return 1;
	for (i = 0; i < N; i++) {
		int a;
		if (scanf("%d", &a) != 1) return 1;
		ki_addmul(i, i + 1, 1, a);
	}
	for (i = 0; i < Q; i++) {
		int type;
		if (scanf("%d", &type) != 1) return 1;
		if (type == 0) {
			int l, r, b, c;
			if (scanf("%d%d%d%d", &l, &r, &b, &c) != 4) return 1;
			ki_addmul(l, r, b, c);
		} else if (type == 1) {
			int l, r;
			if (scanf("%d%d", &l, &r) != 2) return 1;
			printf("%d\n", ki_get(l, r));
		}
	}
	return 0;
}
