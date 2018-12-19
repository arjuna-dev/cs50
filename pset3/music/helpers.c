// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    char num1 = fraction[0];
    char num2 = fraction[2];

    num1 = num1 - '0';
    num2 = num2 - '0';

    float fractionToDecimal = (float)num1/(float)num2;
    float theDuration = fractionToDecimal/0.125;
    int theDurationInt = theDuration;
    return theDurationInt;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double freq;
    bool isLowerThanA = true;
    int n;

    char letter = note[0];
    char octave;

    //Get octave
    if(note[1]=='b'||note[1]=='#'){
        octave = note[2];
        octave = octave - '0';
    } else {
        octave = note[1];
        octave = octave - '0';
    }

    //Find frequency for A of the given octave
    if (octave>=4){
        freq = 440*(pow(2.00,octave-4.00));
        freq = round(freq);
        printf("The frequency as an integer for the given octave is %i\n",(int) freq);
    } else if (octave<4){
        freq = 440/(pow(2.00,4.00-octave));
        printf("The frequency as an integer for the given octave is %i\n",(int) freq);
    }

    //Find 'n' which is the number of semitones separating the given note from A

    if(letter=='A'){
        n=0;
        isLowerThanA = false;
    } else if(letter=='B'){
        n=2;
        isLowerThanA = false;
    } else if(letter=='C'){
        n=9;
        isLowerThanA = true;
    } else if(letter=='D'){
        n=7;
        isLowerThanA = true;
    } else if(letter=='E'){
        n=5;
        isLowerThanA = true;
    } else if(letter=='F'){
        n=4;
        isLowerThanA = true;
    } else if(letter=='G'){
        n=2;
        isLowerThanA = true;
    }

    //printf("n before sharp is %i",n);
    //Add or substract sharps and flats.
    if(note[1]=='b'&&isLowerThanA==true){
        n++;
    } else if(note[1]=='#'&&isLowerThanA==true){
        n--;
    } else if(note[1]=='b'&&isLowerThanA==false){
        n--;
    } else if(note[1]=='#'&&isLowerThanA==false){
        n++;
    }

    //printf("n after sharp is %i",n);

    if (isLowerThanA){
        freq = freq/pow(2.00,  (float)n/12.00);
    } else if (isLowerThanA==false){
        freq = freq*pow(2.00, (float)n/12.00);
    }

    int frequ = freq;

    return frequ;
}


// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strncmp(s,"",1)==0) {
        return true;
    } else {
        return false;
    }
}

// int main(void){
//     printf("%i",is_rest("asd"));
// }