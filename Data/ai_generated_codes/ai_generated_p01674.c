#include <stdio.h>
#include <math.h>

// Structure to represent a 3D vector
typedef struct {
    double x;
    double y;
    double z;
} Vector3D;

// Structure to represent a circle in 3D space
typedef struct {
    Vector3D center;
    Vector3D direction1;
    Vector3D direction2;
} Circle3D;

// Function to calculate the dot product of two vectors
double dotProduct(Vector3D v1, Vector3D v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Function to calculate the cross product of two vectors
Vector3D crossProduct(Vector3D v1, Vector3D v2) {
    Vector3D result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return result;
}

// Function to check if two circles are connected as chained rings
int areCirclesChained(Circle3D circle1, Circle3D circle2) {
    // Calculate the vector connecting the centers of the circles
    Vector3D centerVector;
    centerVector.x = circle2.center.x - circle1.center.x;
    centerVector.y = circle2.center.y - circle1.center.y;
    centerVector.z = circle2.center.z - circle1.center.z;

    // Calculate the dot product of the center vector and the direction vectors of each circle
    double dotProduct1 = dotProduct(centerVector, circle1.direction1);
    double dotProduct2 = dotProduct(centerVector, circle1.direction2);
    double dotProduct3 = dotProduct(centerVector, circle2.direction1);
    double dotProduct4 = dotProduct(centerVector, circle2.direction2);

    // If the dot products are close to zero, the circles are connected as chained rings
    if (fabs(dotProduct1) < 1e-6 && fabs(dotProduct2) < 1e-6 && fabs(dotProduct3) < 1e-6 && fabs(dotProduct4) < 1e-6) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Read the input
    Circle3D circle1, circle2;
    scanf("%lf %lf %lf", &circle1.center.x, &circle1.center.y, &circle1.center.z);
    scanf("%lf %lf %lf %lf %lf %lf", &circle1.direction1.x, &circle1.direction1.y, &circle1.direction1.z,
            &circle1.direction2.x, &circle1.direction2.y, &circle1.direction2.z);
    scanf("%lf %lf %lf", &circle2.center.x, &circle2.center.y, &circle2.center.z);
    scanf("%lf %lf %lf %lf %lf %lf", &circle2.direction1.x, &circle2.direction1.y, &circle2.direction1.z,
            &circle2.direction2.x, &circle2.direction2.y, &circle2.direction2.z);

    // Check if the circles are connected as chained rings
    if (areCirclesChained(circle1, circle2)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}