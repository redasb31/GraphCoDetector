#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 100
#define EPS 1e-9

double b[MAX_N], c[MAX_N][MAX_N], h[MAX_N];
int n, H;

// Calculates the total cost of the given altitudes
double calculate_cost() {
    double cost = 0;
    for (int i = 0; i < n; i++) {
        cost += b[i] * h[i];
        for (int j = i + 1; j < n; j++) {
            cost += fabs(h[i] - h[j]) * c[i][j];
        }
    }
    return cost;
}

// Solves the problem using a gradient descent algorithm
void solve() {
    // Initialize the altitudes randomly
    for (int i = 0; i < n; i++) {
        h[i] = (double)rand() / RAND_MAX;
    }

    // Gradient descent
    double learning_rate = 1.0;
    double cost = calculate_cost();
    while (learning_rate > EPS) {
        // Calculate the gradient
        double gradient[MAX_N] = {0};
        for (int i = 0; i < n; i++) {
            gradient[i] += b[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    gradient[i] += (h[i] - h[j]) * c[i][j] * (h[i] > h[j] ? 1 : -1);
                }
            }
        }

        // Update the altitudes
        for (int i = 0; i < n; i++) {
            h[i] -= learning_rate * gradient[i];
        }

        // Calculate the new cost
        double new_cost = calculate_cost();

        // Adjust the learning rate
        if (new_cost < cost) {
            cost = new_cost;
        } else {
            learning_rate /= 2;
        }
    }

    // Adjust the altitudes to satisfy the constraint
    double sum_h = 0;
    for (int i = 0; i < n; i++) {
        sum_h += h[i];
    }
    double factor = (H - (1 - 1e-9) * sum_h) / sum_h;
    for (int i = 0; i < n; i++) {
        h[i] *= factor;
    }
}

int main() {
    int case_num = 1;
    while (scanf("%d %d", &n, &H) == 2 && (n || H)) {
        for (int i = 0; i < n; i++) {
            scanf("%lf", &b[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%lf", &c[i][j]);
            }
        }

        printf("Case %d:\n", case_num++);
        solve();
        for (int i = 0; i < n; i++) {
            printf("%.9lf ", h[i]);
        }
        printf("\n");
    }
    return 0;
}