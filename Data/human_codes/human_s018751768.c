#include <stdio.h>
#include <string.h>

#define TREE_MAX 100010

typedef struct {
	int key;
	int isred;
	int parent;
	int left;
	int right;
} rbt_node_t;

int rbt_node_used;
rbt_node_t rbt_node[TREE_MAX+1];

void rbt_init(void) {
	rbt_node_used=1;
	memset(rbt_node,0,sizeof(rbt_node));
	rbt_node[0].key=-0x7fffffff;
}

int rbt_search(int searchfor) {
	int pos=rbt_node[0].right;
	while(pos>0) {
		if(rbt_node[pos].key==searchfor) {
			return 1;
		} else if(rbt_node[pos].key<searchfor) {
			pos=rbt_node[pos].right;
		} else {
			pos=rbt_node[pos].left;
		}
	}
	return 0;
}

int rbt_insert(int key) {
	int pos=0;
	int parent,p_parent,p_left,p_right;
	int pp_parent,pp_left,pp_right;
	while(1) {
		if(rbt_node[pos].key==key) {
			return 0;
		} else if(rbt_node[pos].key<key) {
			if(rbt_node[pos].right==0)break;
			pos=rbt_node[pos].right;
		} else {
			if(rbt_node[pos].left==0)break;
			pos=rbt_node[pos].left;
		}
	}
	if(rbt_node_used>TREE_MAX)return 0;
	rbt_node[rbt_node_used].key=key;
	rbt_node[rbt_node_used].isred=1;
	rbt_node[rbt_node_used].parent=pos;
	rbt_node[rbt_node_used].left=0;
	rbt_node[rbt_node_used].right=0;
	if(rbt_node[pos].key<key) {
		rbt_node[pos].right=rbt_node_used;
	} else {
		rbt_node[pos].left=rbt_node_used;
	}
	pos=rbt_node_used;
	rbt_node_used++;

	while(pos>0) {
		if(rbt_node[pos].parent==0) {
			rbt_node[pos].isred=0;
			break;
		}
		parent=rbt_node[pos].parent;
		p_parent=rbt_node[parent].parent;
		p_left=rbt_node[parent].left;
		p_right=rbt_node[parent].right;
		if(!rbt_node[parent].isred) {
			break;
		}
		pp_parent=rbt_node[p_parent].parent;
		pp_left=rbt_node[p_parent].left;
		pp_right=rbt_node[p_parent].right;
		if(rbt_node[pp_left].isred && rbt_node[pp_right].isred) {
			rbt_node[pp_left].isred=0;
			rbt_node[pp_right].isred=0;
			rbt_node[p_parent].isred=1;
			pos=p_parent;
		} else {
			if(pos==p_right && parent==pp_left) {
				if(rbt_node[pos].left>0) {
					rbt_node[rbt_node[pos].left].parent=parent;
				}
				rbt_node[parent].right=rbt_node[pos].left;
				rbt_node[parent].parent=pos;
				rbt_node[pos].left=parent;
				rbt_node[pos].parent=p_parent;
				rbt_node[p_parent].left=pos;
				pos=parent;
			} else if(pos==p_left && parent==pp_right) {
				if(rbt_node[pos].right>0) {
					rbt_node[rbt_node[pos].right].parent=parent;
				}
				rbt_node[parent].left=rbt_node[pos].right;
				rbt_node[parent].parent=pos;
				rbt_node[pos].right=parent;
				rbt_node[pos].parent=p_parent;
				rbt_node[p_parent].right=pos;
				pos=parent;
			} else if(pos==p_left && parent==pp_left) {
				if(rbt_node[pp_parent].left==p_parent) {
					rbt_node[pp_parent].left=parent;
				} else if(rbt_node[pp_parent].right==p_parent) {
					rbt_node[pp_parent].right=parent;
				} else {
					/* error!bug! */
					return 0;
				}
				if(rbt_node[parent].right>0) {
					rbt_node[rbt_node[parent].right].parent=p_parent;
				}
				rbt_node[p_parent].left=rbt_node[parent].right;
				rbt_node[p_parent].parent=parent;
				rbt_node[parent].right=p_parent;
				rbt_node[parent].parent=pp_parent;
				rbt_node[p_parent].isred=1;
				rbt_node[parent].isred=0;
				break;
			} else if(pos==p_right && parent==pp_right) {
				if(rbt_node[pp_parent].left==p_parent) {
					rbt_node[pp_parent].left=parent;
				} else if(rbt_node[pp_parent].right==p_parent) {
					rbt_node[pp_parent].right=parent;
				} else {
					/* error!bug! */
					return 0;
				}
				if(rbt_node[parent].left>0) {
					rbt_node[rbt_node[parent].left].parent=p_parent;
				}
				rbt_node[p_parent].right=rbt_node[parent].left;
				rbt_node[p_parent].parent=parent;
				rbt_node[parent].left=p_parent;
				rbt_node[parent].parent=pp_parent;
				rbt_node[p_parent].isred=1;
				rbt_node[parent].isred=0;
				break;
			} else {
				/* error!bug! */
				return 0;
			}
		}
	}
	rbt_node[0].parent=0;
	rbt_node[0].left=0;
	rbt_node[0].isred=0;
	return 1;
}

int N,M;
int input[100000];

int main(void) {
	int count;
	int i;
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++)scanf("%d",&input[i]);
	count=0;
	rbt_init();
	for(i=N-1;i>=0 && count<M;i--) {
		if(!rbt_search(input[i])) {
			count++;
			rbt_insert(input[i]);
			printf("%d\n",input[i]);
		}
	}
	return 0;
}