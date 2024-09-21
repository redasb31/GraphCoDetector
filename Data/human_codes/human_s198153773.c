#include <stdio.h>
  int main(){
	  int w,h,i,j;
	  int a[101][101];
	  int b[101][101];
	  int c[101][101];
	  int x[101][101];
	  scanf("%d%d",&w,&h);
	  for(i=1;i<=h;i++){
		  for(j=1;j<=w;j++){
			  scanf("%d",&x[j][i]);
		  }
	  }
	  for(i=1;i<=100;i++){
		  for(j=1;j<=100;j++){
			  a[i][j]=0;
			  b[i][j]=0;
			  c[i][j]=0;
		  }
	  }
	  for(i=1;i<=h;i++){
		  if(x[2][i] == 1 && x[1][i] == 1){
			  a[1][i]=1;
		  }else if(x[1][i]==1){
			  a[1][i]=2;
		  }
	  }
	  for(i=1;i<=h;i++){
		  if(x[w-1][i]==1 && x[w][i]==1){
			  a[w][i]=1;
		  }else if(x[w][i]==1){
			  a[w][i]=2;
		  }
	  }
	  for(i=2;i<w;i++){
		  for(j=1;j<=h;j++){
			  if(x[i-1][j]==1 && x[i+1][j]==1 && x[i][j]==1){
				  a[i][j]=0;
			  }else if(x[i-1][j]==0 && x[i+1][j]==0 && x[i][j]==1){
				  a[i][j]=2;
			  }else if(x[i][j]==1){
				  a[i][j]=1;
			  }
		  }
	  }
	  for(i=1;i<=w;i++){
		  if(x[i][2]==1 && x[i][1]==1){
			  b[i][1]=1;
		  }else if(x[i][1]==1){
			  b[i][1]=2;
		  }
	  }
	  for(i=1;i<=w;i++){
		  if(x[i][h-1]==1 && x[i][h]==1){
			  b[i][h]=1;
		  }else if(x[i][h]==1){
			  b[i][h]=2;
		  }
	  }
	  for(i=2;i<h;i+=2){
		  if(x[1][i-1]==1 && x[1][i]==1){
			  b[1][i]=1;
		  }else if(x[1][i]==1){
			  b[1][i]=2;
		  }
	  }
	  for(i=3;i<h;i+=2){
		  if(x[w][i+1]==1 && x[w][i]==1){
			  b[w][i]=1;
		  }else if(x[w][i]==1){
			  b[w][i]=2;
		  }
	  }
	  for(i=2;i<=w;i++){
		  for(j=2;j<h;j+=2){
			  if(x[i][j-1]==1 && x[i-1][j+1]==1 && x[i][j]==1){
				  b[i][j]=0;
			  }else if(x[i][j-1]==0 && x[i-1][j+1]==0 && x[i][j]==1){
				  b[i][j]=2;
			  }else if(x[i][j]==1){
				  b[i][j]=1;
			  }
		  }
	  }
	  for(i=1;i<w;i++){
		  for(j=3;j<h;j+=2){
			  if(x[i+1][j-1]==1 && x[i][j+1]==1 && x[i][j]==1){
				  b[i][j]=0;
			  }else if(x[i+1][j-1]==0 && x[i][j+1]==0 && x[i][j]==1){
				  b[i][j]=2;
			  }else if(x[i][j]==1){
				  b[i][j]=1;
			  }
		  }
	  }
	  if(x[w][1]==1){  c[w][1]=2;}
	  if(x[1][h]==1){  c[1][h]=2;}
      for(i=1;i<w;i++){
		  if(x[i+1][2]==1 && x[i][1]==1){
			  c[i][1]=1;
		  }else if(x[i][1]==1){
			  c[i][1]=2;
		  }
	  }
	  for(i=2;i<=w;i++){
		  if(x[i-1][h-1]==1 && x[i][h]==1){
			  c[i][h]=1;
		  }else if(x[i][h]==1){
			  c[i][h]=2;
		  }
	  }
	  for(i=2;i<h;i+=2){
		  if(x[1][i+1]==1 && x[1][i]==1){
			  c[1][i]=1;
		  }else if(x[1][i]==1){
			  c[1][i]=2;
		  }
	  }
	  for(i=3;i<h;i+=2){
		  if(x[w][i-1]==1 && x[w][i]==1){
			  c[w][i]=1;
		  }else if(x[w][i]==1){
			  c[w][i]=2;
		  }
	  }
	  for(i=2;i<=w;i++){
		  for(j=2;j<h;j+=2){
			  if(x[i-1][j-1]==1 && x[i][j+1]==1 && x[i][j]==1){
				  c[i][j]=0;
			  }else if(x[i-1][j-1]==0 && x[i][j+1]==0 && x[i][j]==1){
				  c[i][j]=2;
			  }else if(x[i][j]==1){
				  c[i][j]=1;
			  }
		  }
	  }
	  for(i=1;i<w;i++){
		  for(j=3;j<h;j+=2){
			  if(x[i][j-1]==1 && x[i+1][j+1]==1 && x[i][j]==1){
				  c[i][j]=0;
			  }else if(x[i][j-1]==0 && x[i+1][j+1]==0 && x[i][j]==1){
				  c[i][j]=2;
			  }else if(x[i][j]==1){
				  c[i][j]=1;
			  }
		  }
	  }
	  int around=0;
	  for(i=1;i<=w;i++){
		  for(j=1;j<=h;j++){
			  around += a[i][j];
			  around += b[i][j];
			  around += c[i][j];
		  }
	  }
	  printf("%d\n",around-6);
	  scanf("%d",&i);
return 0;
}