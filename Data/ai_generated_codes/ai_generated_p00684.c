#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int real;
    int imag;
} Complex;

// Function to check if a complex number is within the overflow range
int isOverflow(Complex num) {
    return (num.real > 10000 || num.real < -10000 || num.imag > 10000 || num.imag < -10000);
}

// Function to perform addition of two complex numbers
Complex add(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    if (isOverflow(result)) {
        return (Complex){-1, -1}; // Return an indicator of overflow
    }
    return result;
}

// Function to perform subtraction of two complex numbers
Complex subtract(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real - num2.real;
    result.imag = num1.imag - num2.imag;
    if (isOverflow(result)) {
        return (Complex){-1, -1}; // Return an indicator of overflow
    }
    return result;
}

// Function to perform multiplication of two complex numbers
Complex multiply(Complex num1, Complex num2) {
    Complex result;
    result.real = (num1.real * num2.real) - (num1.imag * num2.imag);
    result.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
    if (isOverflow(result)) {
        return (Complex){-1, -1}; // Return an indicator of overflow
    }
    return result;
}

// Function to parse a complex number from a string
Complex parseComplex(char *str, int *index) {
    Complex num = {0, 0};
    int sign = 1;
    int i = *index;
    while (isdigit(str[i])) {
        num.real = num.real * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    if (str[i] == 'i') {
        num.imag = sign * 1;
        i++;
    }
    *index = i;
    return num;
}

// Function to evaluate the expression
Complex evaluate(char *expression) {
    Complex result = {0, 0};
    Complex operand1, operand2;
    int i = 0;
    int len = strlen(expression);
    while (i < len) {
        if (expression[i] == '(') {
            i++;
            operand1 = evaluate(&expression[i]);
            while (expression[i] != ')') {
                i++;
            }
            i++;
        } else {
            operand1 = parseComplex(expression, &i);
        }
        if (i < len) {
            if (expression[i] == '*') {
                i++;
                if (expression[i] == '(') {
                    i++;
                    operand2 = evaluate(&expression[i]);
                    while (expression[i] != ')') {
                        i++;
                    }
                    i++;
                } else {
                    operand2 = parseComplex(expression, &i);
                }
                result = multiply(operand1, operand2);
            } else if (expression[i] == '+' || expression[i] == '-') {
                i++;
                if (expression[i] == '(') {
                    i++;
                    operand2 = evaluate(&expression[i]);
                    while (expression[i] != ')') {
                        i++;
                    }
                    i++;
                } else {
                    operand2 = parseComplex(expression, &i);
                }
                if (expression[i - 1] == '+') {
                    result = add(result, operand2);
                } else {
                    result = subtract(result, operand2);
                }
            }
        }
        if (isOverflow(result)) {
            return (Complex){-1, -1}; // Return an indicator of overflow
        }
    }
    return result;
}

int main() {
    char expression[100];
    Complex result;
    while (scanf("%s", expression) != EOF) {
        result = evaluate(expression);
        if (isOverflow(result)) {
            printf("overflow\n");
        } else if (result.real == 0 && result.imag == 0) {
            printf("0\n");
        } else if (result.imag == 0) {
            printf("%d\n", result.real);
        } else if (result.real == 0) {
            printf("%di\n", result.imag);
        } else {
            printf("%d%di\n", result.real, result.imag);
        }
    }
    return 0;
}