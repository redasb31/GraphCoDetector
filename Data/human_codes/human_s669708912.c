#include <stdio.h>
#include <stdlib.h>
//next_permutation
void nexp(int*a,int cnt){
	int l=cnt-1,r=cnt-1;
	int t;
	while(--l>=0&&a[l]>a[l+1]);
	if(l>=0){
		while(a[l]>a[r])r--;
		t=a[l];a[l]=a[r];a[r]=t;
	}
	for(l++,r=cnt-1;l<r;l++,r--)t=a[l],a[l]=a[r],a[r]=t;
}

int a[9]={1,2,3,4,5,6,7,8,9};
char s[100010];
int cnt[10][10];
int m=1e9;
int ans[9];
int main(){
	int n;
	scanf("%d%s",&n,s);
	for(int i=1;i<n;i++)cnt[s[i-1]-'0'][s[i]-'0']++;
	for(int _=0;_<362880;_++){
		int temp=0;
		for(int i=0;i<9;i++)for(int j=0;j<9;j++){
			temp+=cnt[a[i]][a[j]]*(abs(i/3-j/3)+abs(i%3-j%3));
		}
		if(temp<m){
			m=temp;
			for(int i=0;i<9;i++)ans[i]=a[i];
		}
		nexp(a,9);
	}
	for(int i=0;i<9;i++,i%3==0?puts(""):0)printf("%d",ans[i]);
}
