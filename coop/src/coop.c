#include <stdio.h>

/* Start playing as Cooparate. Every 10 times of opponents' Defective move, play 'C' 
and every 50 times of opponents' Cooperate move, play 'D' */

int main(void){
    int choice, cntD=0, cntC=0, rounds=0;                                  
    putchar('C');
    putchar('\n');
    fflush(stdout);
        
    do{
        choice=getchar();
               
        if      (choice=='C' && cntC!=50){
                putchar('C');
                putchar('\n');
                fflush(stdout);                        
                cntC++;
                rounds++;
        }

        if      (choice=='C' && cntC==50){
                putchar('D');
                putchar('\n');
                fflush(stdout);
                cntC=0;
                rounds++;
        }

        if      (choice=='D' && cntD==10){
                putchar('C');
                putchar('\n');
                fflush(stdout);
                cntD=0;
                rounds++;
        }

        if      (choice=='D' && cntD!=10){
                putchar('D');
                putchar('\n');
                fflush(stdout);                        
                cntD++;
                rounds++;
        }
        }
        while (rounds!=1E6);
        
        return 0;
}
