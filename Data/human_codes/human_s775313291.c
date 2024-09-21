#include <stdio.h>
int main(void) {
	while(1){
		int n;
		scanf("%d",&n);
		if(n==0) break;
		long long int j,id[n],m1[n],s1[n],m2[n],s2[n],m3[n],s3[n],m4[n],s4[n];
		for(j=0;j<n;j++){
			scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld",&id[j],&m1[j],&s1[j],&m2[j],&s2[j],&m3[j],&s3[j],&m4[j],&s4[j]);
		}
		long long int ss1[n],ss2[n],ss3[n],ss4[n],s5[n];
		for(j=0;j<n;j++){
			ss1[j]=(m1[j]*60)+s1[j];
			ss2[j]=(m2[j]*60)+s2[j];
			ss3[j]=(m3[j]*60)+s3[j];
			ss4[j]=(m4[j]*60)+s4[j];
			s5[j]=ss1[j]+ss2[j]+ss3[j]+ss4[j];
		}
		long long int k,tmp,tmp1;
		for(k=n;k>0;k--){
			for(j=0;j<k;j++){
				if(s5[j]>s5[j+1]){
					tmp=s5[j];
					tmp1=id[j];
					s5[j]=s5[j+1];
					id[j]=id[j+1];
					s5[j+1]=tmp;
					id[j+1]=tmp1;
				}
			}
		}
		printf("%lld\n",id[1]);
		printf("%lld\n",id[2]);
		printf("%lld\n",id[n-1]);
	}
	return 0;
}
