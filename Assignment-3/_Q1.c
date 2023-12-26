#include<stdio.h>
#include <stdlib.h>

int decimalToBinary(int decimalNumber) {
    int reminder, binaryNumber = 0, i = 1;
    while (decimalNumber != 0) {
        reminder = decimalNumber % 2;
        decimalNumber /= 2;
        binaryNumber += reminder * i;
        i *= 10;
    }
    return binaryNumber ;
}

int countDigits(int num) {
    // Ensure non-negative input
    if (num < 0) {
        printf("Please enter a non-negative integer.\n");
        return -1; // Error code for invalid input
    }

    // Initialize digit count to 0
    int digitCount = 0;

    // Handle the case when the number is 0 separately
    if (num == 0) {
        digitCount = 1;
    } else {
        // Count the number of digits
        while (num != 0) {
            num /= 10;
            ++digitCount;
        }
    }

    return digitCount;
}

int* convertToDigitArray(int num, int *size) {
    // Ensure non-negative input
    if (num < 0) {
        printf("Please enter a non-negative integer.\n");
        *size = -1; // Error code for invalid input
        return NULL;
    }

    // Initialize variables
    int tempNum = num;
    int count = 0;

    // Count the number of digits
    while (tempNum != 0) {
        tempNum /= 10;
        ++count;
    }

    // Update the size of the array
    *size = count;

    // Allocate memory for the array dynamically
    int* digitArray = (int*)malloc(count * sizeof(int));

    // Extract digits and store them in the array
    for (int i = count - 1; i >= 0; --i) {
        digitArray[i] = num % 10;
        num /= 10;
    }

    return digitArray;
}

void findMaxDigitSize()


int main() {
    int decimalNumber1, decimalNumber2;
    printf("Enter Number 1 : ");
    scanf("%d", &decimalNumber1);
    printf("Enter Number 2 : ");
    scanf("%d", &decimalNumber2);

    int binaryNumber1 = decimalToBinary(decimalNumber1);
    int binaryNumber2 = decimalToBinary(decimalNumber2);

    printf("Binary Number 1 : %d\n", binaryNumber1);
    printf("Binary Number 2 : %d", binaryNumber2);



    return 0;
}
