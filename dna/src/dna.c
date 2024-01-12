#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc!=3){                                                                        //checking if the given arguments are 3.
        printf("the program needs to be called as './prog filename1 filename2'\n");       //else print the right way.
        return 1;
    }
    FILE *fp1, *fp2;                               //open 2 streams for the files 
    int i,j,l,k=0, mx=0, len1, len2;               // variables for the loops, counter for the maximum character sequence and 2 for the lengths of the strings.
    char *a, file1[20], file2[20];                 //pointer for keeping the first character of the maximum sequence and 2 characters strings with maximum length 20

    fp1=fopen(argv[1], "r");                       //open the first file using fp1 stream.
    if (fp1==NULL){                                //if something went wrong or the file is empty
        puts("open file1 failed");                 //print error message
        exit(2);                                   //and exit.
    }
    fp2=fopen(argv[2], "r");                       //Do the same for the second file.
    if (fp2==NULL){
        puts("open file2 failed");
        exit(2);
    }    
    fgets(file1,20,fp1);                           //read from first file up to 20 characters and save to file1 array.
    fgets(file2,20,fp2);                           //same for the second file to file2.

    len1=strlen(file1);                            //lengths of files
    len2=strlen(file2);

    for (i=0; i<len1; i++){                        //compare the 2 strings char by char
        for (j=0; j<len2; j++){
            
            while (file1[i+k]==file2[j+k]){        //if 2 characters are the same keep checking for the next too on the row.
                                                               
                k++;                               //and if so adding 1 to the counter of equal characters on the row.
            }
            
            if(k>mx){                              //when exit the loop, check if this is the maximum sequence of same characters
                mx=k;
                k=0;
                a=&file1[i];                       //and point to the first one. 
            }
            k=0;                                   //reset the counter
        }
    }
    printf("maximum= %d\n", mx);                   //print the maximum sequence with an integer
    for (l=0; l<mx; l++){
        putchar(a[l]);                             //and print the sequence
    }
    return 0;
}   
