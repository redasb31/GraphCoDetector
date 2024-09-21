#include <stdio.h>

int main(){
	int n=0;
	int m=0;
	int dn[100000];
	int dm[200000];
	scanf("%d%d",&n,&m);
	int i=0;
	for(i=0;i<m;i++){
		int a=0;
		int b=0;
		scanf(" %d%d",&a,&b);
		dn[a]++;
		dm[i]=a;
	}
	for(i=0;i<n;i++){
		if (dn[i]==1){
			int j=0;
			for(j=0;j<m;j++){
				if (dm[j]==i){
					printf("%d\n",(j+1));
				}
			}
		}
	}
	return 0;

}