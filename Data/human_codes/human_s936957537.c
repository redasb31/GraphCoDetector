#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_FLOWER_MAX	100000									// 最大花数

// 内部構造体 - 花情報
typedef struct Flower {
	long long mlStart;											// １本目
	long long mlSep;											// 間隔
} Flower;

// 内部変数
static FILE *szpFpI;											// 入力
static Flower sz1Flower[D_FLOWER_MAX];							// 花
static int siFCnt;												// 花数
static long long slNCnt;										// 必要花数

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
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, pcpLine)) {
		siRes = -1;
	}
#else
	printf("%s", pcpLine);
#endif

	return 0;
}

// 花数 - 取得
long long
fGetFCnt(
	long long plPos				// <I> 位置
)
{
	int i;

	long long llSum = 0;
	for (i = 0; i < siFCnt; i++) {
		if (plPos >= sz1Flower[i].mlStart) {
			llSum += 1 + (plPos - sz1Flower[i].mlStart) / sz1Flower[i].mlSep;
		}
	}

	return llSum;
}

// 実行メイン
long long
fMain(
)
{
	int i;
	char lc1Buf[1024];

	// 花数・必要花数 - 取得
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%lld", &siFCnt, &slNCnt);

	// 花・最大位置 - 取得
	long long llMax = LLONG_MAX;
	for (i = 0; i < siFCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%lld%lld", &sz1Flower[i].mlStart, &sz1Flower[i].mlSep);

		// 必要距離
		long long llLen = sz1Flower[i].mlStart + (slNCnt - 1) * sz1Flower[i].mlSep;
		if (llMax > llLen) {
			llMax = llLen;
		}
	}

	// 位置 - 取得
	long long llMin = 0;
	long long llPos = llMax;
	while (llMin <= llMax) {

		// 中間値
		long long llVal = (llMin + llMax) / 2;

		// 花数 - 取得
		long long llFCnt = fGetFCnt(llVal);

		// 範囲を絞る
		if (llFCnt >= slNCnt) {
			llPos = llVal;
			llMax = llVal - 1;
		}
		else {
			llMin = llVal + 1;
		}
	}

	return llPos;
}

// １回実行
int
fOne(
)
{
	long long llRet;
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
	llRet = fMain();

	// 出力
	sprintf(lc1Buf, "%lld\n", llRet);
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

