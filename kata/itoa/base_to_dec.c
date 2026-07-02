#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function to convert a character symbol to its decimal value
int symbolToValue(char c) {
    if (isdigit(c)) {
        return c - '0'; // '0'-'9' -> 0-9
    }
    return toupper(c) - 'A' + 10; // 'A'-'Z' -> 10-35
}

// Function to convert a positional number string to Base 10
long long toDecimal(char *numStr, int base) {
    int len = strlen(numStr);
    long long decimalValue = 0;
    long long power = 1; // Represents base^0 initially

    // Walk through the string from right to left
    for (int i = len - 1; i >= 0; i--) {
        int digitValue = symbolToValue(numStr[i]);

        // Validate that the digit is legal for the given base
        if (digitValue < 0 || digitValue >= base) {
            printf("Error: Invalid character '%c' for Base %d\n", numStr[i], base);
            return -1;
        }

        // Add the positional value to the total
        decimalValue += digitValue * power;
        
        // Move to the next power of the base
        power *= base;
    }

    return decimalValue;
}

int main() {
    char numStr[64];
    int base;

    printf("Enter the number string (e.g., 2B5, 1101): ");
    scanf("%s", numStr);

    printf("Enter the base of the number (2-36): ");
    scanf("%d", &base);

    if (base < 2 || base > 36) {
        printf("Base must be between 2 and 36.\n");
        return 1;
    }

    long long result = toDecimal(numStr, base);

    if (result != -1) {
        printf("The decimal (Base 10) equivalent of %s in Base %d is: %lld\n", numStr, base, result);
    }

    return 0;
}
