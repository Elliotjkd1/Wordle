#include <stdio.h> // "Standard Input/Output Header" -- printf(), scanf(), etc. 
#include <string.h> // Provides String functions -- strlen(), strcpy(), strcat(), etc. 
#include <time.h> // time(null)
#include <stdlib.h> // rand()
#include <ctype.h> // toLower()
#include "headers.h" 

static char wordList[MAXWORDS][WORDLEN]; // static so it persists
static int wordCount = 0;


void feedback_function(char secretWord[], char playerGuess[]) {
    char feedback[] = "....."; // . Indicates that the letter is not in the word 
    int used[5] = {0}; // Initialize array that keeps track of the letters used in the secret word , 0 = not used, 1 = used 

    printf("\n");
    for (int i = 0; i < 5; i++ ) { // First loop that checks for correct letters in the correct place 
        if (playerGuess[i] == secretWord[i]) { 
            feedback[i] = 'X';
            used[i] = 1; // marks off the index that has been used 
        }
    }

    for (int i = 0; i < 5; i++ ) { // This loop checks for correct letters in the right place 
        if (feedback[i] == 'X') { // skip this index if the guess letter has been used in the loop above 
            continue;
        }
        for (int j = 0; j < 5; j++) {  // this loop check for correct letters in wrong places 
            if (used[j] == 0 && playerGuess[i] == secretWord[j]) { // checks to see if the word has been used and if the letter is anywhere in the secret word
                feedback[i] = 'O'; 
                used[j] = 1; // once the letter has been used we set it 1 one indicating that is has been already used. 
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

// instruction function 
void instructions(void) { 
    printf("\nYou have 6 tries to guess the 5 letter secret word!");
    puts(
        "\nAfter each guess you will recieve feedback and hints for each character in your guess."
        "\n . = Character not found at all."
        "\n O = Character is in the word but in wrong place."
        "\n X = Charcter is in the word and is in the correct place."
        "\nHints will reset for each guess."
                );
}


char* choose_word(void) { 
    int index = rand() % wordCount; 
    char* word = wordList[index]; 
    for (int i = 0; word[i]; i++) {
         word[i] = tolower(word[i]); // converts to lowercase by looping through each index in secret word and converting it to lowercase 
    }
    return word; 
}   


void game_loop(void) { 
    char* secretWord = choose_word();// initialize secret word *calls the choose word function*
    char playerGuess[WORDLEN + 1]; // Initialize player guess variable 
    int guessSize = WORDLEN + 2; 
    int guessCount; // Initialize guessCount ( 6 TOTAL guesses )


    for (guessCount = 1; guessCount < 7; guessCount++) { // For loop -- increments guessCount by 1 until the guesses reach 6 
        printf("\nEnter your #%d guess here: ", guessCount); // User guess input 

        fgets(playerGuess, sizeof(playerGuess), stdin); // User guess input 

        for (int i = 0; playerGuess[i]; i++) {
            playerGuess[i] = tolower(playerGuess[i]); // converts to lowercase by looping through each index in player guess and converting it to lowercase 
        }

        if (strchr(playerGuess, '\n') == NULL) { //checking to see if there is left over characters 
            input_buffer(); 
        } else {
            playerGuess[strcspn(playerGuess, "\n")] = '\0'; // Removes /n from the end of the player guess to make it 5 characters again 

        }

        if (strlen(playerGuess) != 5) { // is the length of the player's guess doesn't equal 5 we will print a messsage telling them to enter a 5 letter word. 
            printf("\nPlease enter a 5 letter word next time!\n");
            guessCount--; // remove 1 from count and go to the next one which repeats the same count # until you guess a correctly formated word. 
            continue; 
        }


        if (strcmp(playerGuess, secretWord) == 0 ) { // If the player guesses the word the game ends 
            printf("\nYou are correct! The wordle was %s", secretWord); 
            guessCount = 7; // Ends the for loop a
            break;
        } else {
            feedback_function(secretWord, playerGuess); // Gives the user feedback on their guess
            if (guessCount >= 6) {
                printf("\nYou ran out of guesses the wordle was: %s\n", secretWord);
            }
            else { 
                printf("\nYou are incorrect try again.\n"); 
            }
    }
    }

}


void load_wordlist(void) { 
    FILE *file;
    
    file = fopen("dictionary.txt", "r");
    // buffer 
    // + 20 so it is able to clip every word and not have any characters left over. 
    char buffer[WORDLEN + 20]; 


    printf("\n");
    printf("Loading word list.....");
    printf("\n");
    printf("\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL ) {  // loops through every word in dictionary, only stops at EOF( == NULL) or \n which is why we remove the newline 
        
        buffer[strcspn(buffer, "\r\n")] = '\0'; // remove newline 

        if (strlen(buffer) == 5) {
            strncpy(wordList[wordCount], buffer, WORDLEN-1); // copies buffer to wordlist at the increasing index(count) and only 5 chars are allowed to be copied 
            wordList[wordCount][WORDLEN-1] = '\0'; // manually adds '\0' to end to make sure it is a proper string 
            wordCount++; 
            if (wordCount >= MAXWORDS) break;
        }
    }

    fclose(file);
}