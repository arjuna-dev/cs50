#define _GNU_SOURCE
#include <crypt.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int finder(string aSalt,string aHash,char anArray[])
{
    //Varaiable to check on what number of letter we are iterating through
    int n = 0;

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

        char key[6] = {anArray[m],anArray[l],anArray[k],anArray[j],anArray[i]};
        key[n]='\0';

        string newHash = crypt(key,aSalt);


        if(strcmp(newHash, aHash)==0){
            printf("Found the password, it is: %s\n",key);
            return 0;
        }
                    }
                }
            }
        }
    }
    return 1;
}

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


        //Iterate through all possibilities

        finder(hash,salt,letterArray);

    } else {
        printf("Smthn went wrong... Please enter a hash after writing ./crack.\n");
        return 1;
    }
}



//Do a function and escape loop with return
//Do the print outside of the funtion, the funtion