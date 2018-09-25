#include <cs50.h>
#include <stdio.h>


int main(void)
{
    float n;

    do
    {
        n = get_float("How much change do I owe you? ");
    }
    while (n<0);

    float cent = 0.01;
    float nickel = 0.05;
    float dime = 0.1;
    float quarter = 0.25;
    int numberOfCoins = 0;

    while (n>=quarter)
    {
        numberOfCoins++;
        n = n - quarter;
    }
    while (n>=dime)
    {
        numberOfCoins++;
        n = n - dime;
    }
    while (n>=nickel)
    {
        numberOfCoins++;
        n = n - nickel;
    }
    while (n>=cent)
    {
        numberOfCoins++;
        n = n - cent;
    }

    printf("%i\n", numberOfCoins);
}