#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(unsigned int n, int binary[32], int size) {
    int i;
    size=0;
    for (i = 0; i < 32; i++) {
        binary[i] = n % 2;
        n /= 2;
        size=size+1;
    }
}

// Function to find the index of the most significant bit that is set to 1
int findMostSignificantBit(int binary[32]) {
    int i;
    for (i = 31; i >= 0; i--) {
        if (binary[i] == 1) {
            return i;
        }
    }
    return -1;  // If the number is 0, return -1
}

// Function to print binary representation without leading zeros
void printBinary(int binary[32]) {
    int i = findMostSignificantBit(binary);

    // If the number is 0, print a single 0
    if (i == -1) {
        printf("0");
    } else {
        for (; i >= 0; i--) {
            printf("%d", binary[i]);
        }
    }

    printf("\n");
}

int main() {
    unsigned int num1, num2,a,b,max;
    int binary1[32], binary2[32];

    // Input first number
    printf("Enter the first unsigned decimal number: ");
    scanf("%u", &num1);

    // Input second number
    printf("Enter the second unsigned decimal number: ");
    scanf("%u", &num2);

    // Convert decimal numbers to binary
    decimalToBinary(num1, binary1,a);
    decimalToBinary(num2, binary2,b);
    if(a>b){
        max=a;
    }
    else if(a<b || a==b){
        max=b;
    }

    printf("Binary representation of %u: ", num1);
    printBinary(binary1);

    printf("Binary representation of %u: ", num2);
    printBinary(binary2);

    // Bitwise AND
    printf("\nBitwise AND: ");
    for (int i = max; i >= 0; i--) {
        
        printf("%d", binary1[i] & binary2[i]);
    }

    // Bitwise OR
    printf("\nBitwise OR: ");
    for (int i = max; i >= 0; i--) {
        printf("%d", binary1[i] | binary2[i]);
    }

    // Bitwise XOR
    printf("\nBitwise XOR: ");
    for (int i = max; i >= 0; i--) {
        printf("%d", binary1[i] ^ binary2[i]);
    }

    // Bitwise XNOR
    printf("\nBitwise XNOR: ");
    for (int i = max; i >= 0; i--) {
        printf("%d", !(binary1[i] ^ binary2[i]));
    }

    // Bitwise Complement
    printf("\nBitwise Complement of %u: ", num1);
    for (int i = max; i >= 0; i--) {
        printf("%d", !binary1[i]);
    }
    printf("\n");

    return 0;
}
