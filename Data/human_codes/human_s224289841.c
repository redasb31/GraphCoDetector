#include <stdio.h>
#include <stdlib.h>

#define ERROR_WRONG_SET_NAME		1
#define ERROR_INVALID_EXPRESSION	0
#define ERROR_INVALID_STACK			3
#define ERROR_INVALID_CALCULATION	4
#define ERROR_INVALID_RESULT		5
#define ERROR_LIMIT_EXCEEDED		6	

enum {
	TYPE_SET,
	TYPE_UNION,
	TYPE_INTERSECTION,
	TYPE_DIFFERENCE,
	TYPE_SYMMETRIC_DIFFERENCE,
	TYPE_CONPLEMENT,
	TYPE_BRACKET
};

#define SYSTEM_LIMIT 1000000

int qsort_comp(const void* x,const void* y) {
	const int* a=(const int*)x;
	const int* b=(const int*)y;
	if(*a>*b)return 1;
	if(*a<*b)return -1;
	return 0;
}

typedef struct {
	/* 8*64==512>500 */
	unsigned long long list[8];
} set_t;

typedef struct {
	int type;
	int value;
} rp_t;

int element_raw_num;
int element_num;
int elements_raw[500];
int elements[500];
set_t sets[6];
int set_num[5];
int set_elements[5][100];

int stack_num;
int operator_stack[SYSTEM_LIMIT];
set_t calc_stack[SYSTEM_LIMIT];
int rp_num;
rp_t rp[SYSTEM_LIMIT];

int search_element(int element) {
	int left,right,mid;
	left=0;right=element_num-1;
	while(left<=right) {
		mid=(left+right)/2;
		if(elements[mid]==element)return mid;
		else if(elements[mid]<element)left=mid+1;
		else right=mid-1;
	}
	return -1;
}

void set_empty(set_t* set) {
	int i;
	for(i=0;i<8;i++)set->list[i]=0;
}

void set_add(set_t* set,int toadd) {
	int pos=search_element(toadd);
	if(pos<0)return;
	set->list[pos/64]|=(1ull<<(pos%64));
}

int is_included(set_t* set,int pos) {
	return set->list[pos/64] & (1ull<<(pos%64));
}

void compile_reverse_porland(void) {
	int now;
	stack_num=0;
	rp_num=0;
	while((now=getchar())!='\n' && now!=EOF) {
		switch(now) {
			case 'A':case 'B':case 'C':case 'D':case 'E':
				rp[rp_num].type=TYPE_SET;
				rp[rp_num].value=now-'A';
				rp_num++;
				break;
			case 'U':
				rp[rp_num].type=TYPE_SET;
				rp[rp_num].value=5;
				rp_num++;
				break;
			case 'u':
				while(stack_num>0 &&
						operator_stack[stack_num-1]!=TYPE_BRACKET) {
					rp[rp_num++].type=operator_stack[--stack_num];
				}
				operator_stack[stack_num++]=TYPE_UNION;
				break;
			case 'i':
				while(stack_num>0 &&
						operator_stack[stack_num-1]!=TYPE_BRACKET) {
					rp[rp_num++].type=operator_stack[--stack_num];
				}
				operator_stack[stack_num++]=TYPE_INTERSECTION;
				break;
			case 'd':
				while(stack_num>0 &&
						operator_stack[stack_num-1]!=TYPE_BRACKET) {
					rp[rp_num++].type=operator_stack[--stack_num];
				}
				operator_stack[stack_num++]=TYPE_DIFFERENCE;
				break;
			case 's':
				while(stack_num>0 &&
						operator_stack[stack_num-1]!=TYPE_BRACKET) {
					rp[rp_num++].type=operator_stack[--stack_num];
				}
				operator_stack[stack_num++]=TYPE_SYMMETRIC_DIFFERENCE;
				break;
			case 'c':
				operator_stack[stack_num++]=TYPE_CONPLEMENT;
				break;
			case '(':
				operator_stack[stack_num++]=TYPE_BRACKET;
				break;
			case ')':
				while(stack_num>0 &&
						operator_stack[stack_num-1]!=TYPE_BRACKET) {
					rp[rp_num++].type=operator_stack[--stack_num];
				}
				if(stack_num>0)stack_num--;
				break;
			default:
				exit(ERROR_INVALID_EXPRESSION);
				break;
		}
		if(stack_num>=SYSTEM_LIMIT-1)exit(ERROR_LIMIT_EXCEEDED);
		if(rp_num>=SYSTEM_LIMIT-1)exit(ERROR_LIMIT_EXCEEDED);
	}
	while(stack_num>0) {
		rp[rp_num++].type=operator_stack[--stack_num];
	}
}

set_t calc_reverse_porland(void) {
	int i,j;
	stack_num=0;
	for(i=0;i<rp_num;i++) {
		switch(rp[i].type) {
			case TYPE_SET:
				calc_stack[stack_num++]=sets[rp[i].value];
				break;
			case TYPE_UNION:
				if(stack_num<2)exit(ERROR_INVALID_STACK);
				for(j=0;j<8;j++) {
					calc_stack[stack_num-2].list[j]|=
						calc_stack[stack_num-1].list[j];
				}
				stack_num--;
				break;
			case TYPE_INTERSECTION:
				if(stack_num<2)exit(ERROR_INVALID_STACK);
				for(j=0;j<8;j++) {
					calc_stack[stack_num-2].list[j]&=
						calc_stack[stack_num-1].list[j];
				}
				stack_num--;
				break;
			case TYPE_DIFFERENCE:
				if(stack_num<2)exit(ERROR_INVALID_STACK);
				for(j=0;j<8;j++) {
					calc_stack[stack_num-2].list[j]&=
						~calc_stack[stack_num-1].list[j];
				}
				stack_num--;
				break;
			case TYPE_SYMMETRIC_DIFFERENCE:
				if(stack_num<2)exit(ERROR_INVALID_STACK);
				for(j=0;j<8;j++) {
					calc_stack[stack_num-2].list[j]^=
						calc_stack[stack_num-1].list[j];
				}
				stack_num--;
				break;
			case TYPE_CONPLEMENT:
				if(stack_num<1)exit(ERROR_INVALID_STACK);
				for(j=0;j<8;j++) {
					calc_stack[stack_num-1].list[j]=
						(~calc_stack[stack_num-1].list[j]) &
						sets[5].list[j];
				}
				break;
			default:
				exit(ERROR_INVALID_CALCULATION);
		}
		if(stack_num>=SYSTEM_LIMIT-1)exit(ERROR_LIMIT_EXCEEDED);
	}
	if(stack_num!=1)exit(ERROR_INVALID_RESULT);
	return calc_stack[0];
}

int main(void) {
	int now_set_num;
	char setname[4];
	int i,j;
	set_t result;
	int found;
	while(scanf("%s%d",setname,&now_set_num)==2) {
		/* load sets */
		element_raw_num=0;
		set_num[0]=set_num[1]=set_num[2]=set_num[3]=set_num[4]=0;
		for(i=0;i<5;i++) {
			if(i!=0)scanf("%s%d",setname,&now_set_num);
			if(now_set_num==0)break;
			if(now_set_num<0 || now_set_num>100)return ERROR_LIMIT_EXCEEDED;
			if(setname[0]<'A' || setname[0]>'E')return ERROR_WRONG_SET_NAME;
			set_num[setname[0]-'A']=now_set_num;
			for(j=0;j<now_set_num;j++) {
				int buf;
				scanf("%d",&buf);
				set_elements[setname[0]-'A'][j]=buf;
				elements_raw[element_raw_num++]=buf;
			}
		}
		while(getchar()!='\n');

		/* make element list */
		qsort(elements_raw,element_raw_num,sizeof(int),qsort_comp);
		element_num=0;
		for(i=0;i<element_raw_num;i++) {
			if(i==0 || elements_raw[i-1]!=elements_raw[i]) {
				elements[element_num++]=elements_raw[i];
			}
		}
		for(i=0;i<5;i++) {
			set_empty(&sets[i]);
			for(j=0;j<set_num[i];j++) {
				set_add(&sets[i],set_elements[i][j]);
			}
		}
		/* make set U */
		set_empty(&sets[5]);
		for(i=0;i<element_num;i++)set_add(&sets[5],elements[i]);

		/* do calcuation */
		compile_reverse_porland();
		result=calc_reverse_porland();

		/* output result */
		found=0;
		for(i=0;i<element_num;i++) {
			if(is_included(&result,i)) {
				if(found)putchar(' ');
				printf("%d",elements[i]);
				found=1;
			}
		}
		if(!found)printf("NULL");
		putchar('\n');
	}
	return 0;
}