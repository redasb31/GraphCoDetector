#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 100
#define EPS 1e-6

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    double a;
    double b;
    double c;
} Line;

// Function to parse a number from a string
double parseNumber(char *str, int *i) {
    double num = 0;
    int sign = 1;
    if (str[*i] == '-') {
        sign = -1;
        (*i)++;
    }
    while (str[*i] >= '0' && str[*i] <= '9') {
        num = num * 10 + (str[*i] - '0');
        (*i)++;
    }
    return num * sign;
}

// Function to parse a point from a string
Point parsePoint(char *str, int *i) {
    Point p;
    (*i)++; // Skip '('
    p.x = parseNumber(str, i);
    (*i)++; // Skip ','
    p.y = parseNumber(str, i);
    (*i)++; // Skip ')'
    return p;
}

// Function to parse a line from a string
Line parseLine(char *str, int *i) {
    Line l;
    if (str[*i] == '(') {
        (*i)++; // Skip '('
        l = parseLine(str, i);
        (*i)++; // Skip ')'
    } else {
        Point p1 = parsePoint(str, i);
        (*i)++; // Skip '@'
        Point p2 = parsePoint(str, i);
        l.a = p2.y - p1.y;
        l.b = p1.x - p2.x;
        l.c = p1.x * p2.y - p2.x * p1.y;
    }
    return l;
}

// Function to calculate the symmetric point of a point with respect to a line
Point symmetricPoint(Point p, Line l) {
    Point sym;
    double d = l.a * p.x + l.b * p.y + l.c;
    sym.x = p.x - 2 * l.a * d / (l.a * l.a + l.b * l.b);
    sym.y = p.y - 2 * l.b * d / (l.a * l.a + l.b * l.b);
    return sym;
}

// Function to calculate the intersection point of two lines
Point intersectionPoint(Line l1, Line l2) {
    Point p;
    p.x = (l1.b * l2.c - l2.b * l1.c) / (l1.a * l2.b - l2.a * l1.b);
    p.y = (l1.c * l2.a - l2.c * l1.a) / (l1.a * l2.b - l2.a * l1.b);
    return p;
}

// Function to evaluate the expression
Point evaluateExpression(char *str) {
    int i = 0;
    Point p = parsePoint(str, &i);
    while (str[i] == '@') {
        i++;
        if (str[i] == '(') {
            Line l = parseLine(str, &i);
            if (str[i] == '@') {
                i++;
                Point p2 = parsePoint(str, &i);
                p = intersectionPoint(l, parseLine(str, &i));
            } else {
                p = symmetricPoint(p, l);
            }
        } else {
            Point p2 = parsePoint(str, &i);
            p = intersectionPoint(parseLine(str, &i), parseLine(str, &i));
        }
    }
    return p;
}

int main() {
    char str[MAX_LEN];
    while (1) {
        if (fgets(str, MAX_LEN, stdin) == NULL) {
            break;
        }
        if (str[0] == '#') {
            break;
        }
        Point p = evaluateExpression(str);
        printf("%.8lf %.8lf\n", p.x, p.y);
    }
    return 0;
}