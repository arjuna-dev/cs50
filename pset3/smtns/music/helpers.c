//Writing notes taking A_G as first character is wrong, should be !-~


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
    int n;

    char sign = note[0];
    char octave;

    //Get octave
    octave = note[1];
    octave = octave - '0';


    //Find frequency for A of the given octave
    if (octave>=4){
        freq = 440*(pow(2.00,octave-4.00));
        freq = round(freq);
    } else if (octave<4){
        freq = 440/(pow(2.00,4.00-octave));
    }

    //Find 'n' which is the number of semitones separating the given note from A

    //Make array of sings for semitones
    char signArray[94];

    for(int i=0;i<94;i++){
        signArray[i]='!'+i;
    }

    for(int i=0;i<94;i++){
    printf("%c4@1/4\n", signArray[i]);
        if (note[0] == signArray[i]){
        n = note[0]-33;
        }
    }


    freq = freq*pow(2.00,  (float)n/93.00);
    //printf("%f", freq);
    //freq = freq*pow(2.00, (float)n/12.00);


    int frequ = freq;

    //printf("%i\n",frequ);
    return frequ;
}


int main(void){
    frequency("!4");
    // frequency("!5");
    // frequency("!6");
    // frequency("A7");
    // frequency("B7");
    // frequency("C7");
    // frequency("D7");
    // frequency("E7");
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

