#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_SIZE_MAX		405										// 最大サイズ
#define D_MASS_BLACK	'#'										// マス - 黒
#define D_MASS_WHITE	'.'										// マス - 白

// 内部変数
static FILE *szpFpI;											// 入力
static char sc2Mass[D_SIZE_MAX][D_SIZE_MAX];					// マス
static int siW, siH;											// 幅・高さ

// 内部変数 - テスト用
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// マス数 - 取得
int
fGetMCnt(
	int piX						// <I> 位置X
	, int piY					// <I> 位置Y
	, char pcMass				// <I> 対象マスの色
	, int *pipBCnt				// <O> 黒数
	, int *pipWCnt				// <O> 白数
)
{
	// 対象マスの色 - チェック
	if (sc2Mass[piY][piX] != pcMass) {
		return 0;
	}

	// 処理済
	sc2Mass[piY][piX] = 0;

	// 色数・次の色
	if (pcMass == D_MASS_BLACK) {		// 黒
		(*pipBCnt)++;
		pcMass = D_MASS_WHITE;
	}
	else {								// 白
		(*pipWCnt)++;
		pcMass = D_MASS_BLACK;
	}

	// 上下左右へ
	fGetMCnt(piX + 1, piY, pcMass, pipBCnt, pipWCnt);
	fGetMCnt(piX - 1, piY, pcMass, pipBCnt, pipWCnt);
	fGetMCnt(piX, piY + 1, pcMass, pipBCnt, pipWCnt);
	fGetMCnt(piX, piY - 1, pcMass, pipBCnt, pipWCnt);

	return 0;
}

// 実行メイン
int
fMain(
	int piTNo					// <I> テスト番号 1～
)
{
	int i, j;
	char lc1Buf[1024], lc1Out[1024];

	// データ - 初期化
	memset(sc2Mass, 0, sizeof(sc2Mass));						// マス

	// 入力 - セット
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpI = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#else
	szpFpI = stdin;
#endif

	// 幅・高さ - 取得
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siH, &siW);

	// マス - 取得
	for (i = 1; i <= siH; i++) {
		fgets(&sc2Mass[i][1], sizeof(sc2Mass[0]) - 1, szpFpI);
	}

	// パターン数 - 取得
	long long llPCnt = 0;
	for (i = 1; i <= siH; i++) {
		for (j = 1; j <= siW; j++) {

			// マス数 - 取得
			int liBCnt = 0;
			int liWCnt = 0;
			fGetMCnt(j, i, D_MASS_BLACK, &liBCnt, &liWCnt);

			// パターン数 - 加算
			llPCnt += (long long)liBCnt * (long long)liWCnt;
		}
	}

	// 結果 - セット
	sprintf(lc1Out, "%lld\n", llPCnt);

	// 結果 - 表示
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
#endif

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
		printf("OK %d\n", piTNo);
	}
	else {
		printf("NG %d\n", piTNo);
	}
#endif

	return 0;
}

int
main()
{

#ifdef D_TEST
	int i;
	for (i = D_TEST_SNO; i <= D_TEST_ENO; i++) {
		fMain(i);
	}
#else
	fMain(0);
#endif

	return 0;
}

