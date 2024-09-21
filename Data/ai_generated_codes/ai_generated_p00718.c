#include <stdio.h>
#include <string.h>

// Function to calculate the MCXI-value of a given string
int calculate_mcxi_value(char *str) {
    int value = 0;
    int i = 0;
    int len = strlen(str);

    // Iterate through the string
    while (i < len) {
        // Check for prefix digits
        if (str[i] >= '2' && str[i] <= '9') {
            int prefix_digit = str[i] - '0';
            i++; // Move to the next character (letter)
            switch (str[i]) {
                case 'm':
                    value += prefix_digit * 1000;
                    break;
                case 'c':
                    value += prefix_digit * 100;
                    break;
                case 'x':
                    value += prefix_digit * 10;
                    break;
                case 'i':
                    value += prefix_digit * 1;
                    break;
            }
        } else { // No prefix digit, just a single letter
            switch (str[i]) {
                case 'm':
                    value += 1000;
                    break;
                case 'c':
                    value += 100;
                    break;
                case 'x':
                    value += 10;
                    break;
                case 'i':
                    value += 1;
                    break;
            }
        }
        i++;
    }

    return value;
}

// Function to generate an MCXI-string from a given integer
void generate_mcxi_string(int value, char *result) {
    int i = 0;

    // Calculate 'm' component
    if (value >= 1000) {
        int m_count = value / 1000;
        if (m_count > 9) {
            result[i++] = (m_count / 10) + '0';
        }
        result[i++] = (m_count % 10) + '0';
        result[i++] = 'm';
        value %= 1000;
    }

    // Calculate 'c' component
    if (value >= 100) {
        int c_count = value / 100;
        if (c_count > 9) {
            result[i++] = (c_count / 10) + '0';
        }
        result[i++] = (c_count % 10) + '0';
        result[i++] = 'c';
        value %= 100;
    }

    // Calculate 'x' component
    if (value >= 10) {
        int x_count = value / 10;
        if (x_count > 9) {
            result[i++] = (x_count / 10) + '0';
        }
        result[i++] = (x_count % 10) + '0';
        result[i++] = 'x';
        value %= 10;
    }

    // Calculate 'i' component
    if (value > 0) {
        if (value > 9) {
            result[i++] = (value / 10) + '0';
        }
        result[i++] = (value % 10) + '0';
        result[i++] = 'i';
    }

    result[i] = '\0'; // Terminate the string
}

int main() {
    int n;
    char str1[10], str2[10], result[10];

    scanf("%d", &n);

    // Process each input pair of MCXI-strings
    for (int i = 0; i < n; i++) {
        scanf("%s %s", str1, str2);
        int sum = calculate_mcxi_value(str1) + calculate_mcxi_value(str2);
        generate_mcxi_string(sum, result);
        printf("%s\n", result);
    }

    return 0;
}