#define _GNU_SOURCE
#include <crypt.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    bool containsOnlyLetters = true;
    for(int i=0, strlo=strlen(argv[1]); i<strlo; i++){
        if (isalpha(argv[1][i])==false){
            containsOnlyLetters = false;
        }
    }


    if (argc==2&&containsOnlyLetters){

        string key = argv[1];
        //Sample hash: 50xcIMJ0y.RXo

        printf("%s\n", crypt(key,"50"));
        char justAString[5] = {'A',' ','A','B','\0'};

        printf("%s", justAString);
        return 0;

    } else {
        printf("Smthn went wrong... Please exactly only one alphabetical argument after writing ./vinagere. Thanks.\n");
        return 1;
    }
}