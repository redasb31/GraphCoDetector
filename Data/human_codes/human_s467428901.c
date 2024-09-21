#include<stdio.h>
#include<math.h>

int main(){
	int n;
	char box[9][9];
	char ans[9][9][10000];
	int x[100]={0},y[100]={0};
	int l,i,j,k,count=0;
	int start_x=0,start_y=0;
	int end_x=0,end_y=0;
	
	scanf("%d",&n);
	for(l=0;l<n;l++){
	for(i=0;i<8;i++)scanf("%s",box[i]);
	
	scanf("%d",&x[0]);
	scanf("%d",&y[0]);

	x[0]--;
	y[0]--;
	
	for(j=0;j<=count;j++){
		
		k=count;
		
		if(x[j]<=3)start_x=0;
		else start_x=x[j]-3;
		if(y[j]<=3)start_y=0;
		else start_y=y[j]-3;
	
		if(x[j]+3>=8)end_x=7;
		else end_x=x[j]+3;
		if(y[j]+3>=8)end_y=7;
		else end_y=y[j]+3;
		
		
		for(i=start_x;i<=end_y;i++){
			if(box[y[j]][i]=='1'){
				count++;
				y[count]=y[j];
				x[count]=i;
				box[y[j]][i]='0';
			}
		}
		
		for(i=start_y;i<=end_y;i++){
			if(box[i][x[j]]=='1'){
				count++;
				x[count]=x[j];
				y[count]=i;
				box[i][x[j]]='0';
			}
		}
	}
		for(i=0;i<8;i++){
			for(j=0;j<8;j++)ans[i][j][l]=box[i][j];
		}
			count=0;
	}
	for(l=0;l<n;l++){
		printf("Data %d:\n",(l+1));
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
					printf("%c",ans[i][j][l]);
			}
			printf("\n");
		}
	}
	return 0;
}