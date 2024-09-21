#include <stdio.h>
#include <ctype.h>

int main(void) {
	char sikibetushi[200];
	char kisoku[2];
	char* sbp;
	while(1) {
		scanf("%s%s",sikibetushi,kisoku);
		if(kisoku[0]=='X')break;
		if(kisoku[0]=='U') {
			putchar(toupper(sikibetushi[0]));
		} else {
			putchar(tolower(sikibetushi[0]));
		}
		for(sbp=sikibetushi+1;*sbp!=0;sbp++) {
			if(isupper(*sbp)) {
				if(kisoku[0]=='D') {
					putchar('_');
					putchar(tolower(*sbp));
				} else putchar(toupper(*sbp));
			} else if(*sbp=='_') {
				*sbp++;
				if(*sbp==0)break;
				if(kisoku[0]=='D') {
					putchar('_');
					putchar(tolower(*sbp));
				} else putchar(toupper(*sbp));
			} else putchar(*sbp);
		}
		putchar('\n');
	}
	return 0;
}