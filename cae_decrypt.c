#include <stdio.h>

// Function to decrypt a message using Caesar cipher
void decrypt(char message[], int shift) {
    char ch;
    int i;

    // Iterate through each character in the message
    for(i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        // Decrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z')
            ch = 'Z' - ('Z' - ch + shift) % 26;

        // Decrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z')
            ch = 'z' - ('z' - ch + shift) % 26;

        // Update the character in the message
        message[i] = ch;
    }
}

int main() {
    char message[100];
    int shift;

    // Input message from user
    printf("Enter a message to decrypt: ");
    fgets(message, sizeof(message), stdin);

    // Input shift value from user
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    // Validate shift value (make sure it's between 1 and 25)
    if (shift < 1 || shift > 25) {
        printf("Shift amount must be between 1 and 25.\n");
        return 1;  // Exit program with error code
    }

    // Decrypt the message
    decrypt(message, shift);

    // Output the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}

