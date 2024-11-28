#include <stdio.h>
int factorial(int x);
int main()
{
    int num,fact;

    printf("Enter Num : ");
    scanf("%d",&num);

    fact = factorial(num);
    printf("Factorial of %d is %d\n",num,fact); 

    return 0;
}

int factorial(int x)
{
    if(x==1)
    return 1;
    return x*factorial(x-1);
}

int factorial(int x)
{
    if(x==1)
    return 1;
    return x*factorial(x-1);
}


    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < (n - i); j++)
        {

            if (i == 0)
            {
                Y[j] = y[j + 1] - y[j];
                printf("%f\n", Y[j]);
                if (j == 0)
                {
                    DeltaY[i] = Y[j];
                    printf("DeltaY[%d] = %f\n", i, DeltaY[i]); // DeltaY[1]
                }
            }

            else if (i == 1)
            {
                YY[j] = Y[j + 1] - Y[j];
                printf("%f\n", YY[j]);
                if (j == 0)
                {
                    DeltaY[i] = YY[j];
                    printf("DeltaY[%d] = %f\n", i, DeltaY[i]); // DeltaY[2]
                }
            }

            else if (i == 2)
            {
                YYY[j] = YY[j + 1] - YY[j];
                printf("%f\n", YYY[j]);
                if (j == 0)
                {
                    DeltaY[i] = YYY[j];
                    printf("DeltaY[%d] = %f\n", i, DeltaY[i]); // DeltaY[3]
                }
            }

            else if (i == 3)
            {
                YYYY[j] = YYY[j + 1] - YYY[j];
                printf("%f\n", YYYY[j]);
                if (j == 0)
                {
                    DeltaY[i] = YYYY[j];
                    printf("DeltaY[%d] = %f\n", i, DeltaY[i]); // DeltaY[4]
                }
            }
        }
        printf("\n\n");
    }
