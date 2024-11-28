#include <stdio.h>
#include <math.h>
// Trapezoidal :cls
int main()
{
    float x0=-1,xn=1;
    int i,a=0,k =4;
    float h = (xn-x0)/k;
    float xVar,fx;
    fx = pow(2.7182,xVar);
    

    // printf("\n Value of h is %.3f \n",h);
    
    for(x0=-1;x0<=xn;x0=(x0+h))
    {
        if(x0==-1 || x0==xn)
        {
            xVar = x0;
            fx = a + pow(2.7182,xVar);
        }
        else{
		   fx = a + 2*pow(2.7182,xVar);
	    }
    }

    printf("Final value of fx is %f \n",fx);

    return 0;
}