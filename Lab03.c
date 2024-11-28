#include<stdio.h>
#include<string.h>
// Multiline comment : 
int main()
{
    char str[100],A,B,C,D,E,F;
    char current_state='A';
    int i=0,n; 

    printf("Enter the String: \n");
    scanf("%[^\n]s", &str);  /* My name is Pthon */

    while(str[i]!='\0')
    {
        switch(current_state)
        {
            case 'A':

                if(str[i]=='/')
                {
                    current_state = 'B';
                } 
                else{
                    current_state = 'F';
                }
                break;

            case 'B':

                if(str[i]=='*')
                {
                    current_state = 'C';
                }
                else{
                    current_state = 'F';
                }
                break;

            case 'C':
                
                if(str[i]=='*')
                {
                    current_state = 'D';
                }
                else{
                    current_state = 'C';
                }
                break;

            case 'D':

                if(str[i]=='*')
                {
                    current_state = 'D';
                }
                else if(str[i]=='/')
                {
                    current_state = 'E';
                    break;
                }

                else{
                    current_state = 'C';
                }
                break;
                
            case 'E':

                current_state = 'F';              
                break;
        }
        i++;
    }

    if(current_state == 'E')
    {
        printf("Given Input is a Multi-line comment ");
    }
    else{
        printf("Given Input is not a Multi-line comment ");
    }

    return 0;
}    