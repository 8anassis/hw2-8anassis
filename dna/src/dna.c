#include <stdio.h>
#include <string.h>

int main(void){

    char *p, *s, *a;
    int i,j,l,k=0, mx=0;
    p = "CTATAGATATAGGGC";
    s = "CATTAGATATAGACG";

    for (i=0; i<strlen(p); i++){
        for (j=0; j<strlen(s); j++){
            
            while (p[i+k]==s[j+k]){
                                                               
                k++;                
            }
            
            if(k>mx){
                mx=k;
                k=0;
                a=&p[i];
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
