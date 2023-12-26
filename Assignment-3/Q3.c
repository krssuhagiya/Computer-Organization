#include <stdio.h>

// Function to convert decimal to binary (2's complement)
void decimalToBinary(int n, int binary[32]) {
    int i;
    for (i = 0; i < 32; i++) {
        binary[i] = n % 2;
        n /= 2;
    }
}

// Function to perform 2's complement
void twosComplement(int binary[32]) {
    int carry = 1;

    for (int i = 0; i < 32; i++) {
        binary[i] = (binary[i] + carry) % 2;
        carry = (binary[i] + carry) / 2;
    }
}

// Function to add two binary numbers
void addBinary(int binary1[32], int binary2[32], int result[32]) {
    int carry = 0;

    for (int i = 0; i < 32; i++) {
        int sum = binary1[i] + binary2[i] + carry;
        result[i] = sum % 2;
        carry = sum / 2;
    }
}

// Function to print binary representation
void printBinary(int binary[32]) {
    int i;
    for (i = 31; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main() {
    int num1, num2;
    int binary1[32], binary2[32], result[32];

    // Input first number
    printf("Enter the first signed decimal number: ");
    scanf("%d", &num1);

    // Input second number
    printf("Enter the second signed decimal number: ");
    scanf("%d", &num2);

    // Convert decimal numbers to binary (2's complement)
    decimalToBinary(num1, binary1);
    decimalToBinary(num2, binary2);

    printf("Binary representation of %d: ", num1);
    printBinary(binary1);

    printf("Binary representation of %d: ", num2);
    printBinary(binary2);

    // Add the binary numbers
    addBinary(binary1, binary2, result);

    // Display the result
    printf("\nSum of %d and %d in binary: ", num1, num2);
    printBinary(result);

    return 0;
}
