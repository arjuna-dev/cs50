#include <cs50.h>
#include <stdio.h>
#include <string.h>

int encrypt(aChar, aALeterValue, n){
    aChar = aChar - aALeterValue + n;
    aChar = aChar%26;
    aChar = aChar+aALeterValue;
    return aChar;
}

int main(int argc, string argv[])
{
    if (argc==2){
        int n = strtol(argv[1], NULL, 10);
        string s = get_string("plaintext:");

        n = n%26;

        printf("ciphertext:");
        //Iterate through the characters of the string.
        for(int i=0, strl=strlen(s); i<strl; i++){
            //Check if letter is capitalized (substract 65)
            if (s[i]<91&&s[i]>64){
                printf("%c", encrypt(s[i],65,n));
            //Check if letter is capitalized (substract 97)
            } else if (s[i]>96&&s[i]<123){
                printf("%c", encrypt(s[i],97,n));
            }
        }
            printf("\n");
    } else {
        printf("ERROR: Please enter exactly two arguments\n");
        return 1;
    }
}