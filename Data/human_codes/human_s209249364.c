#include <stdio.h>

int main(void) {
	int N;
	scanf("%d",&N);
	int A,B,C,D,X,Y,Z;
	int i,tmp=0;
	A=N/1000;
	B=(N-A*1000)/100;
	C=(N-A*1000-B*100)/10;
	D=(N-A*1000-B*100-C*10);
	for(i=0;i<8;i++){
		if(i/4==0){
			if(i%4==0||i%4==1){
				if(i%2==0){
					X=C+D;
				}else{
					X=C-D;
				}
				Y=B+X;
			}else{
				if(i%2==0){
					X=C+D;
				}else{
					X=C-D;
				}
				Y=B-X;
			}
			Z=A+Y;
		}else{
			if(i%4==0||i%4==1){
				if(i%2==0){
					X=C+D;
				}else{
					X=C-D;
				}
				Y=B+X;
			}else{
				if(i%2==0){
					X=C+D;
				}else{
					X=C-D;
				}
				Y=B-X;
			}
			Z=A-Y;
		}
		if(Z==7){
			tmp=i;
			break;
		}
	}
	if(i==0){
		printf("%d+%d+%d+%d=%d",A,B,C,D,Z);
	}else if(tmp==1){
		printf("%d+%d+%d-%d=%d",A,B,C,D,Z);
	}else if(tmp==2){
		printf("%d+%d-%d+%d=%d",A,B,C,D,Z);
	}else if(tmp==3){
		printf("%d+%d-%d-%d=%d",A,B,C,D,Z);
	}else if(tmp==4){
		printf("%d-%d+%d+%d=%d",A,B,C,D,Z);
	}else if(tmp==5){
		printf("%d-%d-%d+%d=%d",A,B,C,D,Z);
	}else if(tmp==6){
		printf("%d-%d+%d-%d=%d",A,B,C,D,Z);
	}else if(tmp==7){
		printf("%d-%d-%d-%d=%d",A,B,C,D,Z);
	}
	return 0;
}