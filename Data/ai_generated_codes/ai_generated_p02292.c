#include <stdio.h>

// Function to calculate the cross product of two vectors (p1 - p0) and (p2 - p0)
int crossProduct(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y) {
    return ((p1x - p0x) * (p2y - p0y) - (p1y - p0y) * (p2x - p0x));
}

// Function to determine the orientation of three points
void orientation(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y) {
    int cross = crossProduct(p0x, p0y, p1x, p1y, p2x, p2y);

    // Counterclockwise
    if (cross > 0) {
        printf("COUNTER_CLOCKWISE\n");
        return;
    }

    // Clockwise
    if (cross < 0) {
        printf("CLOCKWISE\n");
        return;
    }

    // Collinear, check for relative position of p2
    if (cross == 0) {
        // Check if p2 is on the line segment p0p1
        if (((p2x >= p0x && p2x <= p1x) || (p2x >= p1x && p2x <= p0x)) &&
            ((p2y >= p0y && p2y <= p1y) || (p2y >= p1y && p2y <= p0y))) {
            printf("ON_SEGMENT\n");
            return;
        }

        // Check if p2 is on the line p0p1 in the order p2, p0, p1
        if ((p2x < p0x && p2x < p1x) || (p2x > p0x && p2x > p1x) ||
            (p2y < p0y && p2y < p1y) || (p2y > p0y && p2y > p1y)) {
            printf("ONLINE_BACK\n");
            return;
        }

        // Check if p2 is on the line p0p1 in the order p0, p1, p2
        printf("ONLINE_FRONT\n");
    }
}

int main() {
    int p0x, p0y, p1x, p1y, q, p2x, p2y;

    // Read coordinates of p0 and p1
    scanf("%d %d %d %d", &p0x, &p0y, &p1x, &p1y);

    // Read number of queries
    scanf("%d", &q);

    // Read coordinates of p2 for each query
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &p2x, &p2y);
        orientation(p0x, p0y, p1x, p1y, p2x, p2y);
    }

    return 0;
}