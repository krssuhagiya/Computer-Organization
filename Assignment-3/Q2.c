#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(unsigned int n, int binary[32]) {
    int i;
    for (i = 0; i < 32; i++) {
        binary[i] = n % 2;
        n /= 2;
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
    unsigned int num1, num2;
    int binary1[32], binary2[32], result[32];

    // Input first number
    printf("Enter the first unsigned decimal number: ");
    scanf("%u", &num1);

    // Input second number
    printf("Enter the second unsigned decimal number: ");
    scanf("%u", &num2);

    // Convert decimal numbers to binary
    decimalToBinary(num1, binary1);
    decimalToBinary(num2, binary2);

    printf("Binary representation of %u: ", num1);
    printBinary(binary1);

    printf("Binary representation of %u: ", num2);
    printBinary(binary2);

    // Add the binary numbers
    addBinary(binary1, binary2, result);

    // Display the result
    printf("\nSum of %u and %u in binary: ", num1, num2);
    printBinary(result);

    return 0;
}
