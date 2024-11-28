#include <stdio.h>
#include <math.h>
// #define fx sqrt(1+x*x)
int main()
{
    float x0=1,xn=5;
    int i,a=0,k=4;
    float h = (xn-x0)/k;
    float xVar,fx;

    // printf("\n Value of h is %.3f \n",h);
    
    for(x0=-1;x0<=xn;x0=(x0+h))
    {
        if(x0==-1 || x0==xn)
        {
            xVar = x0;
            fx = a + sqrt(1+(xVar*xVar));
        }
        else{
		   fx = a + 2*sqrt(1+(xVar*xVar));
	    }
    }

    printf("Final value of fx is %f \n",fx);

    return 0;
}