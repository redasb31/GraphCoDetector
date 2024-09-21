#include <stdio.h>
#include <string.h>

int get_id(char enzansi) {
	static int id[128]={1};
	if(id[0]==1) {
		id[0]=0;
		id['+']=1;id['-']=2;
		id['*']=3;id['/']=4;
		id['<']=5;id['>']=6;
		id['=']=7;id['&']=8;
		id['|']=9;id['^']=10;
		id['(']=11;id[')']=12;
	}
	return id[enzansi];
}

int enzansi_yuusen[20];
int enzansi_right_ketugo[20];

int enzansi_isdopop(char onstack,char now) {
	int id1=get_id(onstack);
	int id2=get_id(now);
	return enzansi_yuusen[id1]>enzansi_yuusen[id2] ||
		(enzansi_yuusen[id1]==enzansi_yuusen[id2] &&
		!enzansi_right_ketugo[id1]);
}

int main_stack_num;
char main_stack[100][500];
int enzansi_stack_num;
char enzansi_stack[100];
int calc_stack_num;
char calc_stack[100];

int main(void) {
	int data_num,cur_data;
	int teigi_num,nowteigi_num;
	char teigi_rule[4];
	char now_teigi[4];
	char now_siki[200];
	char enzansi_buf[4]={0};
	int siki_num;
	int i,j;
	scanf("%d",&data_num);
	for(cur_data=0;cur_data<data_num;cur_data++) {
		if(cur_data>0)putchar('\n');
		scanf("%d",&teigi_num);
		for(i=0;i<teigi_num;i++) {
			scanf("%s%d",teigi_rule,&nowteigi_num);
			for(j=0;j<nowteigi_num;j++) {
				scanf("%s",now_teigi);
				enzansi_yuusen[get_id(now_teigi[0])]=i;
				enzansi_right_ketugo[get_id(now_teigi[0])]=(teigi_rule[0]=='R');
			}
		}
		scanf("%d",&siki_num);
		for(i=0;i<siki_num;i++) {
			scanf("%s",now_siki);
			main_stack_num=enzansi_stack_num=calc_stack_num=0;
			for(j=0;now_siki[j];j++) {
				if(get_id(now_siki[j])) {
					if(enzansi_stack_num>0) {
						if(now_siki[j]=='(') {
							enzansi_stack[enzansi_stack_num++]=now_siki[j];
						} else if(now_siki[j]==')') {
							while(enzansi_stack_num>0 &&
									enzansi_stack[enzansi_stack_num-1]!='(') {
								calc_stack[calc_stack_num++]=
									enzansi_stack[--enzansi_stack_num];
							}
							if(enzansi_stack_num>0)enzansi_stack_num--;
						} else {
							while(enzansi_stack_num>0 &&
									enzansi_isdopop(
										enzansi_stack[enzansi_stack_num-1],
										now_siki[j])) {
								calc_stack[calc_stack_num++]=
									enzansi_stack[--enzansi_stack_num];
							}
							enzansi_stack[enzansi_stack_num++]=now_siki[j];
						}
					} else {
						enzansi_stack[enzansi_stack_num++]=now_siki[j];
					}
				} else {
					calc_stack[calc_stack_num++]=now_siki[j];
				}
			}
			while(enzansi_stack_num>0) {
				calc_stack[calc_stack_num++]=
					enzansi_stack[--enzansi_stack_num];
			}
			for(j=0;j<calc_stack_num;j++) {
				enzansi_buf[0]=calc_stack[j];
				if(calc_stack[j]=='(' || calc_stack[j]==')')return 1;
				if(get_id(calc_stack[j])) {
					if(main_stack_num<2)return 0;
					strcat(main_stack[main_stack_num-2],enzansi_buf);
					strcat(main_stack[main_stack_num-2],main_stack[main_stack_num-1]);
					strcat(main_stack[main_stack_num-2],")");
					memmove(&main_stack[main_stack_num-2][1],
						&main_stack[main_stack_num-2][0],
						strlen(main_stack[main_stack_num-2])+1);
					main_stack[main_stack_num-2][0]='(';
					main_stack_num--;
				} else {
					strcpy(main_stack[main_stack_num++],enzansi_buf);
				}
			}
			puts(main_stack[0]);
		}
	}
	return 0;
}