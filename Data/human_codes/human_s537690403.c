#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>

int main(){
	int N;
	scanf("%d",&N);
	while(N != 0){
		int x[N],y[N],r[N],m[N];
		for(int i=0;i<N;i++){
			scanf("%d %d %d %d",&x[i],&y[i],&r[i],&m[i]);
		}
		int max = 0;
		for(int i=0;i<N;i++){
			for(double j=0; j< 2*M_PI; j=j+0.001){
				double a,b,c,ab;
				if(j == 0 || j == M_PI){
					a = 1.0;
					b = 0.0;
					c = -x[i]-r[i]*cos(j);
					ab = sqrt(pow(a,2.0)+pow(b,2.0));
				}else{
					a = (-1) * tan(M_PI/2 + j);
					if(a < 0.01 && a > -0.01){
						a = 0.0;
					}
					b = 1.0;
					c = (x[i]+r[i]*cos(j)) * tan(M_PI/2 + j) - y[i] - r[i] * sin(j);
					if(a == 0){
						c = (int)(c*10000)/10000;
					}
					ab = sqrt(pow(a,2.0)+pow(b,2.0));
				}
				int tempmax = 0;
				for(int k=0;k<N;k++){
					if(i==k){
						tempmax++;
					}else{
						double d = fabs(a*x[k] + b*y[k] + c) / ab;
						if(m[k] == 0){
							if((int)(d+0.5) == r[k]){
								tempmax++;
							}
						}else{
							if(d >= r[k] && d <= r[k] + m[k]){
								tempmax++;
							}
						}
					}
				}
				if(max < tempmax){
					max = tempmax;
				}
			}

			for(double j=0; j< 2*M_PI; j=j+0.001){
				double a,b,c,ab;
				if(j == 0 || j == M_PI){
					a = 1.0;
					b = 0.0;
					c = -x[i]-(r[i]+m[i])*cos(j);
					ab = sqrt(pow(a,2.0)+pow(b,2.0));
				}else{
					a = (-1) * tan(M_PI/2 + j);
					if(a < 0.01 && a > -0.01){
						a = 0.0;
					}
					b = 1.0;
					c = (x[i]+( r[i] + m[i] )*cos(j)) * tan(M_PI/2 + j) - y[i] - (r[i] + m[i]) * sin(j);
					if(a == 0){
						c = (int)(c*10000)/10000;
					}
					ab = sqrt(pow(a,2.0)+pow(b,2.0));
				}
				int tempmax = 0;
				for(int k=0;k<N;k++){
					if(i==k){
						tempmax++;
					}else{
						double d = fabs(a*x[k] + b*y[k] + c) / ab;
						if(m[k] == 0){
							if((int)(d+0.5) == r[k]){
								tempmax++;
							}
						}else{
							if(d >= r[k] && d <= r[k] + m[k]){
								tempmax++;
							}
						}
					}
				}
				if(max < tempmax){
					max = tempmax;
				}
			}
		}
		printf("%d\n",max);
		scanf("%d",&N);
	}

}