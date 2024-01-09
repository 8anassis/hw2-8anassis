#include <stdio.h>

int main(void){
    int choice, count=0, rounds=0;                                    // the player's move, a counter (count) for every 10 rounds so that can play cooparate and a counter (rounds) for maximum rounds.
    putchar('C');                                                     // first move always cooperate.
    putchar('\n');
    
    while (((choice = getchar()) != EOF) && (rounds<=1E6)) {
                     
        if ((count == 9) && (choice=='D' || choice=='C')){             // every 10 rounds always play 'Cooperate'.
                putchar('C');
                fflush(stdout);
                putchar('\n');
                fflush(stdout);
                count = 0;                                             // reset counter
                rounds++;                                              //increase total rounds
        }
        else if (choice=='D' || choice=='C'){
                putchar(choice);                                       // next move is players' previous move.
                fflush(stdout);
                putchar('\n');
                fflush(stdout);
                count++;
                rounds++;
        }
        else{
                fflush(stdin);
                continue;                                             // if not the right character ignore and continue.
        }                
    }
    return 0;
}
