#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the position of a staff member
typedef struct {
    int x;
    int y;
} Position;

// Structure to store the details of a staff member
typedef struct {
    Position start;
    int T;
    char *pattern;
} Staff;

// Function to check if a point lies on the line segment connecting two points
int onSegment(Position p, Position q, Position r) {
    if (q.x <=  max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <=  max(p.y, r.y) && q.y >= min(p.y, r.y))
        return 1;
    return 0;
}

// Function to calculate the orientation of three points
int orientation(Position p, Position q, Position r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Function to check if two line segments intersect
int doIntersect(Position p1, Position q1, Position p2, Position q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return 1;

    // Special cases:
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return 1;
    // p1, q1 and q2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return 1;
    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return 1;
    // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return 1;

    return 0; // Doesn't intersect
}

// Function to calculate the number of times a staff member crosses the cable
int countCrossings(Staff staff, Position p1, Position p2, int W, int H) {
    int crossings = 0;
    Position current = staff.start;
    for (int i = 0; i < staff.T; i++) {
        for (int j = 0; j < strlen(staff.pattern); j++) {
            switch (staff.pattern[j]) {
                case 'U':
                    current.y--;
                    if (current.y < 0) current.y = 0;
                    break;
                case 'D':
                    current.y++;
                    if (current.y >= H) current.y = H - 1;
                    break;
                case 'L':
                    current.x--;
                    if (current.x < 0) current.x = 0;
                    break;
                case 'R':
                    current.x++;
                    if (current.x >= W) current.x = W - 1;
                    break;
            }
            // Check for crossing
            if (doIntersect(p1, p2, current, current)) {
                crossings++;
            }
        }
    }
    return crossings;
}

int main() {
    int W, H, N;
    scanf("%d %d %d", &W, &H, &N);

    Position p1, p2;
    scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);

    // Adjust coordinates for edge cases
    if (p1.x == W) p1.x--;
    if (p1.y == H) p1.y--;
    if (p2.x == W) p2.x--;
    if (p2.y == H) p2.y--;

    // Store the staff details
    Staff *staff = malloc(N * sizeof(Staff));

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &staff[i].start.x, &staff[i].start.y);
        scanf("%d", &staff[i].T);
        staff[i].pattern = malloc(1001 * sizeof(char)); // Allocate enough space for the pattern
        scanf("%s", staff[i].pattern);
    }

    // Calculate the total crossings
    int totalCrossings = 0;
    for (int i = 0; i < N; i++) {
        totalCrossings += countCrossings(staff[i], p1, p2, W, H);
    }

    printf("%d\n", totalCrossings);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(staff[i].pattern);
    }
    free(staff);

    return 0;
}