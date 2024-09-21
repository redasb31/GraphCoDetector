#include <stdio.h>

int main(void) {
  int start, count, i, end, n, nums[51], sec = 0;
    nums[50] = 0;
    while(scanf("%d",&n), n != 0 ) {
      if(sec) {
	puts("");
      }
        for(i = 0; i < n; i++ ) {
            scanf("%d",&nums[i]);
        }
        for(i = 0; i < n; i++ ) {
            start = nums[i];
            count = 0;
            for(; i < n - 1; i++ ) {
                if(nums[i] + 1 != nums[i + 1]) {
                    break;
                }
                count++;
            }
            if(count) {
                printf("%d-%d",start, nums[i]);
            } else {
                printf("%d",start);
            }
            if(!(i == n - 1)) {
                printf(" ");
            }
        }
	sec=1;
    }
    return 0;
}