#include <stdio.h> // "Standard Input/Output Header" -- printf(), scanf(), etc. 
#include <string.h> // Provides String functions -- strlen(), strcpy(), strcat(), etc. 

void feedbackFunction(char secretWord[], char playerGuess[]);

int main() {
    char secretWord[] = "flake"; // initialize secret word 
    char playerGuess[10]; // Initialize player guess variable 
    int guessCount; // Initialize guessCount ( 6 TOTAL guesses )


    printf("Hi there! Welcome to Wordle!"); // Welcome statement 

    for (guessCount = 1; guessCount < 6; guessCount++) { // For loop -- increments guessCount by 1 until the guesses reach 6 
        printf("\nEnter your #%d guess here: ", guessCount); // User guess input 
        fgets(playerGuess, sizeof(playerGuess), stdin); // User guess input 
        playerGuess[strcspn(playerGuess, "\n")] = '\0'; // Removes /n from the end of the player guess to make it 5 characters again 
        if (strcmp(playerGuess, secretWord) == 0 ) { // If the player guesses the word the game ends 
            printf("\nYou are correct! The wordle was %s", secretWord); 
            guessCount = 7; // Ends the for loop 
        } else {
            feedbackFunction(secretWord, playerGuess);
            printf("You are incorrect try again."); 
    }
    }
     
    
    return 0; 
    }

void feedbackFunction(char secretWord[], char playerGuess[]) {
    char feedback[] = "....."; // . Indicates that the letter is not in the word 
    int used[5] = {0}; 

    for (int i = 0; i < 5; i++ ) {
        if (playerGuess[i] == secretWord[i]) {
            feedback[i] = playerGuess[i]; 
            used[i] = 1; 
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%c", feedback[i]);
    }
    printf("\n");
}
