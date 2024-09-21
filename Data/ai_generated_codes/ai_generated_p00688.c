#include <stdio.h>
#include <stdlib.h>

// Function to find the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to check if a number is a perfect square
int isPerfectSquare(int num) {
    int sqrtNum = (int)sqrt(num);
    return sqrtNum * sqrtNum == num;
}

// Function to factorize the quadratic formula
void factorize(int a, int b, int c) {
    int p, q, r, s;

    // Calculate the discriminant
    int discriminant = b * b - 4 * a * c;

    // If the discriminant is a perfect square, the quadratic formula can be factored
    if (isPerfectSquare(discriminant)) {
        // Find the square root of the discriminant
        int sqrtDiscriminant = (int)sqrt(discriminant);

        // Calculate p, q, r, and s
        p = a;
        r = 1;
        q = (-b + sqrtDiscriminant) / (2 * a);
        s = (-b - sqrtDiscriminant) / 2;

        // Ensure p > r or (p == r and q >= s) for uniqueness
        if (p < r || (p == r && q < s)) {
            // Swap p and r, and q and s
            int temp = p;
            p = r;
            r = temp;
            temp = q;
            q = s;
            s = temp;
        }

        // Print the factorization
        printf("%d %d %d %d\n", p, q, r, s);
    } else {
        // If the discriminant is not a perfect square, the quadratic formula cannot be factored
        printf("Impossible\n");
    }
}

int main() {
    int a, b, c;

    // Read input until three 0's are encountered
    while (scanf("%d %d %d", &a, &b, &c) == 3 && (a != 0 || b != 0 || c != 0)) {
        // Check if the greatest common divisor of a, b, and c is 1
        if (gcd(gcd(a, b), c) == 1) {
            // Factorize the quadratic formula
            factorize(a, b, c);
        } else {
            // If the greatest common divisor is not 1, the quadratic formula cannot be factored
            printf("Impossible\n");
        }
    }

    return 0;
}