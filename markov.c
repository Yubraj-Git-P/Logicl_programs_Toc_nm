#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STATES 3

// Transition probability matrix
double transitionMatrix[NUM_STATES][NUM_STATES] = {
    {0.1, 0.6, 0.3},
    {0.4, 0.4, 0.2},
    {0.3, 0.3, 0.4}
};

// Function to choose the next state based on current state
int nextState(int currentState) {
    double r = (double)rand() / RAND_MAX;
    double sum = 0.0;
    
    for (int i = 0; i < NUM_STATES; i++) {
        sum += transitionMatrix[currentState][i];
        if (r <= sum) {
            return i;
        }
    }
    
    return NUM_STATES - 1; // should not reach here if probabilities are correctly normalized
}

int main() {
    int currentState = 0; // Initial state
    int numSteps = 100;   // Number of steps in the simulation
    
    srand(time(NULL)); // Seed the random number generator
    
    printf("Initial State: %d\n", currentState);
    
    for (int i = 0; i < numSteps; i++) {
        currentState = nextState(currentState);
        printf("Step %d: State %d\n", i + 1, currentState);
    }
    
    return 0;
}




















// C Program to generate Pseudo-random numbers
// using Linear Congruential Generator.

#include<stdio.h>

void main()
{
    int xi=27;
    int a=17;
    int c=43;
    int m=100;
    int RandNum[m];

    printf("The random numbers are: \n");

    for (int i=0; i<m; i++)
    {
        RandNum[i]= (a*xi+c)%m;
        xi=RandNum[i];
        printf("%d \n",RandNum[i]);
        if (i==0)
            continue;
        if (RandNum[i]==RandNum[0])
        {
            printf("now the pattern repeats..");
            break;
        }
    }
}














