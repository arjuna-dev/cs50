#define _GNU_SOURCE
#include <crypt.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    if (argc==2){

        //Get the hash
        string hash = argv[1];

        //Get first two characters
        char salt[3] = {hash[0],hash[1],'\0'};


        //Try 1
        char letterArray[53];

        for(int i=0;i<26;i++){
            letterArray[i]='A'+i;
        }

        for(int j=26;j<52;j++){
            int k = j-26;
            letterArray[j]='a'+k;
        }

        //Check array by printing it
        // for(int i=0;i<53;i++){
        //     printf("%c",letterArray[i]);
        // }

        //Varaiable to check on what number of letter we are iterating through
        int n = 0;

        //Iterate through all possibilities
        for(int i=0;i<52;i++){
            for(int j=0;j<52;j++){
                for(int k=0;k<52;k++){
                    for(int l=0;l<52;l++){
                        for(int m=0;m<52;m++){

            if(i>0){
                n=5;
            } else if(j>0){
                n=4;
            } else if(k>0){
                n=3;
            } else if(l>0){
                n=2;
            } else if(m>=0){
                n=1;
            }

            char key[6] = {letterArray[m],letterArray[l],letterArray[k],letterArray[j],letterArray[i]};
            key[n]='\0';

            //Try 2

        // char letterArray[53];

        // for(int i=0;i<26;i++){
        //     letterArray[i]='A'+i;
        // }

        // for(int j=26;j<52;j++){
        //     int k = j-26;
        //     letterArray[j]='a'+k;
        // }

        // //Check array by printing it
        // for(int i=0;i<53;i++){
        //     printf("%c",letterArray[i]);
        // }

        // //Varaiable to check on what number of letter we are iterating through
        // int n = 0;

        // for(int i=0;i<52;i++){
        //     for(int j=0;j<52;j++){
        //         for(int k=0;k<52;k++){
        //             for(int l=0;l<52;l++){
        //                 for(int m=0;m<52;m++){

        //     char key[6] = {letterArray[m],letterArray[l],letterArray[k],letterArray[j],letterArray[i],'\0'};

        // char letterArray[53];
        // letterArray[0]='\0';

        // for(int i=0;i<26;i++){
        //     letterArray[i+1]='A'+i;
        // }

        // for(int j=26;j<52;j++){
        //     int k = j-26;
        //     letterArray[j+1]='a'+k;
        // }

            string newHash = crypt(key,salt);

            if(strcmp(newHash, hash)==0){
                printf("Found the password, it is: %s\n",key);
                break;
            }
                        }
                    }
                }
            }
        }


    } else {
        printf("Smthn went wrong... Please enter a hash after writing ./crack.\n");
        return 1;
    }
}



//Do a function and escape loop with return
//Do the print outside of the funtion, the funtion