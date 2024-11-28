#include <iostream>
# include <cmath> 
#include<cstring>// Use <cmath> instead of <math.h> for C++ standard compliance
using namespace std;

float en[3][1], de[3][1], a[3][3], b[3][3], msg[3][1], m[3][3];

void getKeyMatrix() { 
    int i, j;
    char mes[4]; // Increased size to allow null terminator
    cout << "Enter 3x3 matrix for key (should have inverse):\n";
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            cin >> a[i][j];
            m[i][j] = a[i][j]; // Preserve original matrix for inversion
        }
    cout << "\nEnter a string of 3 letters (use A through Z): ";
    cin >> mes;
    if (strlen(mes) != 3) { // Check for exactly 3 letters
        cout << "Error: Please enter exactly 3 letters.\n";
        exit(1);
    }
    for (i = 0; i < 3; i++)
        msg[i][0] = mes[i] - 'A'; // 'A' is 65, simplifying to just subtract 'A'
}

void encrypt() { 
    int i, j, k;
    // Initialize encrypted message matrix to zero
    for (i = 0; i < 3; i++) en[i][0] = 0;
    
    for (i = 0; i < 3; i++)
        for (j = 0; j < 1; j++)
            for (k = 0; k < 3; k++)
                en[i][j] += a[i][k] * msg[k][j];
    
    cout << "\nEncrypted string is: ";
    for (i = 0; i < 3; i++)
        cout << (char)(fmod(en[i][0], 26) + 'A'); // Use 'A' for character mapping
}

void inversematrix() { 
    int i, j, k;
    float p, q;
    
    // Initialize identity matrix
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            b[i][j] = (i == j) ? 1 : 0;
    
    for (k = 0; k < 3; k++) {
        float diag = m[k][k];
        for (j = 0; j < 3; j++) {
            m[k][j] /= diag; // Normalize the pivot row
            b[k][j] /= diag; // Normalize the identity row
        }
        for (i = 0; i < 3; i++) {
            if (i != k) {
        }
    }

    cout << "\n\nInverse Matrix is:\n";
                p = m[i][k];
                for (j = 0; j < 3; j++) {
                    m[i][j] -= p * m[k][j]; // Eliminate column
                    b[i][j] -= p * b[k][j]; // Update identity matrix
                }
            }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            cout << b[i][j] << " ";
        cout << "\n";
    }
}

void decrypt() { 
    int i, j, k;
    // Initialize decrypted message matrix to zero
    for (i = 0; i < 3; i++) de[i][0] = 0;
    
    inversematrix();
    for (i = 0; i < 3; i++)
        for (j = 0; j < 1; j++)
            for (k = 0; k < 3; k++)
                de[i][j] += b[i][k] * en[k][j];
    
    cout << "\nDecrypted string is: ";
    for (i = 0; i < 3; i++)
        cout << (char)(fmod(de[i][0], 26) + 'A'); // Use 'A' for character mapping
    cout << "\n";
}

int main() {
    getKeyMatrix();
    encrypt();
    decrypt();
