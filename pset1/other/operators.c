#include<cs50.h>
#include<stdio.h>

int main (void)
{
    char c = get_char("Answer: ");

    if (c=='a' || c=='A')
    {
        printf("A bro!");
    }
    else if (c=='b' || c=='B')
    {
        printf("B bro!");
    }
}