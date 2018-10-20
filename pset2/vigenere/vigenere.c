#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int normalizeChar0to26(aChar){
    if (isupper(aChar)){
        aChar=aChar-65;
    } else if (islower(aChar)){
        aChar=aChar-97;
    }
    return aChar;
}

int denormalizeChar(aChar){
    if (isupper(aChar)){
        aChar=aChar+65;
    } else if (islower(aChar)){
        aChar=aChar+97;
    }
    return aChar;
}

int encrypt(aChar,numToAdd){
    char newChar;
    newChar=normalizeChar0to26(aChar);
    newChar=newChar+numToAdd;
    newChar=newChar%26;
    newChar=denormalizeChar(newChar);
    printf("%c", newChar);
    return newChar;
}



int main(int argc, string argv[])
{
    bool containsOnlyLetters = true;
    for(int i=0, strlo=strlen(argv[1]); i<strlo; i++){
        if (isalpha(argv[1][i])==false){
            containsOnlyLetters = false;
        }
    }


    if (argc==2&&containsOnlyLetters){


        string s = get_string("plaintext:");
        string key = argv[1];
        printf("ciphertext:");
        int keyChar;

        //Iterate through the characters of the string.
        for(int i=0, strl=strlen(s); i<strl; i++){
            int j = i%(int)strlen(key);

            // int numToAdd = normalizeChar0to26(key[j]);
            // encrypt(s[i],numToAdd);
            //printf("%c", encrypt(s[i],numToAdd))



            if (isupper(key[j])){
                keyChar=key[j]-65;
            } else if (islower(key[j])){
                keyChar=key[j]-97;
            }

            if (isupper(s[i])){
                s[i]=s[i]-65;
                s[i]=s[i]+keyChar;
                s[i]=s[i]%26;
                s[i]=s[i]+65;
                printf("%c", s[i]);
            } else if (islower(s[i])){
                s[i]=s[i]-97;
                s[i]= s[i]+keyChar;
                s[i]=s[i]%26;
                s[i]=s[i]+97;
                printf("%c", s[i]);
            }
        }
            printf("\n");
        return 0;
    } else {
        printf("Smthn went wrong... Please exactly only one alphabetical argument after writing ./vinagere. Thanks.\n");
        return 1;
    }
}