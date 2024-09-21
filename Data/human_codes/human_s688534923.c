#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int qsort_comp(const void* x,const void* y) {
	int a=*((const int*)x);
	int b=*((const int*)y);
	if(a>b)return 1;
	if(a<b)return -1;
	return 0;
}

#define OP_NULL (0)
#define OP_PLUS (-1)
#define OP_MINUS (-2)
#define OP_MUL (-3)
#define OP_DIV (-4)
#define OP_KAKKO (-5)

#define CALC_ERROR 0x7fffffff

char siki_str[204];

int stack_num;
int stack[200];
int siki_num;
int siki[200];

int result_num;
int result_list[1024];

void compile_rp(int puttern) {
	int i;
	int op_count=0;
	int nowop;
	stack_num=siki_num=0;
	for(i=0;siki_str[i];i++) {
		nowop=OP_NULL;
		if(siki_str[i]=='+') {
			nowop=OP_PLUS;
		} else if(siki_str[i]=='-') {
			nowop=OP_MINUS;
		} else if(siki_str[i]=='*') {
			nowop=OP_MUL;
		} else if(siki_str[i]=='/') {
			nowop=OP_DIV;
		} else if(siki_str[i]=='(') {
			stack[stack_num++]=OP_KAKKO;
		} else if(siki_str[i]==')') {
			while(stack_num>0 && stack[stack_num-1]!=OP_KAKKO) {
				siki[siki_num++]=stack[--stack_num];
			}
			if(stack_num>0)stack_num--;
		} else if(isdigit(siki_str[i])) {
			int nownumber=0;
			while(siki_str[i]!=0 && isdigit(siki_str[i])) {
				nownumber=nownumber*10+siki_str[i]-'0';
				i++;
			}
			siki[siki_num++]=nownumber;
			i--;
		}
		if(nowop!=OP_NULL) {
			if(puttern & (1<<op_count))nowop*=10;
			op_count++;
			if(nowop>-10) {
				while(stack_num>0 && stack[stack_num-1]<=-10) {
					siki[siki_num++]=stack[--stack_num];
				}
			}
			stack[stack_num++]=nowop;
		}
	}
	while(stack_num>0)siki[siki_num++]=stack[--stack_num];
	for(i=0;i<siki_num;i++) {
		if(siki[i]<=-10)siki[i]/=10;
	}
}

int calc_rp(void) {
	int i;
	stack_num=0;
	for(i=0;i<siki_num;i++) {
		if(siki[i]==OP_PLUS) {
			if(stack_num<2)return CALC_ERROR;
			stack[stack_num-2]+=stack[stack_num-1];
			stack_num--;
		} else if(siki[i]==OP_MINUS) {
			if(stack_num<2)return CALC_ERROR;
			stack[stack_num-2]-=stack[stack_num-1];
			stack_num--;
		} else if(siki[i]==OP_MUL) {
			if(stack_num<2)return CALC_ERROR;
			stack[stack_num-2]*=stack[stack_num-1];
			stack_num--;
		} else if(siki[i]==OP_DIV) {
			if(stack_num<2 || stack[stack_num-1]==0)return CALC_ERROR;
			stack[stack_num-2]/=stack[stack_num-1];
			stack_num--;
		} else {
			stack[stack_num++]=siki[i];
		}
	}
	if(stack_num!=1)return CALC_ERROR;
	return stack[0];
}

int main(void) {
	while(scanf("%s",siki_str)==1 && siki_str[0]!='#') {
		int i;
		int tansaku_max;
		int answer;
		tansaku_max=1;
		for(i=0;siki_str[i];i++) {
			if(siki_str[i]=='+' || siki_str[i]=='-' ||
				siki_str[i]=='*' || siki_str[i]=='/')tansaku_max<<=1;
		}
		if(tansaku_max>1024)return 1;
		result_num=0;
		for(i=0;i<tansaku_max;i++) {
			compile_rp(i);
			result_list[result_num]=calc_rp();
			if(result_list[result_num]!=CALC_ERROR)result_num++;
		}
		qsort(result_list,result_num,sizeof(int),qsort_comp);
		answer=result_num;
		for(i=1;i<result_num;i++) {
			if(result_list[i]==result_list[i-1])answer--;
		}
		printf("%d\n",answer);
	}
	return 0;
}