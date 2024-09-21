#include<stdio.h>
#include<string.h>
char a[1000000][11],s[11],m[11];
int h,b,r,l,u[10];
int g(char ans[11]){
  int cb=0,ch=0,i,j;
  for(i=0;i<l;i++){
    if(s[i]==ans[i])ch++;
    for(j=0;j<l;j++){
      if(s[i]==ans[j])cb++;
    }
  }
  if(h==ch&&b==cb-ch)return 1;
  return 0;
}
void f(int d){
  int i;
  if(d==0){
    m[l]=0;
    if(g(m))strcpy(a[r++],m);
    return;
  }
  for(i=0;i<10;i++){
    if(u[i])continue;
    u[i]=1;
    m[d-1]=i+'0';
    f(d-1);
    u[i]=0;
  }
}
int main(){
  int n,z,i;
  while(scanf("%d %d",&l,&n),l||n){
    r=0;
    for(i=0;i<10;i++)u[i]=0;
    scanf("%s %d %d",s,&h,&b);
    f(l);
    while(--n){
      scanf("%s %d %d",s,&h,&b);
      for(i=z=0;i<r;i++){
	strcpy(a[i-z],a[i]);
	if(g(a[i])==0)z++;
      }
      r-=z;//printf("\n");
    }
    if(r==1)printf("%s\n",a[0]);
    else    printf("NO\n");
  }
  return 0;
}