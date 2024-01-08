#include <stdio.h>

int main(void){
    int choice, count=0;                                    // the player's move and a counter for rounds.
    putchar('C');                                           // first move always cooperate.
    putchar('\n');
    
    while ((choice = getchar()) != EOF) {
                     
        if ((count == 9) && (choice=='D' || choice=='C')){  // every 10 rounds always play 'Cooperate'.
                putchar('C');
                fflush(stdin);
                putchar('\n');
                fflush(stdin);
                count = 0;                                 // reset counter
        }
        else if (choice=='D' || choice=='C'){
                putchar(choice);                           // next move is players' previous move.
                fflush(stdin);
                putchar('\n');
                fflush(stdin);
                count++;
        }
        else{
                fflush(stdin);
                continue;                                 // if not the right character ignore and continue.
        }                
    }
    return 0;
}
