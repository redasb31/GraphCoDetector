        #include <stdio.h>
         
        int main(void){
            int D,T,S;
        	float S2;
        	
          	scanf("%d %d %d",&D,&T,&S);
         	
		if(1>D || D>10000 || 1>T || T>10000 || 1>S || S>10000)return 1;
        	S2 = D/T;

            if(S2 <= S){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
         
            return 0;
        } 