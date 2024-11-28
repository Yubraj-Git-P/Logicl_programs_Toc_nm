#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char keyMatrix[5][5];
int visited[26] = {0};

// Function to create the key matrix
void createKeyMatrix(char *key) {
    int len = strlen(key);
    int k = 0;

    // Process the key
    for (int i = 0; i < len; i++) {
        if (isalpha(key[i]) && !visited[toupper(key[i]) - 'A']) {
            visited[toupper(key[i]) - 'A'] = 1;
            keyMatrix[k / 5][k % 5] = toupper(key[i]);
            k++;
        }
    }

    // Fill the rest of the matrix with the remaining letters
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!visited[ch - 'A'] && ch != 'J') {
            keyMatrix[k / 5][k % 5] = ch;
            k++;
        }
    }
}

// Function to print the key matrix
void printKeyMatrix() {
    printf("Key Matrix:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", keyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to prepare plaintext
void preparePlaintext(char *text, char *prepared) {
    int len = strlen(text);
    int k = 0;

    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            prepared[k++] = toupper(text[i]);
        }
    }

    // Insert 'X' between duplicate letters
    for (int i = 0; i < k; i++) {
        if (prepared[i] == prepared[i + 1]) {
            for (int j = k; j > i + 1; j--) {
                prepared[j + 1] = prepared[j];
            }
            prepared[i + 1] = 'X';
            k++;
        }
    }

    // Ensure even length
    if (k % 2 != 0) {
        prepared[k++] = 'X';
    }
    prepared[k] = '\0';
}

// Function to encrypt the plaintext
void encrypt(char *prepared) {
    char cipherText[MAX] = "";
    int len = strlen(prepared);

    for (int i = 0; i < len; i += 2) {
        int r1, r2, c1, c2;

        // Find positions of the two letters
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (keyMatrix[j][k] == prepared[i]) {
                    r1 = j;
                    c1 = k;
                }
                if (keyMatrix[j][k] == prepared[i + 1]) {
                    r2 = j;
                    c2 = k;
                }
            }
        }

        // Apply Playfair cipher rules
        if (r1 == r2) {
            cipherText[i] = keyMatrix[r1][(c1 + 1) % 5];
            cipherText[i + 1] = keyMatrix[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            cipherText[i] = keyMatrix[(r1 + 1) % 5][c1];
            cipherText[i + 1] = keyMatrix[(r2 + 1) % 5][c2];
        } else {
            cipherText[i] = keyMatrix[r1][c2];
            cipherText[i + 1] = keyMatrix[r2][c1];
        }
    }
    cipherText[len] = '\0';
    printf("Ciphertext: %s\n", cipherText);
}

int main() {
    char key[MAX], text[MAX], prepared[MAX];

    printf("Enter the key: ");
    fgets(key, MAX, stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline

    createKeyMatrix(key);
    printKeyMatrix();

    printf("Enter the plaintext: ");
    fgets(text, MAX, stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline

    preparePlaintext(text, prepared);
    encrypt(prepared);

    return 0;
}
