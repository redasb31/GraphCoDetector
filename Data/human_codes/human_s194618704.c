#include <stdio.h>
int main(void){
	int n, m, s[5], c[15],i, j, a[3]={};
  scanf("%d %d",&n, &m);
	
	for(i=0; i<m;i++){
		scanf("%d %d", &s[i], &c[i]);
	}
	for(i=0; i<m;i++){
		for(j=0; j<m; j++){
          			if(s[i]>n){
					printf("-1\n");
					return 0;
			}
			if(s[i]==s[j]){
				if(c[i]!=c[j]){
					printf("-1\n");
					return 0;
				}
			}
		}
	}

	for(i=0; i<m;i++){
		if(s[i]==1){
			a[0]=c[i];
		}
		if(s[i]==2){
			a[1]=c[i];
		}
		if(s[i]==3){
			a[2]=c[i];
		}
	}
  
  if(a[0]==0 && n==1){
    printf("0\n");
    return 0;
  }
  if(m==0){
    a[0]=1;
  }
    if(a[0]==0){
    					printf("-1\n");
					return 0;
				}
    
	for(i=0;i<n;i++){
		printf("%d", a[i]);
	}
	printf("\n");
	return 0;
}
