#include <stdio.h>

int main(void){
    int choice, count=0, rounds;                                  
    putchar('C');                                                   
    putchar('\n');
    
    for (rounds=0; rounds<=1E6; rounds++){
        do{
                choice=getchar();
                fflush(stdout);
        }       
        while (choice != 'C' && choice != 'D');

        
        if      (choice=='C'){
                putchar('C');
                fflush(stdout);
                putchar('\n');
                fflush(stdout);
        }

        if      (choice=='D' && count==9){
                putchar('C');                                      
                fflush(stdout);
                putchar('\n');
                fflush(stdout);
                count=0;
        }

        if      (choice=='D' && count!=9){
                putchar('D');
                fflush(stdout);
                putchar('\n');
                fflush(stdout);
                count++;
        }
        
        }                
        return 0;
}
