#include <stdio.h>
#include <stdlib.h>
#include <time.h>

short int tspl[50][4],tt[1260];
int N,M,t,ts,te,r,n,m,q,i,j,k;

int main(){
	while(0<=scanf("%d%d",&N,&M)){
		if(N==0 && M==0){
			break;
		}
				
		scanf("%d",&r);
		
		for(q=0;q<r;q++){
			scanf("%d%d%d%d",&tspl[q][0],&tspl[q][1],&tspl[q][2],&tspl[q][3]);
		}
		
		scanf("%d",&q);
		
		for(n=0;n<q;n++){
			scanf("%d%d%d",&ts,&te,&m);

			for(t=0;t<1260;t++){
				tt[t]=0;
			}
			
			for(t=0;t<r;t++){
				if(tspl[t][2]==m && tspl[t][3]==1){
					for(j=t+1;j<r;j++){
						if(tspl[j][1]==tspl[t][1]){
							for(k=tspl[t][0];k<tspl[j][0];k++){
								tt[k]=1;
							}
							break;
						}
					}
				}
			}
			
			j=0;
			for(t=ts;t<te;t++){
				if(tt[t]==1){
					j++;
				}
			}
			
			printf("%d\n",j);
		}
	}
	return 0;
}