/*      ex3_2
        Tarara  */
#include <stdio.h>

int main(void)
{
    int pencils; //鉛筆の本数
    scanf("%d", &pencils);

    int digit = pencils % 10; //鉛筆の本数の一の位の数
    if (digit == 3)
        printf("bon\n");
    else if (digit == 0 || digit == 1 || digit == 6 || digit == 8)
        printf("pon\n");
    else // 0, 1, 6, 8の時
        printf("hon\n");
    return 0;
}