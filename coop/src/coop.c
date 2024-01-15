#include <stdio.h>

int main(void){
    int choice, cntD=0, cntC=0, rounds=0;                                  
    putchar('C');
    fflush(stdout);                                                   
    putchar('\n');
    fflush(stdout);
        
    do{
        choice=getchar();
        fflush(stdin);              
        
        if      (choice=='C' && cntC!=100){
                putchar('C');
                fflush(stdout);
                putchar('\n');
                fflush(stdout);                        
                cntC++;
                rounds++;
        }

        if      (choice=='C' && cntC==100){
                putchar('D');
                fflush(stdout);
                putchar('\n');
                fflush(stdout);
                cntC=0;
                rounds++;
        }

        if      (choice=='D' && cntD==9){
                putchar('C');
                fflush(stdout);                                      
                putchar('\n');
                fflush(stdout);
                cntD=0;
                rounds++;
        }

        if      (choice=='D' && cntD!=9){
                putchar('D');
                fflush(stdout);
                putchar('\n');
                fflush(stdout);                        
                cntD++;
                rounds++;
        }
        }
        while (rounds!=1E6);
        
        return 0;
}
