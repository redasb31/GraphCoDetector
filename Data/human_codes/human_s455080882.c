#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define isMonth(m)	( 1 <= m && m <= 12 )
#define isYear(y)	( !isMonth(y) && 1 <= y )

void main(void)
{
	char str[8], str_top[8];
	int t, b;

	memset(str, 0, sizeof(str));
	scanf("%s", str);
	memcpy(str_top, str, 8);
	str_top[2] = '\0';

	t = atoi(str_top);
	b = atoi(&str[2]);

	if( isMonth(t) && isMonth(b) )
	{
		puts("AMBIGUOUS");
	}
	else if( isYear(t)  && isMonth(b) )
	{
		puts("YYMM");
	}
	else if( isMonth(t)  && isYear(b))
	{
		puts("MMYY");
	}
	else
	{
		puts("NA");
	}
}