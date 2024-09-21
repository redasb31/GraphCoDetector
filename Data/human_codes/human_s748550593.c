#include <stdio.h>

int main() {
	int n, i, j, k;
	char map[1000][1000];
	int x, y, cm, f;
	
	while(1) {
		scanf("%d", &n);
		if (n==0) break;
		
		cm=0; j=0;
		for(i=0; i<n;i++) scanf("%s",&map[i]);
		
		for(i=0; i<n*n; i++) {
			x = i % n; y = i / n;
			if (map[y][x]=='*') continue;
			for(j=1;  ; j++) {
				if ( (x+j>=n) || (y+j>=n) ) break;
				f=0;
				if (map[y+j][x+j]!='*') {
					for(k=0; k<j; k++) {
						if (map[y+j][x+k]=='*') {f=1; break;}
						if (map[y+k][x+j]=='*') {f=1; break;}
					}
				}else break;
				if (f) break;
			}
			if (cm<j) cm=j;
			if (cm>=n-1) break;
			
		}
		printf("%d\n", cm);
	}
	
	return 0;
}