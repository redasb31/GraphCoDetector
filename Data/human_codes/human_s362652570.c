#include <stdio.h>

int main(void)
{
    int W, H, N, p;
    int out, in;
    int i;
    int n;
    
    scanf("%d%d", &W, &H);
    out = W * 2 + H - 2;
    in = (W - 1) * 2 + (H - 2) - 2;

//printf("<<%d %d>>", in, out);

    scanf("%d", &N);
    n = 0;
    for (i = 0; i < N; i++){
        scanf("%d", &p);
        if (p == 0){
            out--;
        }
        else {
            in--;
        }
//printf("<%d %d>", in, out);
        if (out <= W - 1 && in == out){
//printf("(A%d %d)", in, out);
            n++;
        }
        if (W + 1 <= out && out <= W + H - 2){
            if (out - 2 == in){
//printf("(B%d %d)", in, out);
                n++;
            }
        }
        if (W + H - 2 + 1 <= out){
            if (out - 4 == in){
//printf("(C%d %d)", in, out);
                n++;
            }
        }
    }
    printf("%d\n", n);
    
    return (0);
}

