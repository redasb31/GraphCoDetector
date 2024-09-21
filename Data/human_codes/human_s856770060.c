#include <stdio.h>
#include <string.h>

void strsort(int* a,int len) {
	int tmp;
	for (int i=0;i<len;i++) {
		for (int j=0;j<len;j++) {
			if (a[i]<a[j]) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

int main(void) {
	int n;
	scanf("%d",&n);
	int str[n];
	int strbuf[n];
	int strmed[(n*n)];
	int strmed_i = 0;
	for (int i=0;i<n;i++) {
		scanf(" %d",str+i);
	}
	for (int l=0;l<n;l++) {
		for (int r=l;r<n;r++) {
			memcpy(strbuf,str+l,sizeof(int)*(r-l+1));			
			strsort(strbuf,r-l+1);
			strmed[strmed_i] = strbuf[((r-l+1)/2)];
			strmed_i++;
		}
	}
	strsort(strmed,strmed_i);
	printf("%d\n",strmed[strmed_i/2]);
	return 0;
}