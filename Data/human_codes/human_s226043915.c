#include<stdio.h> 

int ans=0;

void rensa(int chara3[10000],int n){
	int c,d;
	int s=1;
	for(c=0;c<n;c++){
		if(chara3[c]==chara3[c+1])s++;
		else if(s>=4){
			for(d=0;d<s;d++){
				chara3[c-d]=chara3[c-d+s];
			}
			n-=s;
			rensa(chara3,n);
		}
		else s=1;
		if(c==n-1){
			if(ans>n)ans=n;
			return;
		}
	}
}

void erease(int chara[10000],int a,int b,int n){
	int c,d;
	int chara2[10000];
	for(c=0;c<n;c++){
		chara2[c]=chara[c];
	}
	chara2[b]=a;
	rensa(chara2,n);
	
}

int main(void){
	int a,b,c;
	int n;
	int chara[10000];
	while(scanf("%d",&n),n){
		ans=n;
		for(a=0;a<n;a++){
			scanf("%d",&chara[a]);
		}
		for(b=0;b<n;b++){
			for(a=1;a<=3;a++){
				if(a!=chara[b])erease(chara,a,b,n);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}