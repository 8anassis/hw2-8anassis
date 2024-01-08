#include <stdio.h>

int main(void){
    int choice, count=0;    // the player's choice of move and a counter for rounds.
    putchar('C');           // first move always cooperate.
    putchar('\n');
    while (1) {
        choice = getchar(); // to store players move.
        if (choice != EOF){             
            if ((count == 9) && (choice=='D' || choice=='C')){    //in every 9 rounds always play 'Cooperate'.
                putchar('C');
                fflush(stdin);
                putchar('\n');
                fflush(stdin);
                count = 0;     // reset counter
            }
            else if (choice=='D' || choice=='C'){
                putchar(choice);    // next move is players' previous move.
                fflush(stdin);
                putchar('\n');
                fflush(stdin);
                count++;
            }
            else{
                fflush(stdin);
                continue; // if not the right character ignore and continue.
            }                
        }
        break;  // if you reach EOF, break the loop.
    }return 0;
}
