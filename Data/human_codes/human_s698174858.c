#include <stdio.h>

int main(int argc, const char * argv[])
{

    double input1, input2;
    
    scanf("%lf%lf",&input1 ,&input2);
    if (input1 < 35.50 && input2 < 71.00) {
        printf("AAA\n");
    }
    else if (input1 < 37.50 && input2 < 77.00) {
        printf("AA\n");
    }
    else if (input1 < 40.00 && input2 < 83.00) {
        printf("A\n");
    }
    else if (input1 < 43.00 && input2 < 89.00) {
        printf("B\n");
    }
    else if (input1 < 50.00 && input2 < 105.00) {
        printf("C\n");
    }
    else if (input1 < 55.00 && input2 < 116.00) {
        printf("D\n");
    }
    else if (input1 < 70.00 && input2 < 148.00) {
        printf("E\n");
    }
    else {
        printf("NA\n");
    }
    
    
    return 0;
}