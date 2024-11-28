#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to generate random numbers
void generateRandomNumbers(int numbers[], int count, int digitCount) {
    int lower = pow(10, digitCount - 1);
    int upper = pow(10, digitCount) - 1;

    for (int i = 0; i < count; i++) {
        numbers[i] = lower + rand() % (upper - lower + 1);
    }
}

// Function to count patterns in 3-digit numbers
void countPatterns3Digit(int numbers[], int count, int *aaa, int *aab, int *abc) {
    for (int i = 0; i < count; i++) {
        int digits[3] = {numbers[i] / 100, (numbers[i] / 10) % 10, numbers[i] % 10};
        if (digits[0] == digits[1] && digits[1] == digits[2]) {
            (*aaa)++;
        } else if (digits[0] == digits[1] || digits[1] == digits[2] || digits[0] == digits[2]) {
            (*aab)++;
        } else {
            (*abc)++;
        }
    }
}

// Function to count patterns in 4-digit numbers
void countPatterns4Digit(int numbers[], int count, int *aaaa, int *aaab, int *aabb, int *aabc, int *abcd) {
    for (int i = 0; i < count; i++) {
        int digits[4] = {numbers[i] / 1000, (numbers[i] / 100) % 10, (numbers[i] / 10) % 10, numbers[i] % 10};
        int digitCount[10] = {0};
        for (int j = 0; j < 4; j++) {
            digitCount[digits[j]]++;
        }
        int maxCount = 0;
        for (int j = 0; j < 10; j++) {
            if (digitCount[j] > maxCount) {
                maxCount = digitCount[j];
            }
        }
        if (maxCount == 4) {
            (*aaaa)++;
        } else if (maxCount == 3) {
            (*aaab)++;
        } else if (maxCount == 2) {
            int pairs = 0;
            for (int j = 0; j < 10; j++) {
                if (digitCount[j] == 2) {
                    pairs++;
                }
            }
            if (pairs == 2) {
                (*aabb)++;
            } else {
                (*aabc)++;
            }
        } else {
            (*abcd)++;
        }
    }
}

// Function to perform chi-squared test
double chiSquaredTest(int observed[], double expected[], int size) {
    double chiSquared = 0.0;
    for (int i = 0; i < size; i++) {
        chiSquared += (observed[i] - expected[i]) * (observed[i] - expected[i]) / expected[i];
    }
    return chiSquared;
}

int main() {
    srand(time(0)); // Seed the random number generator

    // Parameters
    int count = 10000; // Number of random numbers to generate
    int digitCount = 3; // Number of digits (3 or 4)

    // Generate random numbers
    int numbers[count];
    generateRandomNumbers(numbers, count, digitCount);

    // Expected patterns
    double expected3Digit[] = {count * 0.001, count * 0.027, count * 0.972};
    double expected4Digit[] = {count * 0.0001, count * 0.0036, count * 0.0090, count * 0.0720, count * 0.9153};

    if (digitCount == 3) {
        int observed3Digit[3] = {0, 0, 0};
        countPatterns3Digit(numbers, count, &observed3Digit[0], &observed3Digit[1], &observed3Digit[2]);
        double chiSquared = chiSquaredTest(observed3Digit, expected3Digit, 3);
        printf("Chi-squared statistic for 3-digit numbers: %f\n", chiSquared);
    } else if (digitCount == 4) {
        int observed4Digit[5] = {0, 0, 0, 0, 0};
        countPatterns4Digit(numbers, count, &observed4Digit[0], &observed4Digit[1], &observed4Digit[2], &observed4Digit[3], &observed4Digit[4]);
        double chiSquared = chiSquaredTest(observed4Digit, expected4Digit, 5);
        printf("Chi-squared statistic for 4-digit numbers: %f\n", chiSquared);
    } else {
        fprintf(stderr, "Invalid digit count!\n");
    }

    return 0;
}

