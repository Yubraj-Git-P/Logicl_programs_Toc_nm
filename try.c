#include <stdio.h>
int factorial(int a);
// int minus(int b,int ss);
int minus(int b, int ss);
int main()
{
    // int x[5] = {10, 20, 30, 40, 50};
    // float y[5] = {0.1736, 0.3420, 0.5000, 0.6428, 0.7660};

    float x[5] = {1.1,2.0,3.5,5,7.1};
    float y[5] = {0.6981,1.4715,2.1287,2.0521,1.4480};


    int i, j, k, X = 1.75; //X = 25
    float h = (x[1] - x[0]);
    float s = (X - x[0]) / h;
    float A, Y[5], YY[5], YYY[5], YYYY[5], DeltaY[5], Fx;
    

       int n = 4;
    // Y[j] = y[j+1] - y[j];

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
                    printf("DeltaY[%d] = %f\n", i, DeltaY[i]);
                }
            }

            else if (i == 1)
            {
                YY[j] = Y[j + 1] - Y[j];
                printf("%f\n", YY[j]);
                if (j == 0)
                {
                    DeltaY[i] = YY[j];
                    printf("DeltaY[%d] = %f\n", i, DeltaY[i]);
                }
            }

            else if (i == 2)
            {
                YYY[j] = YY[j + 1] - YY[j];
                printf("%f\n", YYY[j]);
                if (j == 0)
                {
                    DeltaY[i] = YYY[j];
                    printf("DeltaY[%d] = %f\n", i, DeltaY[i]);
                }
            }

            else if (i == 3)
            {
                YYYY[j] = YYY[j + 1] - YYY[j];
                printf("%f\n", YYYY[j]);
                if (j == 0)
                {
                    DeltaY[i] = YYYY[j];
                    printf("DeltaY[%d] = %f\n", i, DeltaY[i]);
                }
            }
        }
        printf("\n\n");
    }

     for(i=0;i<4;i++)
    {
        printf("\nDeltaY[%d] = %f \n",(i+1),DeltaY[i]);
    }

    // formula calculation part :

    Fx = y[0] + s * DeltaY[1];

    for (i = 1; i < 5; i++)
    {
        Fx = Fx + (s * minus(i, s) / factorial(i)) * DeltaY[i + 1];
    }

    printf("\n\n\nNewtons Forward interpolation is %f \n",Fx);

    return 0;
}

int factorial(int a)
{
    if (a == 1)
        return 1;
    return a * factorial(a - 1);
}

int minus(int b, int ss)
{
    int subs = 1, i;

    for (i = 1; i <= b; i++)
    {
        subs = subs * (ss - i);
    }
    return subs;
}
