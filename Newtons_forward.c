#include <stdio.h>
// Newtons forward
int main()
{
    int x[5] = {10, 20, 30, 40, 50};
    float y[5] = {0.1736, 0.3420, 0.5000, 0.6428, 0.7660};
    int i, j, k, X = 25;
    float h = (x[1] - x[0]);
    float s = (X - x[0]) / h;
    float A, Y[5], YY[5], YYY[5], YYYY[5], DeltaY[5];

    for(i=0;i<5;i++)
    {
        printf("%d\t %f\t\n",x[i],y[i]);
    }

    for(i=0;i<4;i++)
    {
    Y[i] = y[i+1]-y[i];
    printf("%f\n",Y[i]);
    }

    printf("\n\n");
    for(i=0;i<3;i++)
    {
    YY[i] = Y[i+1]-Y[i];
    printf("%f\n",YY[i]);
    }

    printf("\n\n");
    for(i=0;i<2;i++)
    {
    YYY[i] = YY[i+1]-YY[i];
    printf("%f\n",YYY[i]);
    }

    printf("\n\n");
    for(i=0;i<1;i++)
    {
    YYYY[i] = YYY[i+1]-YYY[i];
    printf("%f\n",YYYY[i]);
    }

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

    // for(i=0;i<4;i++)
    // {
    //     printf("DeltaY[%d] = %f \n",(i+1),DeltaY[i]);
    // }

    return 0;
}