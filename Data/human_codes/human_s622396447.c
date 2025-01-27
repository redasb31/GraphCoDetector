# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int key;
	struct node *p_left;
	struct node *p_right;
	struct node *p_parent;
}NODE;

NODE *insert(int value, NODE *p_root);	/* ?????\ */
void inorderTreeWalk(NODE *p_node);	/* ??????????????? */
void preorderTreeWalk(NODE *p_node); /* ??????????????? */
int find(int value, NODE *p_root);	/* ??¢?´¢ */
void delete(int value, NODE *p_root);	/* ?????? */
void deleteHasNoChildNode(NODE *z);	/* ?????????????????????????????????????????? */
void deleteHasOneChildNode(NODE *z); /* ?????????????????????????????????????????? */
void deleteHasTwoChildlenNode(NODE *z);	/* ?????????????????????????????????????????? */

int main(void) {

	char command[7];
	int value, n, i;
	int result_find;
	NODE *p_root = NULL;

	scanf("%d", &n);/* ????????°?????\??? */

	for (i = 0; i < n; i++) {
		scanf("%s", &command);
		/* insert?????? */
		if (command[0] == 'i') {
			scanf("%d", &value);
			p_root = insert(value, p_root);
		}
		/* print?????? */
		else if (command[0] == 'p') {
			inorderTreeWalk(p_root);
			printf("\n");
			preorderTreeWalk(p_root);
			printf("\n");
		}
		/* find?????? */
		else if (command[0] == 'f') {
			scanf("%d", &value);
			result_find = find(value, p_root);
			result_find ? printf("yes\n") : printf("no\n");
		}
		/* delete?????? */
		else if (command[0] == 'd') {
			scanf("%d", &value);
			delete(value, p_root);
		}
	}
	return 0;
}

/* ?????\?????? */
NODE* insert(int value, NODE *p_root) {
	NODE *x = p_root;	/* ??? */
	NODE *y = NULL;	/* x?????? */

	NODE *z = (NODE *)malloc(sizeof(NODE));
	z->key = value;
	z->p_left = NULL;
	z->p_right = NULL;

	while (x != NULL) {
		y = x;
		if (x->key > z->key) {
			x = x->p_left;		/* ?????????????§???? */
		}
		else {
			x = x->p_right;	/* ?????????????§???? */
		}
	}
	z->p_parent = y;

	if (y == NULL) {	/* ??¨???????????´??? */
		p_root = z;
	}
	else if (z->key < y->key) {
		y->p_left = z;	//z?????????????????????
	}
	else {
		y->p_right = z;	//z?????????????????????
	}
	return p_root;
}

//?????????????????§??¨???
void inorderTreeWalk(NODE *p_node) {

	if (p_node == NULL) {
		return;
	}
	inorderTreeWalk(p_node->p_left);
	printf(" %d", p_node->key);
	inorderTreeWalk(p_node->p_right);
}

//?????????????????§??¨???
void preorderTreeWalk(NODE *p_node) {

	if (p_node == NULL) {
		return;
	}
	printf(" %d", p_node->key);
	preorderTreeWalk(p_node->p_left);
	preorderTreeWalk(p_node->p_right);
}

/* ??????????????????value????????¨????????????????????±????????? */
/* ????????????0 : ?????¨?????????, 1 : ?????¨?????? */
int find(int value, NODE *p_root) {
	
	NODE *z;
	z = p_root;

	while (z->key != value) {
		if (z->key > value) {
			if (z->p_left != NULL) {
				z = z->p_left; /* ?????????????§???? */
			}
			else {
				return 0;
			}
		}
		else if (z->key < value) {
			if (z->p_right != NULL) {
				z = z->p_right; /* ?????????????§???? */
			}
			else {
				return 0;
			}
		}
	}
	return 1;
}
/* value????????????????????????????????????????????? */
void delete(int value, NODE *p_root) {
	NODE *z;
	z = p_root;

	/* ?????????????????????????????¢??? */
	while (1) {
		if (z->key > value) {
			z = z->p_left; /* ?????????????§???? */
		}
		else if (z->key < value) {
			z = z->p_right; /* ?????????????§???? */
		}
		else {
			break;
		}
	}

	/* ??????????±????????????????????????????????????¨??? */
	if (z->p_left == NULL && z->p_right == NULL) {
		deleteHasNoChildNode(z);
	}
	/* ??????????±??????????????????????????????????????????¨??? */
	else if (z->p_right == NULL || z->p_left == NULL) {
		
		deleteHasOneChildNode(z);
	}
	/* ??????????±????????????????????????????????????¨??? */
	else {
		deleteHasTwoChildlenNode(z);
	}
}

/* ?????????????????????????????????????????? */
void deleteHasNoChildNode(NODE *z) {
	if (z->p_parent != NULL) {
		if (z->key >= z->p_parent->key) {
			z->p_parent->p_right = NULL;
		}
		else {
			z->p_parent->p_left = NULL;
		}
	}
	free(z);
}

/* ?????????????????????????????????????????? */
void deleteHasOneChildNode(NODE *z) {

	/* ????????????????????¨??? */
	if (z->p_left != NULL) {
		if (z->key > z->p_parent->key) {
			z->p_parent->p_right = z->p_left;
		}
		else {
			z->p_parent->p_left = z->p_left;
		}
		z->p_left->p_parent = z->p_parent;
	}
	/* ????????????????????¨??? */
	else{
		if (z->key > z->p_parent->key) {
			z->p_parent->p_right = z->p_right;
		}
		else {
			z->p_parent->p_left = z->p_right;
		}
		z->p_right->p_parent = z->p_parent;
	}
	free(z);
}

/* ?????????????????????????????????????????? */
void deleteHasTwoChildlenNode(NODE *z) {

	NODE *y; /* z????¬??????? */

	y = z->p_right;
	while (y->p_left != NULL) {
		y = y->p_left;
	}

	/* y????????????z????????????????????? */
	z->key = y->key;

	/* y????????? */
	if (y->p_left == NULL && y->p_right == NULL) {
		deleteHasNoChildNode(y);
	}
	else{
		deleteHasOneChildNode(y);
	}
}