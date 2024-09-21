#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_ROW_MAX		200000									// 最大行数
#define D_COL_CNT		7										// 列数
#define D_GRP_MAX		D_ROW_MAX * D_COL_CNT					// 最大グループ数

// 内部変数
static FILE *szpFpI;											// 入力
static long long slRow;											// 全行数
static int siDiv;												// 除数
static char sc2Mass[D_ROW_MAX][D_COL_CNT];						// マス
static int si1GNo[D_GRP_MAX];									// グループ番号
static int siGCnt;												// グループ数

// 内部変数 - テスト用
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
	static int siTNo;
#endif

// １行出力
int
fOutLine(
	char *pcpLine				// <I> １行
)
{
	char lc1Buf[1024];

#ifdef D_TEST
	lc1Buf[0] = '\0';
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, pcpLine)) {
		siRes = -1;
	}
#else
	printf("%s", pcpLine);
#endif

	return 0;
}

// グループ番号 - 取得
int
fGNoGet(
	int piRow					// <I> 行
	, int piCol					// <I> 列
)
{
	// グループ番号
	int liNo = piRow * D_COL_CNT + piCol;
	if (liNo == si1GNo[liNo]) {
		return liNo;
	}

	// グループ番号 - 取得
	piRow = si1GNo[liNo] / D_COL_CNT;
	piCol = si1GNo[liNo] % D_COL_CNT;
	si1GNo[liNo] = fGNoGet(piRow, piCol);

	return si1GNo[liNo];
}

// 同一グループ化
int
fGrpConv(
	int piRow1					// <I> 行１
	, int piCol1				// <I> 列１
	, int piRow2				// <I> 行２
	, int piCol2				// <I> 列２
)
{
	// 色
	if (sc2Mass[piRow1][piCol1] != 0) {
		return 0;
	}
	if (sc2Mass[piRow2][piCol2] != 0) {
		return 0;
	}

	// グループ番号 - 取得
	int liGNo1 = fGNoGet(piRow1, piCol1);
	int liGNo2 = fGNoGet(piRow2, piCol2);
	if (liGNo1 == liGNo2) {
		return 0;
	}

	// 同一グループ化
	si1GNo[liGNo2] = liGNo1;
	siGCnt--;

	return 0;
}

// グループ数 - 取得
int
fGetGCnt(
	int piRow					// <I> 行数
)
{
	int i, j;

	// グループ番号 - 初期化
	siGCnt = 0;
	for (i = 0; i < piRow; i++) {
		for (j = 0; j < D_COL_CNT; j++) {
			if (sc2Mass[i][j] == 0) {
				int liNo = i * D_COL_CNT + j;
				si1GNo[liNo] = liNo;
				siGCnt++;
			}
		}
	}

	// 同一グループ化 - 右方向
	for (i = 0; i < piRow; i++) {
		for (j = 0; j < D_COL_CNT - 1; j++) {
			fGrpConv(i, j, i, j + 1);
		}
	}

	// 同一グループ化 - 下方向
	for (i = 0; i < piRow - 1; i++) {
		for (j = 0; j < D_COL_CNT; j++) {
			fGrpConv(i, j, i + 1, j);
		}
	}

	return siGCnt;
}

// 実行メイン
int
fMain(
)
{
	int i, j;
	char lc1Buf[1024];

	// データ - 初期化
	memset(sc2Mass, 0, sizeof(sc2Mass));

	// 全行数・除数・黒数 - 取得
	int liBCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%lld%d%d", &slRow, &siDiv, &liBCnt);

	// 最小単位の行数
	int liMRow;
	if (siDiv % D_COL_CNT) {
		liMRow = siDiv;
	}
	else {
		liMRow = siDiv / D_COL_CNT;
	}

	// 黒 - 取得
	for (i = 0; i < liBCnt; i++) {
		int liNum;
		fscanf(szpFpI, "%d", &liNum);

		// マス - 黒化
		for (j = 0; ; j++) {
			int liRow = liNum / D_COL_CNT;
			if (liRow >= liMRow) {
				break;
			}
			int liCol = liNum % D_COL_CNT;
			sc2Mass[liRow][liCol] = 1;
			liNum += siDiv;
		}
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// グループ数 - 取得
	long long llGCnt = fGetGCnt(liMRow);

	// 最小単位超
	if (slRow > liMRow) {
		slRow -= liMRow;

		// マスコピー
		memcpy(sc2Mass[liMRow], sc2Mass[0], sizeof(char) * liMRow * D_COL_CNT);

		// グループ数 - 増加分
		long long llGCnt2 = fGetGCnt(liMRow * 2);
		llGCnt2 -= llGCnt;

		// グループ数 - 加算
		llGCnt += slRow / (long long)liMRow * llGCnt2;
	}

	// 出力
	sprintf(lc1Buf, "%lld\n", llGCnt);
	fOutLine(lc1Buf);

	return 0;
}

// １回実行
int
fOne(
)
{
	int liRet;
	char lc1Buf[1024];

	// 入力 - セット
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", siTNo);
	szpFpI = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", siTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#else
	szpFpI = stdin;
#endif

	// 実行メイン
	liRet = fMain();

	// 残データ有無
#ifdef D_TEST
	lc1Buf[0] = '\0';
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, "")) {
		siRes = -1;
	}
#endif

	// テストファイルクローズ
#ifdef D_TEST
	fclose(szpFpI);
	fclose(szpFpA);
#endif

	// テスト結果
#ifdef D_TEST
	if (siRes == 0) {
		printf("OK %d\n", siTNo);
	}
	else {
		printf("NG %d\n", siTNo);
	}
#endif

	return 0;
}

// プログラム開始
int
main()
{

#ifdef D_TEST
	int i;
	for (i = D_TEST_SNO; i <= D_TEST_ENO; i++) {
		siTNo = i;
		fOne();
	}
#else
	fOne();
#endif

	return 0;
}

