#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* This program reads 2 files containing of strings, comparing them and searches for the maximum in common sequence of characters. */

//This function reads and copy the file given -as argument- returning a pointer to an array of the copied characters.
char *readfile(char* filename){
    FILE *fp;                              
    char *b;                 

    fp=fopen(filename, "r");                      
    if (fp==NULL){                                
        puts("open file failed");                 
        exit(2);                                   
    }

    //find out how large is the file in order to alocate buffer.
    fseek(fp, 0L, SEEK_END);                        
    int size=ftell(fp); 
    fseek(fp, 0L, SEEK_SET);
    b=calloc(size,sizeof(char));
    if (b==NULL){
        puts("insufficient memory");
    }

    //copying and cheking if something went wrong.
    size_t result = fread(b,1,size,fp); 
    fclose(fp);
    if (result==0){
        exit(2);
    }
    return b;
}


bool is_invalid_char(char ch){
    //keeping only the valid characters.
    return ch!='A' && ch!='G' && ch!='C' && ch!='T'; 
}

int main(int argc, char *argv[]){
    if (argc!=3){                                                                        
        printf("the program needs to be called as './prog filename1 filename2'\n");
        return 1;
    }

    int i,j,l,k=0, mx=0, len1=0, len2=0;               
    char *a, *b, *c;                 

    b=readfile(argv[1]);
   
    c=readfile(argv[2]);
    
    len1=strlen(b);                  
    len2=strlen(c);

    /* compare only the valid characters. If are the same, keep checking next one, counting the sequence
    and keep pointing to the first. */
    for (i=0; i<len1; i++){    
        if (is_invalid_char(b[i])){
            continue;
        }                    
        for (j=0; j<len2; j++){
            if (is_invalid_char(c[j])){
                continue;
            }   
            while (b[i+k]==c[j+k]){        
                                                               
                k++;                       
            }

            //check if this is the maximum sequence
            if(k>mx){                      
                mx=k;
                k=0;
                a=&b[i];                   
            }
            k=0;                                   
        }
    }
    for (l=0; l<mx; l++){
        putchar(a[l]);                             
    }
    putchar('\n');
    return 0;
}   
