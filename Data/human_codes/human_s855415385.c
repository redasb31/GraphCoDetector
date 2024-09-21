#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_W				100										// 幅
#define D_H				21										// 高さ
#define D_CHAR_W		'.'										// 文字 - 白
#define D_CHAR_B		'#'										// 文字 - 黒

// 内部変数
static char sc2Mass[D_H * 2][D_W + 5];							// マス

// 内部変数 - テスト用
#ifdef D_TEST
	static FILE *szpFpT;
#endif

// マスセット
int
fSetMass(
	int piRow					// <I> 開始行 0～
	, char pcIni				// <I> 初期文字
	, char pcSet				// <I> セット文字
	, int piCnt					// <I> セット数
)
{
	int i;

	// 初期化
	for (i = 0; i < D_H; i++) {
		memset(sc2Mass[piRow + i], pcIni, sizeof(sc2Mass[piRow + i]));
		sc2Mass[piRow + i][D_W] = '\0';
	}

	// 文字セット
	piRow++;
	while (piCnt > 0) {

		// １行セット
		for (i = 0; i < D_W; i += 2) {

			// １文字セット
			sc2Mass[piRow][i] = pcSet;

			// 終了チェック
			piCnt--;
			if (piCnt < 1) {
				break;
			}
		}

		// 次の次の行へ
		piRow += 2;
	}

	return 0;
}

// 実行メイン
int
fMain(
	int piTNo					// <I> テスト番号 1～
)
{
	int i;
	char lc1Buf[1024];

	// テストファイルオープン
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
#endif

	// 白数・黒数取得
	int liWCnt, liBCnt;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &liWCnt, &liBCnt);

	// テストファイルクローズ
#ifdef D_TEST
	fclose(szpFpT);
#endif

	// マスセット
	fSetMass(0, D_CHAR_B, D_CHAR_W, liWCnt - 1);
	fSetMass(D_H, D_CHAR_W, D_CHAR_B, liBCnt - 1);

	// 表示
	printf("%d %d\n", D_H * 2, D_W);
	for (i = 0; i < D_H * 2; i++) {
		printf("%s\n", sc2Mass[i]);
	}

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

