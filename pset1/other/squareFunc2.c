#include<cs50.h>
#include<stdio.h>

int square(int n);

int main (void)
{
    int n = get_int("Gimmie an int please: ");
    printf("%i\n", square(n));
}

int square(int n)
{
    return n * n;
}
