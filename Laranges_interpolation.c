#include <stdio.h>
// Lagrange interpolation : 
int main()
{
   int x[4] = {5,6,9,11};
   int y[4] = {12,13,14,16};
   int X=10;
   float A=1,B=1,C=0;

   for(int i=0;i<4;i++)
   {
       printf("%d\t %d\t \n",x[i],y[i]);
   }

   for(int i=0;i<4;i++)   // i = 2  
   {
      for(int j=0;j<4;j++) // j = 0   
      {
          if(j!=i)
          {
            A=A*(X-x[j]);
            B=B*(x[i]-x[j]);
          }          
      }
      C = C + (A/B)*y[i];
        // printf("%f\n",C);
      A=1,B=1;
   }    
   printf("\n\n%f\n",C);

    return 0;
}