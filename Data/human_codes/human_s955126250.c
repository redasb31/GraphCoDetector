#include <stdio.h>
#include <malloc.h>

#define MAX_K 40000
#define MAX_N 40000
#define MAX (1<<16)
#define count(x) (x ? x->size : 0)

unsigned xor128() {
	static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}

typedef struct rb {
	int size;
	int keya, keyb;
	int val;
	struct rb *left, *right;
} map, *pmap;

typedef struct pa {
	pmap first, second;
} pmappair;

pmap new_map(int keya, int keyb, int val) {
	pmap res = malloc(sizeof(map));
	res->size = 1;
	res->keya = keya;
	res->keyb = keyb;
	res->val = val;
	res->left = res->right = 0;
	return res;
}

pmap update(pmap x) {
	x->size = count(x->left) + 1 + count(x->right);
	return x;
}

pmap merge(pmap l, pmap r) {
	if (!l) return r;
	if (!r) return l;
	if (xor128() % (l->size + r->size) < l->size) {
		l->right = merge(l->right, r);
		return update(l);
	}
	else {
		r->left = merge(l, r->left);
		return update(r);
	}
}

pmappair split(pmap x, int k) {
	pmappair res;
	if (!x) {
		res.first = res.second = 0;
		return res;
	}
	if (k == 0) {
		res.first = 0;
		res.second = x;
		return res;
	}
	if (k == x->size) {
		res.first = x;
		res.second = 0;
		return res;
	}
	if (k <= count(x->left)) {
		res = split(x->left, k);
		x->left = res.second;
		res.second = update(x);
	}
	else {
		res = split(x->right, k - count(x->left) - 1);
		x->right = res.first;
		res.first = update(x);
	}
	return res;
}

int count_lower(pmap x, int keya, int keyb) {
	int res = 0;
	while (x) {
		if (keya < x->keya || (keya == x->keya && keyb <= x->keyb)) {
			x = x->left;
		}
		else {
			res += count(x->left) + 1;
			x = x->right;
		}
	}
	return res;
}

pmap insert_map(pmap x, int keya, int keyb, int val) {
	int pos = count_lower(x, keya, keyb);
	pmappair s = split(x, pos);
	return merge(merge(s.first, new_map(keya, keyb, val)), s.second);
}

pmap erase_map(pmap x, int k) {
	pmappair s1 = split(x, k), s2 = split(s1.second, 1);
	return merge(s1.first, s2.second);
}

pmap get_map(pmap x, int keya, int keyb) {
	while (x) {
		if (x->keya == keya && x->keyb == keyb) return x;
		if (keya < x->keya || (keya == x->keya && keyb < x->keyb)) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	return x;
}

typedef struct vec {
	int val;
	struct vec *next;
} vector, *pvec;

pvec new_vec(int val) {
	pvec res = malloc(sizeof(vector));
	res->val = val;
	res->next = 0;
	return res;
}

typedef struct lis {
	int val;
	struct lis *next, *prev;
} list, *plis;

plis new_lis(int val) {
	plis res = malloc(sizeof(list));
	res->val = val;
	res->next = res->prev = 0;
	return res;
}

int qu[MAX_K], qv[MAX_K];
pvec insuf[MAX * 2], insub[MAX * 2], insvf[MAX * 2], insvb[MAX * 2];
int inssiz[MAX * 2];
pvec resf, resb;

int n, k;

int uf[MAX_N];

plis posf, posb;
plis pref, preb;
int psize;
plis verf, verb;

void push_pp(int pos) {
	if (!posf) {
		posf = posb = new_lis(pos);
		pref = preb = new_lis(uf[pos]);
	}
	else {
		posb->next = new_lis(pos);
		posb->next->prev = posb;
		posb = posb->next;
		preb->next = new_lis(uf[pos]);
		preb->next->prev = preb;
		preb = preb->next;
	}
	psize++;
}

void undo() {
	while (psize > verb->val) {
		if (preb != pref) {
			uf[posb->val] = preb->val;
			posb = posb->prev;
			posb->next = 0;
			preb = preb->prev;
			preb->next = 0;
		}
		else {
			preb = pref = posb = posf = 0;
		}
		psize--;
	}
	if (verf != verb) {
		verb = verb->prev;
		verb->next = 0;
	}
	else {
		verf = verb = 0;
	}
}

int find(int x) {
	return uf[x] >= 0 ? find(uf[x]) : x;
}

void unite(int u, int v) {
	if (!verf) {
		verf = verb = new_lis(psize);
	}
	else {
		verb->next = new_lis(psize);
		verb->next->prev = verb;
		verb = verb->next;
	}
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (-uf[u] < -uf[v]) {
		push_pp(v);
		push_pp(u);
		uf[v] += uf[u];
		uf[u] = v;
	}
	else {
		push_pp(u);
		push_pp(v);
		uf[u] += uf[v];
		uf[v] = u;
	}
}

int same(int u, int v) {
	return find(u) == find(v);
}

void dfs(int p) {
	pvec t1, t2;
	for (t1 = insuf[p], t2 = insvf[p]; t1 && t2; t1 = t1->next, t2 = t2->next) {
		unite(t1->val, t2->val);
	}
	if (p >= MAX) {
		if (p - MAX < k && qu[p - MAX] != -1) {
			int res = same(qu[p - MAX], qv[p - MAX]);
			if (!resf) {
				resf = resb = new_vec(res);
			}
			else {
				resb = resb->next = new_vec(res);
			}
		}
	}
	else {
		dfs(p * 2);
		dfs(p * 2 + 1);
	}
	int i;
	for (i = 0; i < inssiz[p]; i++) {
		undo();
	}
}

void add(int l, int r, int u, int v, int p, int lb, int ub) {
	if (ub <= l || r <= lb) return;
	if (l <= lb && ub <= r) {
		if (!insub[p]) {
			insuf[p] = insub[p] = new_vec(u);
			insvf[p] = insvb[p] = new_vec(v);
		}
		else {
			insub[p] = insub[p]->next = new_vec(u);
			insvb[p] = insvb[p]->next = new_vec(v);
		}
		inssiz[p]++;
		return;
	}
	int c = (lb + ub) / 2;
	add(l, r, u, v, p * 2, lb, c);
	add(l, r, u, v, p * 2 + 1, c, ub);
}

void sweap_map(pmap x) {
	if (!x) return;
	sweap_map(x->left);
	add(x->val, k, x->keya, x->keyb, 1, 0, MAX);
	sweap_map(x->right);
}

int main(void)
{
	int i, t, u, v, tmp;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++) {
		uf[i] = -1;
	}
	for (i = 0; i < k; i++) {
		qu[i] = -1;
	}
	pmap dic = 0;
	for (i = 0; i < k; i++) {
		scanf("%d%d%d", &t, &u, &v);
		if (t == 1) {
			dic = insert_map(dic, u, v, i);
		}
		else if (t == 2) {
			tmp = get_map(dic, u, v)->val;
			dic = erase_map(dic, count_lower(dic, u, v));
			add(tmp, i, u, v, 1, 0, MAX);
		}
		else {
			qu[i] = u;
			qv[i] = v;
		}
	}
	sweap_map(dic);
	dfs(1);
	pvec p;
	for (p = resf; p; p = p->next) {
		puts(p->val ? "YES" : "NO");
	}
	return 0;
}

