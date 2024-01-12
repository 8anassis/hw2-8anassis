#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc!=3){
        printf("the program needs to be called as './prog filename1 filename2'\n");
        return 1;
    }
    FILE *fp1, *fp2;
    int i,j,l,k=0, mx=0, len1, len2;
    char *a, file1[20], file2[20];

    fp1=fopen(argv[1], "r");
    if (fp1==NULL){
        puts("open file1 failed");
        exit(2);
    }
    fp2=fopen(argv[2], "r");
    if (fp2==NULL){
        puts("open file2 failed");
        exit(2);
    }    
    fgets(file1,20,fp1);
    fgets(file2,20,fp2);

    len1=strlen(file1);
    len2=strlen(file2);

    for (i=0; i<len1; i++){
        for (j=0; j<len2; j++){
            
            while (file1[i+k]==file2[j+k]){
                                                               
                k++;                
            }
            
            if(k>mx){
                mx=k;
                k=0;
                a=&file1[i];
            }
            k=0;
        }
    }
    printf("maximum= %d\n", mx);
    for (l=0; l<mx; l++){
        putchar(a[l]);
    }
    return 0;
}   
