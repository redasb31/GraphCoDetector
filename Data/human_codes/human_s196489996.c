#include <stdio.h>
#include <string.h>

long calc(char *target) {
	long ans = 0;
	char *p = strtok(target, "+");
	while(p) {
		ans += atol(p);
		p = strtok(NULL, "+");
	}
	return ans;
}

main() {
	char S[21];
	scanf("%s", S);

	int i;
	int n = strlen(S);
	
	char target[41];
	int j;
	
	long ans = 0;
	for(i=0;i< 1<< (n - 1); i++) {
		strcpy(target ,S);
		int target_pos = 0;
		for(j=0;j<n;j++) {
			target[target_pos++] = S[j];

			if( ((i >> j) & 1)  == 1) {
				target[target_pos++] = '+';
			}
		}
		target[target_pos] = '\0';
		ans += calc(target);
	}
	printf("%ld\n", ans);
}
