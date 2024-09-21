#include<stdio.h>

int main(){

	int i,j,tmp,card[5]={0},pair[5],count[4];
	char *rank[30];
	while(scanf("%d,%d,%d,%d,%d",&card[0],&card[1],&card[2],&card[3],&card[4])!=EOF){
		for(i=0;i<5;i++) pair[i]=0;
		for(i=0;i<4;i++) count[i]=0;
		*rank="";

		for(i=0;i<5;i++){
			for(j=1;j<5-i;j++){
				if(card[j-1]>card[j]){
					tmp=card[j-1];
					card[j-1]=card[j];
					card[j]=tmp;
				}
			}
		}

		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				if(card[i]==card[j]){
					pair[i]++;
				}
			}
		}

		for(i=0;i<5;i++){
			if(pair[i]==4){
				*rank="four card";
				break;
			}
			else if(pair[i]==2){
				for(j=0;j<5;j++){
					if(pair[j]==3){
						*rank="full house";
						break;
					}
				}
				if(*rank=="full house") break;
			}
			else if(pair[i]==3){
				for(j=0;j<5;j++){
					if(pair[j]==2){
						*rank="full house";
						break;
					}
				}
				if(*rank=="full house") break;
				*rank="three card";
			}
			if(pair[i]==2) count[1]++;
		}
		if(card[0]+1==card[1] && card[0]+2==card[2] && card[0]+3==card[3] && card[0]+4==card[4]) *rank="straight";
		else if(card[0]+9==card[1] && card[0]+10==card[2] && card[0]+11==card[3] && card[0]+12==card[4]) *rank="straight";
		else if(count[1]==4) *rank="two pair";
		else if(count[1]==2 && *rank=="") *rank="one pair";
		else if(*rank=="") *rank="null";

		printf("%s\n",*rank);

	}





	return 0;

}