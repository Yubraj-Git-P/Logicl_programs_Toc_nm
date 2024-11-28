#include <stdio.h>
#include <math.h>
// #define fx sqrt(1-x*x)

// simsons 1/3

int main()
{
    float x0 = 0, xn = 1, x;
    int k = 8, i = 0,a=x0;
    float h = (xn - x0) / k,fx=0;

    printf("Value for k is %f \n", h);

    // for Composite simsons 1/3_th rule...

    for (x0 = 0; x0 <= xn; x0 = (a + i * h))
    {
        if (x0 == 0 || x0 == xn) // x0 amd xn
        {
            x = x0;
            fx = fx + sqrt(1 - x * x);
            printf("%f\n", fx);
        }
        else
        { // x1 to xn-1

            if ((i % 2) == 0)
            {
                x = x0;
                fx = fx + 2 * sqrt(1 - (x * x));
                printf("%f\n", fx);
            }
            else
            {
                x = x0;
                fx = fx + 4 * sqrt(1 - (x * x));
                printf("%f\n", fx);
            }
        }
        i++;
    }

    fx=(h/3)*fx;

    printf("Hence final value is %f \n", fx);

    return 0;
}
