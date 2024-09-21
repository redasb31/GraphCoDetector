#include <stdio.h>
#include <math.h>

int main()
{
    long long int nums, first, r, i, disc = 0, answer, n = 0, j;

    scanf("%lld %lld %lld", &nums, &first, &r);

    int conj[nums];
    conj[0] = first;

    for(i = 1; i < nums; i++)
    {
        conj[i] = conj[i-1] + r;
    }
    
    for(i = 0; i < nums; i++)
    {
        for(j = 0; j < nums; j++)
        {
            if(conj[i] - conj[j] == 0 && i != j && nums!= 2)
            {
                disc += 1;
            }
            else if(nums == 2)
            {
                disc = 1;
            }
        }
    }

    n = nums;
    n = n - disc;

    answer = abs(pow(2, n));

    printf("%lld", answer);
    
    return 0;
}