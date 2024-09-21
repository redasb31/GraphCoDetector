#include <stdio.h>

unsigned xor128() {
	static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}

typedef struct node_t {
	int val;
	struct node_t *lch, *rch;
	int size;
	unsigned int pri;
} node;

node* new_node(int val) {
	static int it = 0;
	static node pool[200000];
	pool[it] = (node) { val, 0, 0, 1, xor128() };
	return &pool[it++];
}

int count(node *t) {
	return !t ? 0 : t->size;
}

node *update(node *t) {
	t->size = count(t->lch) + count(t->rch) + 1;
	return t;
}

node *merge(node *l, node *r) {
	if (!l || !r) return !l ? r : l;
	if (l->pri > r->pri) {
		l->rch = merge(l->rch, r);
		return update(l);
	}
	r->lch = merge(l, r->lch);
	return update(r);
}

typedef struct{ node *a, *b; } pnode;

pnode split(node *t, int k) {
	if (!t) return (pnode) { 0, 0 };
	if (k <= count(t->lch)) {
		pnode s = split(t->lch, k);
		t->lch = s.b;
		return (pnode) { s.a, update(t) };
	}
	pnode s = split(t->rch, k - count(t->lch) - 1);
	t->rch = s.a;
	return (pnode) { update(t), s.b };
}

node* find(node *t, int val) {
	while (t) {
		if (t->val == val) break;
		t = val < t->val ? t->lch : t->rch;
	}
	return t;
}

int count_lower(node *t, int v) {
	if (!t) return 0;
	if (t->val < v) return count(t->lch) + 1 + count_lower(t->rch, v);
	if (t->val == v) return count(t->lch);
	return count_lower(t->lch, v);
}

node *insert(node *t, int val) {
	int k = count_lower(t, val);
	pnode s = split(t, k);
	return merge(merge(s.a, new_node(val)), s.b);
}

node *erase(node *t, int k) {
	pnode s1 = split(t, k), s2 = split(s1.b, 1);
	return merge(s1.a, s2.b);
}

int main(void)
{
	int q, com, x, cnt = 0;
	node *root = 0;
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &com, &x);
		if (com == 0) {
			if (!find(root, x)) ++cnt, root = insert(root, x);
			printf("%d\n", cnt);
		}
		else if (com == 1) {
			puts(find(root, x) ? "1" : "0");
		}
		else {
			root = erase(root, count_lower(root, x));
			--cnt;
		}
	}
	return 0;
}

