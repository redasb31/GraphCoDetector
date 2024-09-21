#include<stdio.h>
//#define ERROR -1

void fl(int M,int dp[M][M]);

int next_perm(int *p, int n)
{
  int i, j, k, tmp;

  /* 上位桁のほうが下位桁よりも小さいところまで移動 */
  for(i = n - 1; i > 0 && p[i-1] >= p[i]; i--);

  /* pが最大(次の並べ替えがない) */
  if(i == 0) return 0;

  /* p[i-1]より値の大きい最も下位の桁をp[j]とする */
  for(j = n - 1; j > i && p[i-1] >= p[j]; j--);

  /* p[i-1]とp[j]とを交換 */
  tmp = p[i-1], p[i-1] = p[j], p[j] = tmp;

  /* p[i]から最下位までを逆順 */
  for(k = 0; k <= ((n-1)-i)/2; k++)
    tmp = p[i+k], p[i+k] = p[(n-1)-k], p[(n-1)-k] = tmp;

  return 1;
}

int main(){
	int N,M,R;//N=街の数 M=道の数 R=訪れる街の数
	int i,j;//ループ用変数
	scanf("%d %d %d",&N,&M,&R);
/*	if(N<2||N>200)return ERROR;
	if(M<1||M>N*(N-1)/2)return ERROR;
	if(R<2||R>8||R>N)return ERROR;*/
	int res=0,res_tmp[50000],R_ka=1;
	int R_num[R];
	int dist[M];//キョリ
	int d[N][N];//どこからどこへ？のキョリ格納用
	int a,b,tmp;//一時変数

	for(i=0;i<N+1;i++){
		for(j=1;j<N+1;j++){
			d[i][j]=65535;
		}
	}

	//if(N<R)return ERROR;
	for(i=0;i<R;i++){
		scanf("%d ",&R_num[i]);
	}
	for(i=0;i<M;i++){
		scanf("%d %d %d",&a,&b,&dist[i]);
		//if(a==b||a==0||b==0||dist==0)return ERROR;
		d[a][b]=dist[i];//ex:a=1,b=2,dist=2→d[1][2]=2
	}
	for(i=1;i<N+1;i++){
		for(j=1;j<N+1;j++){
			if(d[i][j]!=65535&&d[j][i]==65535){
				d[j][i]=d[i][j];
			}
			else if(d[i][j]!=65535&&d[j][i]!=65535){
				if(d[i][j]>d[j][i]){
					d[i][j]=d[j][i];
				}else{
					d[j][i]=d[i][j];
				}
			}
		}
	}

	/*for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			printf("%dと%dの最短距離＝%d\n",i,j,d[i][j]);
		}
	}*/
	fl(N,d);
    for(i=0;i<N+1;i++){
    	for(j=0;j<N+1;j++){
			if(d[i][j]==65535){
				d[i][j]=-1;
			}
			if(i==j){
				d[i][i]=-1;
			}
    	}
    }

    for(i=R;i!=1;i--){
    	R_ka=i*R_ka;
    }

    //printf("R!=%d\n",R_ka);
    for(j=0;j<R_ka;j++){
    	  /* 並べ替え */
    	  do {
    		  res=0;
    		  for(i=0;i<R-1;i++){
    			  res+=d[R_num[i]][R_num[i+1]];
    		  }
   			res_tmp[j]=res;
   			j++;
    	  } while(next_perm(R_num, R));
		/*for(i=0;i<R-1;i++){
			res+=d[R_num[i]][R_num[i+1]];
		}*/
		/*tmp=R_num[0];
		for(i=0;i<R;i++){
			if(i==R-1){
				R_num[i]=tmp;
			}else{
				R_num[i]=R_num[i+1];
			}
		}*/
    }
	/*for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			printf("%dと%dの最短距離＝%d\n",i,j,d[i][j]);
		}
	}*/
    for(i=0;i<R_ka;i++){
    	if(res>res_tmp[i]){
    		res=res_tmp[i];
    	}
    }
    /*for(i=0;i<R_ka;i++){
    	printf("res_tmp=%d\n",res_tmp[i]);
    }*/
    printf("%d\n",res);
    return 0;
}

void fl(int M,int dp[M][M]){
	int i,j,k;
    for (k = 1; k < M+1; k++) {
      for (j = 1; j < M+1; j++) {
    	  for(i=1;i<M+1;i++){
			if (dp[i][j] > dp[i][k] + dp[k][j]){
			  dp[i][j] = dp[i][k] + dp[k][j];
			}
        }
      }
    }
}

