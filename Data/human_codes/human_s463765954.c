#include <stdio.h>
#include <string.h>
#include <math.h>

/***********/
// マクロ定義
/***********/
#define PQUE_SIZE (1000000)    // 優先度付きキューバッファサイズ

#define parent(i) (i/2)      // ヒープにおけるノードiの親のインデックス
#define right(i)  (i*2)      // ヒープにおけるノードiの右の子のインデックス
#define left(i)   (i*2+1)    // ヒープにおけるノードiの左の子のインデックス


/***********/
// 型定義
/***********/
typedef struct{
    double distance;
    char   id;
} PqueItemType;   // 優先度付きキュー格納型

/***********/
// プロトタイプ
/***********/
// 公開関数
void pque_init(void);               // 初期化
int  pque_insert(PqueItemType *a);  // 要素追加
int  pque_extract(PqueItemType *a); // 要素取り出し
// 使用時要実装関数
int  pque_itemcmp(PqueItemType *a, PqueItemType *b); // 要素の優先度比較（PqueItemTypeに合わせて要実装）
// 内部関数
void maxHeapify(int h, PqueItemType a[],int i);
void buildMaxHeap(int h, PqueItemType a[]);

/***********/
// データ
/***********/

// ヒープは配列として持つ。
// インデックス計算の単純化のため、インデックス0は使用しない。
// よって、サイズhのヒープaはa[1]～a[h]を使用する。
PqueItemType    pque[PQUE_SIZE+1];  // バッファ（優先度付きキュー本体）
int             pque_itemcnt;       // 現在の格納数

/***********/
// 関数定義
/***********/
/* キューを初期化する。 */
void pque_init(void){
    pque_itemcnt = 0;
}
/* キューに要素aを追加する。 */
/* 戻り値：成功(0) キューサイズを超えた(-1) */
int pque_insert(PqueItemType *a){
    PqueItemType tmp;
    int idx;

    if(pque_itemcnt >= PQUE_SIZE) return -1;

    /* いったん要素はヒープ末端に追加し、適宜親要素と入れ替えてルートまでたどる */
    pque_itemcnt++;
    pque[pque_itemcnt] = *a;

    idx = pque_itemcnt;
    while( (parent(idx) > 0) && pque_itemcmp(&pque[idx], &pque[idx/2]) ){
        tmp               = pque[idx];
        pque[idx]         = pque[parent(idx)];
        pque[parent(idx)] = tmp;

        idx = parent(idx);
    }

    return 0;
}

/* キューから最優先要素を取り出しaに格納する。 */
/* 戻り値：成功(0) キューに何も格納されていない(-1) */
int pque_extract(PqueItemType *a){
    if(pque_itemcnt <= 0) return -1;

    *a = pque[1];

    if(pque_itemcnt>1){
        pque[1] = pque[pque_itemcnt];
        pque_itemcnt--;
        maxHeapify(pque_itemcnt, pque, 1);
    }else{
        pque_itemcnt--;
    }

    return 0;
}

/* 要素aと要素bの優先度を比較する。 */
/* 戻り値：要素aのほうが優先度が高い(1) それ以外(0) */
int  pque_itemcmp(PqueItemType *a, PqueItemType *b){
    /* PqueItemTypeが整数型であり、大きいほうが優先度が高い */
    return ( a->distance < b->distance ) ? 1 : 0;
}


// サイズhのヒープaにおいて、iのノードを根とするツリーを最大ヒープにする
void maxHeapify(int h, PqueItemType a[],int i){
    int l,r,largest;
    PqueItemType tmp;

    l = left(i);
    r = right(i);
    // 左の子、自分、右の子で値が最大のノードを選ぶ
    largest = i;
    if( (l <= h) && pque_itemcmp(&a[l], &a[largest]) ){
        largest = l;
    }

    if( (r <= h) && pque_itemcmp(&a[r], &a[largest]) ){
        largest = r;
    }

    if( largest != i ){ // i の子の方が値が大きい場合
        tmp         = a[i];
        a[i]        = a[largest];
        a[largest]  = tmp;
        maxHeapify(h, a, largest); // 再帰的に呼び出し
    }
}

// サイズhのヒープaを最大ヒープにする
void buildMaxHeap(int h, PqueItemType a[]){
    int i;
    for( i = h/2; i > 0; i-- ){
        maxHeapify(h, a, i);
    }
}


/* 今回の問題向け */

#define BILL_NUM 100 //ビルの数

#define TRUE 1
#define FALSE 0

#define INF 1e9

void print_route(int start,int goal,int pre[]);
void print_route_sub(int id,int start,int pre[]);

int main(){
    int i,j;
    PqueItemType queitem;
    int n,b,x,y,m,s,g; //入力
    int pos[BILL_NUM+1][2];//ビルの位置
    double dif[BILL_NUM+1][BILL_NUM+1];//ビル間の距離
    double len[BILL_NUM+1];//スタートビルからの距離
    int gone[BILL_NUM+1];//すでに通ったビル
    int pre[BILL_NUM+1];//最短経路時のひとつ前のビル番号

    while(1){
        scanf("%d",&n);
        if(n<=0)break;

        //位置読み込み
        for(i=1;i<=n;i++){
            scanf("%d %d %d",&b,&x,&y);
            pos[i][0]=x;
            pos[i][1]=y;
        }

        //距離計算
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                dif[i][j] = hypot(pos[i][0]-pos[j][0],pos[i][1]-pos[j][1]);
            }
        }

        //クエリ処理
        scanf("%d",&m);
        for(j=0;j<m;j++){
            scanf("%d %d",&s,&g);

            //RAM初期化
            for(i=1;i<=n;i++){
                len[i] =INF;
                gone[i]=FALSE;
                pre[i] =0;
            }

            //ダイクストラ

            //初期設定（最初のビルを距離0としてキューに入れる）
            pque_init();

            len[s] = 0;
            queitem.distance = 0;
            queitem.id = s;
            pque_insert(&queitem);

            //距離が最小のものから順に取り出して処理
            while(pque_extract(&queitem)==0){
                int dist = queitem.distance;
                int id   = queitem.id;
                if(gone[id]==TRUE)continue;
                gone[id] = TRUE;
                for(i=1;i<=n;i++){
                    if(gone[i]==TRUE)continue;
                    if(dif[id][i]>50)continue;//ジャンプできない距離のビルは飛ばす
                    if(len[i]<dist+dif[id][i])continue;//すでにより短い距離でキューに入っているビルは飛ばす
                    //最短距離の更新
                    len[i]=dist+dif[id][i];
                    pre[i]=id;
                    //次に行けるビルとその距離をキューに入れる
                    queitem.distance = len[i];
                    queitem.id = i;
                    pque_insert(&queitem);
                }
            }

            if(len[g]<INF){
                print_route(s,g,pre);
            }else{
                printf("NA\n");
            }
        }
    }

    return 0;
}

//経路表示
void print_route(int start,int goal,int pre[]){
    print_route_sub(pre[goal],start,pre);
    printf("%d\n",goal);
}
//経路表示補助
void print_route_sub(int id,int start,int pre[]){
    if(id!=start)print_route_sub(pre[id],start,pre);
    printf("%d ",id);
}

