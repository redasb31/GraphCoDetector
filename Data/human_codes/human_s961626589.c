#include <stdio.h>
#include <string.h>

static const char* names[15]={
	"Rock" ,"Fire"  ,"Scissors","Snake"    ,"Human",
	"Tree" ,"Wolf"  ,"Sponge"  ,"Paper"    ,"Air"  ,
	"Water","Dragon","Devil"   ,"Lightning","Gun"
};

int get_id(const char* name) {
	int i;
	for(i=0;i<14;i++) {
		if(strcmp(name,names[i])==0)return i;
	}
	return -1;
}

const char* getnamefromid(int id) {
	static const char* err="Draw";
	if(id<0 || id>14)return err;
	return names[id];
}

int main(void) {
	int n;
	int i,j;
	char hand[100];
	int hands_id[1000];
	int winner;
	int ok,ng;
	while(1) {
		scanf("%d",&n);
		if(n==0)break;
		for(i=0;i<n;i++) {
			scanf("%s",hand);
			hands_id[i]=get_id(hand);
		}
		winner=-1;
		for(i=0;i<n;i++) {
			ok=ng=0;
			for(j=0;j<n;j++) {
				if(hands_id[i]!=hands_id[j]) {
					if((hands_id[i]-hands_id[j]+15)%15>7) {
						ok=1;
					} else {
						ng=1;
					}
				}
			}
			if(ok && !ng){winner=hands_id[i];break;}
		}
		puts(getnamefromid(winner));
	}
	return 0;
}