#include<stdio.h>
int main(){
  int Y[]={0,1,0,-1};
  int X[]={1,0,-1,0};
  int n,m,q,h,w,s,a,x[1000],y[1000],d[20][20],i,j,t,r,c[20][20];
  for(i=0;i<20*20;i++)d[i/20][i%20]=2;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)scanf("%d",&d[i+1][j+1]);
  }
  while(m--){
    scanf("%d",&q);
    if(q==0){
      scanf("%d %d %d %d",&h,&w,&s,&a);
      for(i=0;i<=s;i++){
	for(j=0;j<=s;j++){
	  if(a==  0||a==360)c[i][j]=d[h+i][w+j];
	  if(a== 90)c[i][j]=d[h+s-j-1][w  +i  ];
	  if(a==180)c[i][j]=d[h+s-i-1][w+s-j-1];
	  if(a==270)c[i][j]=d[h+  j  ][w+s-i-1];
	}
      }
      for(i=0;i<s;i++){
	for(j=0;j<s;j++)d[i+h][j+w]=c[i][j];
      }
    }
    if(q==1){
      scanf("%d %d %d",&h,&w,&s);
      for(i=0;i<s;i++){
	for(j=0;j<s;j++)d[h+i][w+j]=1-d[h+i][w+j];
      }
    }
    if(q==2){
      scanf("%d",&h);
      w=d[h][1];
      for(i=1;i<n;i++)d[h][i]=d[h][i+1];
      d[h][n]=w;
    }
    if(q==3){
      scanf("%d",&h);
      w=d[h][n];
      for(i=n-2;i;i--)d[h][i+1]=d[h][i];
      d[h][1]=w;
    }
    if(q==4){
      scanf("%d %d",&y[0],&x[0]);
      r=1;
      a=d[y[0]][x[t=0]];
      for(r=1;r-t;t++){//printf("%d %d\n",y[t],x[t]);
	for(i=0;i<4;i++){
	  if(a==d[y[t]+Y[i]][x[t]+X[i]]){
	    d[y[r]=y[t]+Y[i]][x[r]=x[t]+X[i]]=1-a;
	    r++;
	  }
	}
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%d",d[i+1][1]);
    for(j=1;j<n;j++)printf(" %d",d[i+1][j+1]);
    printf("\n");
  }
  return 0;
}
	  
      