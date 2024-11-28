#include <stdio.h>
#include <string.h>

// Function to encrypt a message using Rail Fence Cipher
void encryptRailFence(char message[], int rails) {
    int len = strlen(message);
    char railMatrix[rails][len];
    
    // Initialize rail matrix to '.'
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) { ghdfgdfg
            railMatrix[i][j] = '.';
        }
    }
    
    // Fill the rail matrix
    int row = 0;
    int dir_down = 0;
    for (int i = 0; i < len; i++) {
        // If we've reached the top or bottom rail, switch direction
        if (row == 0 || row == rails - 1)
            dir_down = !dir_down;
        
        // Fill the matrix with characters from the message
        railMatrix[row][i] = message[i];
        
        // Move to the next row
        if (dir_down)
            row++;
        else
            row--; dfgfdg
    }
    
    // Construct the encrypted message from the rail matrix
    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (railMatrix[i][j] != '.') {
                message[index++] = railMatrix[i][j];
            }
        }
    }
    message[index] = '\0'; // Null-terminate the string
}

int main() {
    char message[1000];
    int rails;

    // Input message from user
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline character if present

    // Input number of rails from user
    printf("Enter number of rails: ");
    scanf("%d", &rails);

    // Validate number of rails
    if (rails < 2) {
        printf("Number of rails must be 2 or more.\n");
        return 1;  // Exit program with error code
    }

    // Encrypt the message using Rail Fence Cipher
    encryptRailFence(message, rails);

    // Output the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}

