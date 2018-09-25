#include<cs50.h>
#include<stdio.h>

int main (void)
{
    // char * name = get_string("What is your name?");
    int a = get_int("Get me a number man: ");
    int b = get_int("Get me another number man: ");
    printf("Hi. The sum is %i\n",  a + b);
}