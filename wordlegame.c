#include <stdio.h> // "Standard Input/Output Header" -- printf(), scanf(), etc. 
#include <string.h> // Provides String functions -- strlen(), strcpy(), strcat(), etc. 

void feedback_function(char secretWord[], char playerGuess[]);
void input_buffer(void); 

int main() {
    char secretWord[] = "flake"; // initialize secret word 
    char playerGuess[10]; // Initialize player guess variable 
    int guessCount; // Initialize guessCount ( 6 TOTAL guesses )


    printf("Hi there! Welcome to Wordle!"); // Welcome statement 

    for (guessCount = 1; guessCount < 7; guessCount++) { // For loop -- increments guessCount by 1 until the guesses reach 6 
        printf("\nEnter your #%d guess here: ", guessCount); // User guess input 

        fgets(playerGuess, sizeof(playerGuess), stdin); // User guess input 

        if (strchr(playerGuess, '\n') == NULL) {
            input_buffer();
        } else {
            playerGuess[strcspn(playerGuess, "\n")] = '\0'; // Removes /n from the end of the player guess to make it 5 characters again 

        }

        if (strlen(playerGuess) != 5) {
            printf("\nPlease enter a 5 letter word next time!\n");
            guessCount--;
            continue;
        }

        if (strcmp(playerGuess, secretWord) == 0 ) { // If the player guesses the word the game ends 
            printf("\nYou are correct! The wordle was %s", secretWord); 
            guessCount = 7; // Ends the for loop a
            break;
        } else {
            feedback_function(secretWord, playerGuess); // Gives the user feedback on their guess
            printf("You are incorrect try again."); 
    }
    }
     
    
    return 0; 
    }

void feedback_function(char secretWord[], char playerGuess[]) {
    char feedback[] = "....."; // . Indicates that the letter is not in the word 
    int used[5] = {0}; // Initialize array that keeps track of the letters used in the secret word 

    for (int i = 0; i < 5; i++ ) { // First loop that checks for correct letters in the correct place 
        if (playerGuess[i] == secretWord[i]) { 
            feedback[i] = 'X';
            used[i] = 1; // marks off the index that has been used 
        }
    }

    for (int i = 0; i < 5; i++ ) { // This loop checks for correct letters in the wrong place 
        if (feedback[i] == 'X') { // skip this index if the guess letter has been used in the loop above 
            continue;
        }
        for (int j = 0; j < 5; j++) { 
            if (used[j] == 0 && playerGuess[i] == secretWord[j]) { 
                feedback[i] = 'O'; 
                used[j] = 1;
            }
        }

    }

  

    for (int i = 0; i < 5; i++) { // prints out feedback 
        printf("%c", feedback[i]);
    }
    printf("\n");
}

void input_buffer(void) {
     int c;
    while ( (c = getchar()) != '\n' && c != EOF) {}
}