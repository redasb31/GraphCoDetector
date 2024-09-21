#include<stdio.h>
int main(){
	int n, r, i, p, c, q, j;
	int card[50], t[50];
	while(1){
		scanf("%d %d", &n, &r);
		if((n == 0)&&(r == 0))
			break;
		else{
			for(i=0; i<n; i++)
				card[i]=n-i;
			for(j=0; j<r; j++){
				scanf("%d %d", &p, &c);
				q = p;
				for(i=0; i<(p-1);i++){
					t[i] = card[i];					
				}
				for(i=0; i<c; i++){
					card[i] = card[q-1];
					q++;
				}
				for(i=0; i<(p-1); i++){
					card[c]=t[i];
					c++;
				}
			}
		}
		printf("%d\n", card[0]);
	}
	return 0;
}