#include<stdio.h>
int n,m,i,j,k,l,x,y,p,r,t=0,h[20],w[20],q[1<<16],d[1<<16]={1};
int MIN(int a,int b){return a<b?a:b;}
int MAX(int a,int b){return a<b?b:a;}
int main(){
	char s[20],c[5]={"RGB"};
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d %d",&h[i],&w[i]);
	for(i=0;i<16;i++)scanf(" %c",&s[i]);
	q[t=0]=0;
	for(r=1;r-t;t++){
		for(i=0;i<n;i++){
			for(j=0;j<3;j++){
				for(k=-h[i]+1;k<4;k++){
					for(l=-w[i]+1;l<4;l++){
						m=q[t];
						for(y=MAX(0,k);y<MIN(4,k+h[i]);y++){
							for(x=MAX(0,l);x<MIN(4,l+w[i]);x++){
								//if(k+y<0||3<k+y||l+x<0||3<l+x)continue;
								p=(y)*4+x;
								if(s[p]==c[j])m|= (1<<p);
								else          m&=~(1<<p);
							}
						}//f(m);
						if(d[m]==0)d[q[r++]=m]=d[q[t]]+1;
					}
				}//printf("\n%d\n\n",r);
			}
		}//printf("\n\n%d ",r);
		//f(q[t]);
	}
	//for(i=0;i<(1<<16);i++)printf("%d\n",d[i]);
	printf("%d\n",d[(1<<16)-1]-1);
	return 0;
}
