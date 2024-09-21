#include <stdio.h>
#include <stdlib.h>

#define EMPTY    0
#define NOTEMPTY 1
#define Q 10007

typedef struct node{
	int n;
	struct node *next;
}node;

typedef struct hashnode{
	int a;
	int b;
	int n;
	struct hashnode *next;
}hnode;

int empty(node *q);
int dequeue(node *q);
void enqueue(node *q, int n);
void check_connect(char *g, int *r, const int n, const int t);
int hash(int, int);
void counting(int, int, hnode *);
int hash_search(int, int, hnode *);

hnode *hashtable;
	
int main(void){
	int n, k, l;
	int p, q;
	int i, j;
	int *ar, *br, ans;
	char *graph;

	scanf("%d %d %d", &n, &k, &l);
	graph = (char *)malloc(sizeof(char)*(n*n));
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			graph[i*n+j] = 0;
		}
	}
	ar = (int *)malloc(sizeof(int)*n);
	br = (int *)malloc(sizeof(int)*n);
	for(i=0; i<n; i++){
		ar[i] = -1;
		br[i] = -1;
	}
	for(i=0; i<k; i++){
		scanf("%d %d", &p, &q);
		graph[(p-1)*n+(q-1)] = 1;
		//printf("conncted %d and %d with path.\n", p ,q);
	}
	//printf("checking connect with path\n");
	check_connect(graph, ar, n, 1);
	
	for(i=0; i<l; i++){
		scanf("%d %d", &p, &q);
		graph[(p-1)*n+(q-1)] += 2;
		//printf("connected %d and %d with train.\n", p, q);
	}
	
	hashtable = (hnode *)malloc(sizeof(hnode)*Q);
	for(i=0; i<Q; i++){
		(hashtable+i)->next = NULL;
		(hashtable+i)->a = -1;
		(hashtable+i)->b = -1;
	}
	
	//printf("checking connect with train\n");
	check_connect(graph, br, n, 2);

	//printf("start counting\n");
	for(i=0; i<n; i++){
		counting(ar[i], br[i], hashtable);
	}
	//printf("start print result\n");
	for(i=0; i<n; i++){
		ans = hash_search(ar[i], br[i], hashtable);
		printf("%d ", ans);
	}
	printf("\n");
	
	return 0;
}

int hash_search(int a, int b, hnode *ht){
	int h;
	hnode *p;

	h = hash(a, b);
	p = ht+h;
	while(p->next != NULL){
		if(p->a == a && p->b == b) return p->n;
		p = p->next;
	}
	if(p->a == a && p->b == b) return p->n;

	return -1;
}

void counting(int a, int b, hnode *ht){
	int h;
	hnode *p, *new;

	h = hash(a, b);
	p = ht + h;
	while(p->next != NULL){
		if(p->a == a && p->b == b){
			p->n++;
		}
		p = p->next;
	}
	if(p->a == a && p->b == b){
			p->n++;
	}else{
		new = (hnode *)malloc(sizeof(hnode));
		new->a = a;
		new->b = b;
		new->n = 1;
		new->next = NULL;
		p->next = new;
	}
	
}

int hash(int a, int b){
	int h;

	h = (a*a+b)%Q;
	//printf("%d %d %d\n", a, b, h);

	return h;
}




int empty(node *q){
	if(q->next == NULL) return EMPTY;

	return NOTEMPTY;
}

node* init_queue(){
	node *np;

	np = (node *)malloc(sizeof(node));
	np->next = NULL;

	return np;
}

int dequeue(node *q){
	node *np;
	int n;

	if(empty(q) == EMPTY) return 0;
	np = q->next;
	q->next = q->next->next;
	n = np->n;
	free(np);
	
	return n;
}

void enqueue(node *q, int n){
	node *np;
	
	np = (node*)malloc(sizeof(node));
	np->n = n;
	np->next = NULL;
	while(q->next != NULL) q = q->next;
	q->next = np;
}

void check_connect(char *g, int *r, const int n, const int t){
	int cnum;
	node *set;
	int i, j;

	
	set = init_queue();
	
	for(i=0; i<n; i++){
		if(r[i] != -1)continue;
		enqueue(set, i);
		r[i] = i;
		while(empty(set) != EMPTY){
			cnum=dequeue(set);
			//printf("checking connection with %d.\n", cnum);
			for(j=cnum+1; j<n; j++){
				if(g[cnum*n+j] >= t){
					if(r[j] == -1){
						enqueue(set, j);
						r[j] = i;
						//printf("%d is connected.\n", j);
					}
				}
			}
		}
	}
}