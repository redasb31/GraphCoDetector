#include<stdio.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
int n;
char b[3][2][2][3];

int progress(char s[][2][3]){
	int flag=1;
	while(flag){
		rep(i,0,20)rep(j,0,2)rep(k,0,2)if(s[i][j][k]=='*'&&(i==0||s[i-1][j][k]=='#'))flag=0;
		if(flag)rep(i,0,20)rep(j,0,2)rep(k,0,2)if(s[i][j][k]=='*'){s[i-1][j][k]=s[i][j][k];s[i][j][k]='.';}
	}
	rep(i,0,20)rep(j,0,2)rep(k,0,2)if(s[i][j][k]=='*')s[i][j][k]='#';
	int ans=0;
	rep(i,0,20)if(s[i][0][0]=='#'&&s[i][0][1]=='#'&&s[i][1][0]=='#'&&s[i][1][1]=='#'){
		ans++;
		rep(ii,i+1,20)rep(j,0,2)rep(k,0,2){s[ii-1][j][k]=s[ii][j][k];s[ii][j][k]='.';}
		i--;
	}
	return ans;
}

int f(char [][2][3],int);
int calc(char ss[][2][3],int c){
	char sss[20][2][3]={};
	rep(i,0,20)rep(j,0,2)rep(k,0,2)sss[i][j][k]=ss[i][j][k];
	rep(i,0,2)rep(j,0,2)rep(k,0,2)sss[18+i][j][k]=b[c][i][j][k]=='#'?'*':'.';
	int temp=progress(sss);
	return temp+f(sss,c+1);
}

int f(char ss[][2][3],int c){
	if(c==n)return 0;	
	int ans=0,ret;

	ret=calc(ss,c);
	ans=max(ans,ret);
	
	int flag=0;
	if((b[c][0][0][0]=='.'&&b[c][0][0][1]=='.'&&b[c][1][0][0]=='.'&&b[c][1][0][1]=='.')
	   ||(b[c][0][1][0]=='.'&&b[c][0][1][1]=='.'&&b[c][1][1][0]=='.'&&b[c][1][1][1]=='.')){
		flag++;
		rep(i,0,2)rep(k,0,2){char t=b[c][i][0][k];b[c][i][0][k]=b[c][i][1][k];b[c][i][1][k]=t;}
		ret=calc(ss,c);
		ans=max(ans,ret);
	}

	if((b[c][0][0][0]=='.'&&b[c][0][1][0]=='.'&&b[c][1][0][0]=='.'&&b[c][1][1][0]=='.')
	   ||(b[c][0][0][1]=='.'&&b[c][0][1][1]=='.'&&b[c][1][0][1]=='.'&&b[c][1][1][1]=='.')){
		flag++;
		rep(i,0,2)rep(j,0,2){char t=b[c][i][j][0];b[c][i][j][0]=b[c][i][j][1];b[c][i][j][1]=t;}
		ret=calc(ss,c);
		ans=max(ans,ret);
	}
	if(flag==2){
		rep(i,0,2)rep(k,0,2){char t=b[c][i][0][k];b[c][i][0][k]=b[c][i][1][k];b[c][i][1][k]=t;}
		ret=calc(ss,c);
		ans=max(ans,ret);
	}
	
	return ans;
}

int main(){
	int h;
	while(scanf("%d%d",&h,&n),n){
		char s[20][2][3];
		rep(i,0,20)rep(j,0,2)rep(k,0,2)s[i][j][k]='.';
		rep(i,0,h)rep(j,0,2)scanf("%s",s[i][j]);
		rep(nn,0,n)rep(i,0,2)rep(j,0,2)scanf("%s",b[nn][i][j]);
		printf("%d\n",f(s,0));
	}
}
