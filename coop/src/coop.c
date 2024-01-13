#include <stdio.h>

int main(void){
    int choice, count=0, rounds=0;                                  
    putchar('C');                                                   
    putchar('\n');
    
    while (rounds<=1E6){
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
                rounds++;
        }
        else if (choice=='D' && count==9){
                putchar('C');                                      
                fflush(stdout);
                putchar('\n');
                fflush(stdout);
                count=0;
                rounds++;
        }
        else if (choice=='D' && count!=9){
                putchar('D');
                fflush(stdout);
                putchar('\n');
                fflush(stdout);
                count++;
                rounds++;
        }
        
        }                
        return 0;
}
