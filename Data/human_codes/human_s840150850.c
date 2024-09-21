#include <stdio.h>
int main(void){
    //変数定義
    int N;//N文字
    int M;//M種類
    int Q;//フィルターの数
    int point = 0;//現在のポイント
    int maxpoint = 0;//最大のポイント
    scanf("%d %d %d",&N,&M,&Q);//１行目入力
    int f[Q][4];//フィルター格納用配列、0~(Q-1)
    int l[N];//数列格納用配列、0~(N-1)
    //入力プログラム
    for(int i=0;i<Q;i++){//Q回繰り返す
    	scanf("%d %d %d %d",&f[i][0],&f[i][1],&f[i][2],&f[i][3]);//１行読み取り
    }
    //ループ＆数列作成
    //N文字の数列
    //初期化
    for(int i=1;i<=N;i++){
    	l[i-1]=i;
    }
    while(l[0]!=M-N+1){
        //printf("%d %d %d\n",l[0],l[1],l[2]);
    	//点数計算処理
    	point = 0;
    	for(int i=0;i<Q;i++){//Q回繰り返す
    	    //printf("%d %d %d %d",f[i][0],f[i][1],f[i][2],f[i][3]);
    		if(l[f[i][1]-1]-l[f[i][0]-1]==f[i][2]){
    		    //printf("*\n");
    			point += f[i][3];
    		}else{
    		    //printf("\n");
    		}
    	}
    	if(maxpoint<=point)
          	maxpoint = point;
       	
    	//新規数列作成処理
    	//各n文字目について処理
    	for(int i=N-1;i>=0;i--){
    		if(i==N-1){
    			if(l[i]<M){//右端の数がMより小さいなら
    			l[i]++;
    			break;
    			}
    		}else{
    			if(l[i]<l[i+1]){//右端の数がMより小さいなら
           			l[i]++;
           			break;
           		}
           	}
    	}
    }
    printf("%d",maxpoint);
}
