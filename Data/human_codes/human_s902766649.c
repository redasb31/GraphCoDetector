#include<stdio.h>
int main(void)
{
	int i,j,temp,cnt,flg,n[4+1],l[4+1],s[4+1];
	scanf("%d %d %d %d",&n[0],&n[1],&n[2],&n[3]);
	while(n[0]!=0 || n[1]!=0 || n[2]!=0 || n[3]!=0) {
		flg=0;
		cnt=0;
		while((n[0]!=6)||(n[1]!=1)||(n[2]!=7)||(n[3]!=4)) {
			cnt++;
			for(i=0;i<4-1;i++) {
				for(j=i+1;j<4;j++) {
					if(n[i]<n[j]) {
						temp=n[i];
						n[i]=n[j];
						n[j]=temp;
					}
				}
			}
			for(i=0;i<4;i++) {
				l[i]=n[i];
			}
			for(i=0;i<4-1;i++) {
				for(j=i+1;j<4;j++) {
					if(n[i]>n[j]) {
						temp=n[i];
						n[i]=n[j];
						n[j]=temp;
					}
				}
			}
			for(i=0;i<4;i++) {
				s[i]=n[i];
			}
			for(i=0;i<4;i++) {
				n[i]=l[i]-s[i];
			}
			if((n[0]==n[1])&&(n[1]==n[2])&&(n[2]==n[3])) {
				flg=1;
				printf("NA\n");
				break;
			}
			for(i=3;i>=1;i--) {
				if(n[i]<0) {
					n[i-1]--;
					n[i]+=10;
				}
			}
		}
		if(flg==0) {
			printf("%d\n",cnt);
		}
	scanf("%d %d %d %d",&n[0],&n[1],&n[2],&n[3]);
	}
	return 0;
}