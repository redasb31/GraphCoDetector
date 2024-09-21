#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int debug = 0;
int stack[50];
int flag[50];
int sp = 0;

void push(int *stack, int n){
	stack[sp++] = n;
}

int pop(int *stack){
	return stack[--sp];
}

int fill(int v, int cap[], int num){
	//fill(eÊCzñCr[JÌ)
	int i, j,tmp;

	i=num-1;
//	getchar();
	for(i=num-1;i>=0;i--){
		if(cap[i] == v){
			//¬÷
			if(debug) printf("cap[%d] matches v. return 1\n", i);
			for(j=0;j<sp;j++){
				tmp = stack[j];
				flag[tmp] = 1;
				if(debug) printf("flag[%d] has been set.\n", stack[j]);
			}
			flag[i] = 1;
			if(debug) printf("flag[%d] has been set.\n", i);
			continue;
		}else if(cap[i] <= v){
			if(debug) printf("cap[%d] try. v left %d\n", i, v-cap[i]);
			push(stack, i);
			if(fill(v-cap[i], cap, i) == 0){
//				if(debug) printf("cap[%d] did not match\n", i);
				continue;
			}else{
				continue;
			}
		}else{
			if(debug) printf("cap[%d] exceeds v(%d) try next.\n", i, v);
			continue;
		}
	}
	pop(stack);
	return 0;
}

int main(void){
	int i, j, n;
	int *cap;
	int tmp;
	
	while(1){
		scanf("%d", &n);
		if(n == 0){
			return 0;
		}else{
			cap = (int *)malloc(sizeof(int) * n);
//			flag = (int)malloc(sizeof(int) * n);
			memset(&flag, '\0', sizeof(flag));
			for(i=0;i<n;i++){
				scanf("%d", &cap[i]);
			}
			//sort
			for(i=0;i<n;i++){
				for(j=n-1;j>i;j--){
					if(cap[i] > cap[j]){
						tmp = cap[i];
						cap[i] = cap[j];
						cap[j] = tmp;
					}	
				}
				if(debug) printf("cap[%d] = %d\n", i, cap[i]);
			}
			if(debug) printf("water v = %d\n", cap[n-1]);
			fill(cap[n-1], cap, n-1);

			tmp = 1;
			for(i=0;i<n-1;i++){
				if(debug) printf("flag[%d] = %d\n", i, flag[i]);
				tmp *= flag[i];
			}
			if(tmp == 1){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
			sp = 0;
		}

	}
	return 0;
}