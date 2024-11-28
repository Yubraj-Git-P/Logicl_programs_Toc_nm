#include <stdio.h>

int main()
{
    int x[3];
    int y[3];
    int X=1,i;

    printf("Enter values for x[3] : \n");
    for(i=0;i<=3;i++)
    {
        scanf("%d",&x[i]);
    }

    printf("Enter values for y[3] : \n");
    for(i=0;i<=3;i++)
    {
        scanf("%d",&y[i]);
    }

    for(i=0;i<=3;i++)
    {   
        printf("%d\t",x[i]);
    }

    for(i=0;i<=3;i++)
    {   
        printf("%d\t",y[i]);
    }

    return 0;
}