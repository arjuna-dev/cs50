#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int n;
    char h = '#';
    char s = ' ';


    do
    {
        n = get_int("How tall should your stairs be? ");
    }
    while (n>24 || n<0 || n==0);

    int spaces = n-2;
    int hashes = 2;

    // Loop for levels
    for (int i=0; i<n; i++)
    {
        //Loop for spaces
        for (int j=spaces+1; j>0; j--)
        {
        printf("%c", s);
        }
        //Loop for hashes
        for (int k=n-hashes; k<n; k++)
        {
        printf("%c", h);
        }
    printf("\n");
    spaces--;
    hashes++;
    }

}