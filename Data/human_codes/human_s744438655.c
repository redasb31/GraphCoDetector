#include<stdio.h>
int main(){
  int n,m,y,x,ny,nx,t,r,qx[10000],qy[10000],i,j,c;
  int X[]={1,2, 1,-1,-2,-1};
  int Y[]={1,0,-1,-1, 0, 1};
  while(scanf("%d %d",&n,&m),n||m){
    int d[620][1300]={0};
    while(m--){
      scanf("%d %d",&x,&y);
      d[30-y][60-y+x*2]=-1;
    }
    scanf("%d %d",&x,&y);
    qy[t=0]=30-y;
    qx[0]=60-y+x*2;
    d[qy[t]][qx[t]]=n+1;
    c=1;
    for(r=1;r-t;t++){
      if(d[qy[t]][qx[t]]==1)continue;
      for(i=0;i<6;i++){
	ny=qy[t]+Y[i];
	nx=qx[t]+X[i];
	if(ny<0||60<ny||nx<0||121<nx)continue;
	if(d[ny][nx])continue;
	c++;
	d[ny][nx]=d[qy[t]][qx[t]]-1;
	qx[r  ]=nx;
	qy[r++]=ny;
      }
    }
    /*for(i=0;i<62;i++){
      for(j=0;j<130;j++){
	printf("%2d",d[i][j]);
      }
      printf("\n");
      }//*/
    printf("%d\n",c);
  }
  return 0;
}