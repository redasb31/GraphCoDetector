#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

	int T,P,R;
	int i,j,k,temp;
	int **t;
	int log_team,log_p,log_time;
	char log_m[10];


	for(;;) {
		scanf("%d %d %d",&T,&P,&R);
		if(!T&&!P&&!R) break;

		t=malloc(T*sizeof(int));
		for(i=0;i<T;i++)
			t[i]=(int *)malloc(4*sizeof(int)); //???i?????????????????¶??????????????????????????£?????°?????????????????£???????????°

		for(i=0;i<T;i++)
			for(j=0;j<4;j++) {
				if(j==0)
					t[i][j]=i+1;
				else
					t[i][j]=0;
			}

		for(i=0;i<R;i++) {
			scanf("%d %d %d %s",&log_team,&log_p,&log_time,log_m);

			//printf("%c\n",log_m[0]);

			if(log_m[0]=='C') {
				t[log_team-1][1]++;
				t[log_team-1][2]+=(t[log_team-1][3])*1200+log_time;
				t[log_team-1][3]=0;
				//printf("%d %d %d\n",t[log_team-1][0],t[log_team-1][1],t[log_team-1][2]);
			}

			else {
				t[log_team-1][3]+=1;
			}
		}

		for(i=0;i<T-1;i++) {
			for(j=i+1;j<T;j++) {
				if(t[i][1]<t[j][1]||(t[i][1]==t[j][1]&&t[i][2]>t[j][2])) {
					for(k=0;k<3;k++) {
					temp=t[i][k];
					t[i][k]=t[j][k];
					t[j][k]=temp;
					}
				}
			}
		}

		for(i=0;i<T-1;i++) {
			for(j=i+1;j<T;j++) {
				if(t[i][1]==t[j][1]&&t[i][2]==t[j][2]&&t[i][0]>t[j][0]) {
					temp=t[i][0];
					t[i][0]=t[j][0];
					t[j][0]=temp;
				}
			}
		}
		for(i=0;i<T;i++)
			printf("%d %d %d\n",t[i][0],t[i][1],t[i][2]);
	}