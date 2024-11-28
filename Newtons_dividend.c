#include <stdio.h>

int main()
{
    double x[5] = {1.1,2.0,3.5,5,7.1};
    double y[5] = {0.6918,1.4715,2.1287,2.0521,1.4480};
    int i,j;
    double A[5],B[5],Fx[5];

    // for(i=0;i<5;i++)
    // {
    //     printf("X[%d] = %.3f \t Y[%d] = %.5f\n",i,x[i],i,y[i]);
    // }

    for(i=0;i<4;i++)
    {
        // A[i] = y[i+1]-y[i];
        // B[i] = x[i+1]-x[i];
        // Fx[i] = (A[i]/B[i]);
       Fx[i] = ((y[i+1]-y[i])/(x[i+1]-x[i]));
    }
    // for(i=0;i<4;i++)
    // {
    //     for(j=0;j<4;j++)
    //     { 
                              
    //     }
    // }
    
    for(i=0;i<4;i++)
    {
        printf("Fx[%d] = %.4lf \n",i,Fx[i]);
    }

    return 0;
}