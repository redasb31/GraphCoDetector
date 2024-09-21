
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int atoiLonger(char a[],long num[]){
	int length;
	int i,j,k=0;
	char temp[10];
	for(i=0;i<9;i++){/*--*/
		temp[i]=0;
	}
	temp[9]='\0';
	length=strlen(a);
	for(j=0;j<9;j++){
		temp[j]='0';
	}
	j=8;
	for(i=length-1;i>=0;i--){
		temp[j]=a[i];
		if(j==0){
			num[k]=atoi(temp);
			k++;
			for(j=0;j<9;j++){
				temp[j]='0';
			}
			j=8;
		}else{
			j--;
		}
	}
	num[k]=atoi(temp);
	return 0;
}

int plus(long a[],long b[],long c[]){
	int temp,i,flag=0;
	for(i=0;i<9;i++){
		temp=a[i]+b[i]+flag;
		flag=0;
		if (temp>=1000000000){
			temp-=1000000000;
			flag=1;
		}
		c[i]=temp;
/*		printf("%dÚ:%d+%d=%d( Óê%d)\n",i,a[i],b[i],c[i],flag);
*/	}
	
	return flag;
}

int printLongNumber(long a[]){
	int i,flag=0;
	for(i=8;i>=0;i--){
		if(a[i]!=0 || flag==1){
			if (flag==0){
				printf("%d",a[i]);
				flag=1;
			}else{
				printf("%09d",a[i]);
			}
		}
	}
	
	printf("\n");
	return 0;
}

int scan(char a[]){
	/*char irane[100000];	*/	/*å«·¬H*/
	int i;
/*	for(i=0;i<100000;i++){*/	/*--*/
/*		irane[i]=0;
	}
*/	a[81]='a';
	scanf("%s",a);
	if(a[81]!='a'){
		printf("overflow\n");
		scanf("%*s");
		return 1;
	}
	return 0;
}

int main(){
	char a[82],b[82];
	long numA[9],numB[9],numC[9];
	int i,j,cnt;
	scanf("%d",&cnt);
	for(j=0;j<cnt;j++){
		for(i=0;i<9;i++){
			numA[i]=0;
			numB[i]=0;
			numC[i]=0;
		}
/*	*/	for(i=0;i<82;i++){
			a[i]='0';
			b[i]='0';
/*	*/	}
		if(scan(a))continue;
		if(scan(b))continue;
	/*	printf("%s\n%s\n",a,b);
	*/	
		atoiLonger(a,numA);
		atoiLonger(b,numB);
		
		if(plus(numA,numB,numC)){
			printf("overflow\n");
			continue;
		}
		
	/*	printLongNumber(numA);
		printLongNumber(numB);
	*/	printLongNumber(numC);
	}
	return 0;
}