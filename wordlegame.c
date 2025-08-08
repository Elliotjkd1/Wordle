#include <stdio.h> // "Standard Input/Output Header" -- printf(), scanf(), etc. 
#include <string.h> // Provides String functions -- strlen(), strcpy(), strcat(), etc. 
// #include <stdbool.h> // True or False Logic -- 0 for false, 1 for true 


int main() {
    char secretWord[] = "flake";
    char playerGuess[10]; 
    int guessCount;


    printf("Hi there! Welcome to Wordle!");

    for (guessCount = 1; guessCount < 7; guessCount++) {
        printf("\nEnter your #%d guess here: \n", guessCount);
        fgets(playerGuess, sizeof(playerGuess), stdin);
        playerGuess[strcspn(playerGuess, "\n")] = '\0';
        if (strcmp(playerGuess, secretWord) == 0 ) {
            printf("\nYou are correct! The wordle was %s", secretWord);
            guessCount = 7; 
        } else {
            printf("You are incorrect try again.");
        }
    }
    
    
    
    return 0; 
    }