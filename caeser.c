#include <stdio.h>

// Function to encrypt a message using Caesar cipher
void encrypt(char message[], int shift) {
    char ch;
    int i;

    // Iterate through each character in the message
    for(i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        // Encrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z')
            ch = 'A' + (ch - 'A' + shift) % 26;

        // Encrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z')
            ch = 'a' + (ch - 'a' + shift) % 26;

        // Update the character in the message
        message[i] = ch;
    }
}

int main() {
    char message[100];
    int shift;

    // Input message from user
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // Input shift value from user
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    // Validate shift value (make sure it's between 1 and 25)
    if (shift < 1 || shift > 25) {
        printf("Shift amount must be between 1 and 25.\n");
        return 1;  // Exit program with error code
    }

    // Encrypt the message
    encrypt(message, shift);

    // Output the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}

