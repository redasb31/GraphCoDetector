#include <stdio.h>
#include <string.h>
#define INF 0x3FFFFFFF

struct edge{
	int x;
	int y;
	int z;
};

int main(void){
	int n, m, p, a, b, t[8], i, j, k, l;
	double d[30][1 << 8], ans;
	struct edge e[200];
	while(1){
		scanf("%d%d%d%d%d",&n,&m,&p,&a,&b);
		if(n == 0 && m == 0 && p == 0 && a == 0 && b == 0) break;
		a--, b--; 
		for(i = 0;i < n;i++)   
			scanf("%d",&t[i]);  
		for(i = 0;i < p;i++){    
			scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z); 
			e[i].x = e[i].x - 1,e[i].y = e[i].y - 1;   
		}     
		for(i = 0;i < p;i++)   
			e[i + p].x = e[i].y, e[i + p].y = e[i].x, e[i + p].z = e[i].z;  
		for(i = 0;i < m;i++)
			for(j = 0;j < (1 << n);j++) d[i][j] = (double) INF;
		d[a][(1 << n) - 1] = 0.0; 
		for(i = 0;i < m;i++){ // max arith 30 
			for(j = 0;j < p * 2;j++){ // max arith 100    
				for(k = 0;k < (1 << n);k++){ // max arith 256   
					for(l = 0;l < n;l++){ // max arith 8  
						if(k & (1 << l) && d[e[j].y][k - (1 << l)] > d[e[j].x][k] + (double) e[j].z / t[l])                            d[e[j].y][k - (1 << l)] = d[e[j].x][k] + (double) e[j].z / t[l];  
					}       
				}           
			}       
		}      
		ans = (double)INF;
		for(i = 0;i < (1 << n);i++)
			if(ans > d[b][i]) ans = d[b][i];   
		if(ans != (double)INF)       
			printf("%.3f\n",ans);  
		else           
			printf("Impossible\n");
	}    
	return 0;