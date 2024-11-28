#include <stdio.h>
#include <math.h>
// #define fx sqrt(1-x*x)

// simsons 1/8
int main()
{
    float x0 = 0, xn = 3, x;
    int k = 9, i = 0,a=x0;
    float h = (xn - x0) / k,fx=0,interval;

    printf("Value for k is %f \n", h);

    // for Composite simsons 3/8_th rule...

    for (x0 = 0; x0 <= xn; x0 = (a + i * h))
    {
        if (x0 == 0 || x0 == xn) // x0 amd xn
        {
            x = x0;
            fx = fx + (1/(x+4));
            printf("%f\n", fx);
        }
        else
        { // x1 to xn-1

            if ((i % 3) == 0)
            {
                x = x0;
                fx = fx + 2* (1/(x+4)) ;
                printf("%f\n", fx);
            }
            else
            {
                x = x0;
                fx = fx + 3 * (1/(x+4)) ;
                printf("%f\n", fx);
            }
        }
        i++;
    }
    
    interval = 0.375*h;
    
    printf("value of interval is %f\n",interval);
    fx = interval*fx;

    printf("Hence final value is %f \n", fx);

    return 0;
}
