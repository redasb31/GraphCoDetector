#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_ARRAY_MAX		200005									// 最大配列数

// 内部変数
static FILE *szpFpI;											// 入力
static long long sl1Array[D_ARRAY_MAX];							// 配列
static int siACnt;												// 配列数
static int si1CntP[D_ARRAY_MAX];								// 回数(正)
static int si1CntM[D_ARRAY_MAX];								// 回数(負)
static long long sl1Work[D_ARRAY_MAX];							// ワーク

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

// 最小値 - 取得
int
fGetMinI(
	int piVal1					// <I> 値１
	, int piVal2				// <I> 値２
)
{
	if (piVal1 < piVal2) {
		return piVal1;
	}
	else {
		return piVal2;
	}
}

// 実行メイン
int
fMain(
)
{
	int i;
	char lc1Buf[1024];

	// データ - 初期化
	memset(si1CntP, 0, sizeof(si1CntP));
	memset(si1CntM, 0, sizeof(si1CntM));

	// 配列数 - 取得
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &siACnt);

	// 配列 - 取得
	sl1Array[0] = LLONG_MIN;
	for (i = 1; i <= siACnt; i++) {
		fscanf(szpFpI, "%lld", &sl1Array[i]);
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// 回数(正) - セット
	memcpy(sl1Work, sl1Array, sizeof(sl1Work));
	for (i = siACnt - 1; i >= 1; i--) {
		si1CntP[i] = si1CntP[i + 1];
		while (sl1Work[i] > sl1Work[i + 1]) {
			sl1Work[i + 1] *= 4;
			si1CntP[i] += 2 * (siACnt - i);
		}
	}

	// 回数(負) - セット
	memcpy(sl1Work, sl1Array, sizeof(sl1Work));
	for (i = 1; i <= siACnt; i++) {
		si1CntM[i] = si1CntM[i - 1] + 1;
		sl1Work[i] *= -1;
		while (sl1Work[i] < sl1Work[i - 1]) {
			sl1Work[i - 1] *= 4;
			si1CntM[i] += 2 * (i - 1);
		}
	}

	// 最小値 - 取得
	int liMin = INT_MAX;
	for (i = 1; i <= siACnt; i++) {
		int liSum = si1CntP[i] + si1CntM[i - 1];
		liMin = fGetMinI(liMin, liSum);
	}

	return liMin;
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

	// 出力
	sprintf(lc1Buf, "%d\n", liRet);
	fOutLine(lc1Buf);

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

