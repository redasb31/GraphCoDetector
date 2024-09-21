#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	int score;
} team_t;

int playerComp(team_t x,team_t y) {
	if(x.score>y.score)return 1;
	if(x.score<y.score)return -1;
	if(x.id<y.id)return 1;
	if(x.id>y.id)return -1;
	return 0;
}

typedef struct RedBlackTreeNode_tag {
	team_t key;
	int isRed;
	struct RedBlackTreeNode_tag* left;
	struct RedBlackTreeNode_tag* right;
} RedBlackTreeNode;

RedBlackTreeNode* root=NULL;

#define RBT_REQUEST_NONE			0
#define RBT_REQUEST_INIT			1
#define RBT_REQUEST_NEXTOFLEFT		2
#define RBT_REQUEST_NEXTOFRIGHT		3
#define RBT_REQUEST_ROTATE_LEFT		0x100
#define RBT_REQUEST_ROTATE_RIGHT	0x200

#define RBT_REQUEST_DEL_INIT		1

RedBlackTreeNode* RedBlackTreeNode_new(team_t key) {
	RedBlackTreeNode* ret=malloc(sizeof(RedBlackTreeNode));
	if(ret==NULL)exit(1);
	ret->key=key;
	ret->isRed=1;
	ret->left=ret->right=NULL;
	return ret;
}

void RedBlackTreeNode_delete(RedBlackTreeNode* node) {
	if(node->left)RedBlackTreeNode_delete(node->left);
	if(node->right)RedBlackTreeNode_delete(node->right);
	free(node);
}

void RedBlackTree_rotate(RedBlackTreeNode** target,int isLeft) {
	if(isLeft && (*target)->right!=NULL) {
		RedBlackTreeNode* top=*target;
		RedBlackTreeNode* topRight=(*target)->right;
		RedBlackTreeNode* topRightLeft=(*target)->right->left;
		(*target)->right->left=top;
		(*target)->right=topRightLeft;
		*target=topRight;
	} else if((*target)->left!=NULL) {
		RedBlackTreeNode* top=*target;
		RedBlackTreeNode* topLeft=(*target)->left;
		RedBlackTreeNode* topLeftRight=(*target)->left->right;
		(*target)->left->right=top;
		(*target)->left=topLeftRight;
		*target=topLeft;
	}
}

int RedBlackTree_insertInternal(RedBlackTreeNode** now,team_t key) {
	int ret=RBT_REQUEST_NONE;
	int isLeft;
	if(*now==NULL) {
		*now=RedBlackTreeNode_new(key);
		return RBT_REQUEST_INIT;
	} else if(playerComp((*now)->key,key)==0) {
		return RBT_REQUEST_NONE;
	} else if(playerComp((*now)->key,key)<0) {
		ret=RedBlackTree_insertInternal(&((*now)->right),key);
		isLeft=0;
	} else { /* key<(*now)->key */
		ret=RedBlackTree_insertInternal(&((*now)->left),key);
		isLeft=1;
	}

	if(ret==RBT_REQUEST_INIT) {
		/* case 1 */
		if((*now)->isRed) {
			ret=isLeft?RBT_REQUEST_NEXTOFLEFT:RBT_REQUEST_NEXTOFRIGHT;
		} else {
			ret=RBT_REQUEST_NONE;
		}
	} else if(ret==RBT_REQUEST_NEXTOFLEFT) {
		if(isLeft) {
			if((*now)->right==NULL || !(*now)->right->isRed) {
				/* case 4 */
				(*now)->isRed=1;
				(*now)->left->isRed=0;
				RedBlackTree_rotate(now,0);
				ret=RBT_REQUEST_NONE;
			} else {
				/* case 2 */
				(*now)->left->isRed=0;
				if((*now)->right)(*now)->right->isRed=0;
				(*now)->isRed=1;
				ret=RBT_REQUEST_INIT;
			}
		} else {
			if((*now)->left==NULL || !(*now)->left->isRed) {
				/* case 3 */
				RedBlackTree_rotate(&((*now)->right),0);
				/* case 4 */
				(*now)->isRed=1;
				(*now)->right->isRed=0;
				RedBlackTree_rotate(now,1);
				ret=RBT_REQUEST_NONE;
			} else {
				/* case 2 */
				(*now)->right->isRed=0;
				if((*now)->left)(*now)->left->isRed=0;
				(*now)->isRed=1;
				ret=RBT_REQUEST_INIT;
			}
		}
	} else if(ret==RBT_REQUEST_NEXTOFRIGHT) {
		if(isLeft) {
			if((*now)->right==NULL || !(*now)->right->isRed) {
				/* case 3 */
				RedBlackTree_rotate(&((*now)->left),1);
				/* case 4 */
				(*now)->isRed=1;
				(*now)->left->isRed=0;
				RedBlackTree_rotate(now,0);
				ret=RBT_REQUEST_NONE;
			} else {
				/* case 2 */
				(*now)->left->isRed=0;
				if((*now)->right)(*now)->right->isRed=0;
				(*now)->isRed=1;
				ret=RBT_REQUEST_INIT;
			}
		} else {
			if((*now)->left==NULL || !(*now)->left->isRed) {
				/* case 4 */
				(*now)->isRed=1;
				(*now)->right->isRed=0;
				RedBlackTree_rotate(now,1);
				ret=RBT_REQUEST_NONE;
			} else {
				/* case 2 */
				(*now)->right->isRed=0;
				if((*now)->left)(*now)->left->isRed=0;
				(*now)->isRed=1;
				ret=RBT_REQUEST_INIT;
			}
		}
	}
	return ret;
}

void RedBlackTree_insert(team_t key) {
	RedBlackTree_insertInternal(&root,key);
	root->isRed=0;
}

RedBlackTreeNode* RedBlackTree_searchPtr(RedBlackTreeNode* now,team_t key) {
	if(now==NULL)return NULL;
	if(playerComp(now->key,key)==0)return now;
	return RedBlackTree_searchPtr(playerComp(now->key,key)<0?now->right:now->left,key);
}

RedBlackTreeNode* RedBlackTree_searchMinNode(RedBlackTreeNode* now) {
	if(now->left==NULL)return now;
	return RedBlackTree_searchMinNode(now->left);
}

RedBlackTreeNode* RedBlackTree_searchMaxNode(RedBlackTreeNode* now) {
	if(now->right==NULL)return now;
	return RedBlackTree_searchMaxNode(now->right);
}

int RedBlackTree_removeInternal(RedBlackTreeNode** now,RedBlackTreeNode* target) {
	int ret=RBT_REQUEST_NONE;
	int isLeft=0;
	int colorTemp;
	if(*now==NULL)return RBT_REQUEST_NONE;
	if(*now==target) {
		RedBlackTreeNode* delNode=*now;
		int delNodeIsRed=delNode->isRed;
		*now=(*now)->left?(*now)->left:(*now)->right;
		delNode->left=delNode->right=NULL;
		RedBlackTreeNode_delete(delNode);
		/* case 0 */
		if(delNodeIsRed) {
			return RBT_REQUEST_NONE;
		} else if(*now && (*now)->isRed) {
			(*now)->isRed=0;
			return RBT_REQUEST_NONE;
		}
		return RBT_REQUEST_DEL_INIT;
	} else if(playerComp((*now)->key,target->key)<=0) {
		ret=RedBlackTree_removeInternal(&((*now)->right),target);
		isLeft=0;
	} else {
		ret=RedBlackTree_removeInternal(&((*now)->left),target);
		isLeft=1;
	}
	if(ret==RBT_REQUEST_DEL_INIT) {
		if(isLeft) {
			if((*now)->right!=NULL && (*now)->right->isRed) {
				/* case 2 */
				(*now)->isRed=!(*now)->isRed;
				(*now)->right->isRed=!(*now)->right->isRed;
				RedBlackTree_rotate(now,1);
				now=&((*now)->left);
			}
			ret=RBT_REQUEST_NONE;
			if((*now)->right!=NULL) {
				if(((*now)->right->left==NULL ||
						!((*now)->right->left->isRed)) &&
						((*now)->right->right==NULL ||
						!((*now)->right->right->isRed))) {
					if((*now)->isRed) {
						/* case 4 */
						(*now)->isRed=0;
						(*now)->right->isRed=1;
					} else {
						/* case 3 */
						(*now)->right->isRed=1;
						ret=RBT_REQUEST_INIT;
					}
				} else if((*now)->right->right!=NULL &&
						(*now)->right->right->isRed) {
					/* case 6 */
					colorTemp=(*now)->isRed;
					(*now)->isRed=(*now)->right->isRed;
					(*now)->right->isRed=colorTemp;
					(*now)->right->right->isRed=0;
					RedBlackTree_rotate(now,1); 
				} else {
					/* case 5 */
					(*now)->right->isRed=1; 
					(*now)->right->left->isRed=0;
					RedBlackTree_rotate(&((*now)->right),0);
					/* case 6 */
					colorTemp=(*now)->isRed;
					(*now)->isRed=(*now)->right->isRed;
					(*now)->right->isRed=colorTemp;
					(*now)->right->right->isRed=0;
					RedBlackTree_rotate(now,1); 
				}
			}
		} else {
			if((*now)->left!=NULL && (*now)->left->isRed) {
				/* case 2 */
				(*now)->isRed=!(*now)->isRed;
				(*now)->left->isRed=!(*now)->left->isRed;
				RedBlackTree_rotate(now,0);
				now=&((*now)->right);
			}
			ret=RBT_REQUEST_NONE;
			if((*now)->left!=NULL) {
				if(((*now)->left->left==NULL ||
						!((*now)->left->left->isRed)) &&
						((*now)->left->right==NULL ||
						!((*now)->left->right->isRed))) {
					if((*now)->isRed) {
						/* case 4 */
						(*now)->isRed=0;
						(*now)->left->isRed=1;
					} else {
						/* case 3 */
						(*now)->left->isRed=1;
						ret=RBT_REQUEST_INIT;
					}
				} else if((*now)->left->left!=NULL &&
						(*now)->left->left->isRed) {
					/* case 6 */
					colorTemp=(*now)->isRed;
					(*now)->isRed=(*now)->left->isRed;
					(*now)->left->isRed=colorTemp;
					(*now)->left->left->isRed=0;
					RedBlackTree_rotate(now,0);
				} else {
					/* case 5 */
					(*now)->left->isRed=1; 
					(*now)->left->right->isRed=0;
					RedBlackTree_rotate(&((*now)->left),1);
					/* case 6 */
					colorTemp=(*now)->isRed;
					(*now)->isRed=(*now)->left->isRed;
					(*now)->left->isRed=colorTemp;
					(*now)->left->left->isRed=0;
					RedBlackTree_rotate(now,0); 
				}
			}
		}
	}
	return ret;
}

int RedBlackTree_remove(team_t key) {
	RedBlackTreeNode* target;
	target=RedBlackTree_searchPtr(root,key);
	if(target==NULL)return 0;
	if(target->left!=NULL && target->right!=NULL) {
		RedBlackTreeNode* minNode;
		minNode=RedBlackTree_searchMinNode(target->right);
		target->key=minNode->key;
		target=minNode;
	}
	RedBlackTree_removeInternal(&root,target);
	return 1;
}

team_t RedBlackTree_getMax(void) {
	team_t nothing={1,0};
	RedBlackTreeNode* max=RedBlackTree_searchMaxNode(root);
	return max==NULL?nothing:max->key;
}

int teamScore[100001];
int teamShownTime[100001];

int main(void) {
	int N,R,L;
	int i;
	int prevTime=0;
	int resID,resTime;
	team_t tempTeam={1,0};
	scanf("%d%d%d",&N,&R,&L);
	RedBlackTree_insert(tempTeam);
	for(i=0;i<R;i++) {
		int d,t,x;
		scanf("%d%d%d",&d,&t,&x);
		tempTeam=RedBlackTree_getMax();
		teamShownTime[tempTeam.id]+=t-prevTime;
		tempTeam.id=d;
		tempTeam.score=teamScore[d];
		RedBlackTree_remove(tempTeam);
		teamScore[d]+=x;
		tempTeam.score=teamScore[d];
		RedBlackTree_insert(tempTeam);
		prevTime=t;
	}
	tempTeam=RedBlackTree_getMax();
	teamShownTime[tempTeam.id]+=L-prevTime;
	resID=0;resTime=-1;
	for(i=1;i<=N;i++) {
		if(teamShownTime[i]>resTime) {
			resTime=teamShownTime[i];
			resID=i;
		}
	}
	printf("%d\n",resID);
	return 0;
}