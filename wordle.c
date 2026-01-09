#include "wordle.h"


int load_dictionary(const char *filename, struct Dictionary *dict) { 
    FILE *fptr; 

    fptr = fopen(filename, "r"); 

    if (fptr == NULL) { 
        printf("Could not open file.\n");
        return 0; 
    }

    dict->count = 0; 

    while (dict->count < MAX_WORDS) { 
        int result = fscanf(fptr, "%20s", dict->words[dict->count]); 

        if (result != 1) { 
            break; 
        }

        to_lower_str(dict->words[dict->count]);

        dict->count++; 
    }

    fclose(fptr); 

    return dict->count > 0; 
}

int filter_dictionary(const struct Dictionary *fullDict, struct Dictionary *filteredDict, int word_len) { 
    
    filteredDict->count = 0; 

    for (int i = 0; i < fullDict->count; i++) { 
        int len = strlen(fullDict->words[i]); 

        if (len == word_len) { 
            strcpy(filteredDict->words[filteredDict->count], fullDict->words[i]); 
            filteredDict->count++;
        }
    }
    return filteredDict->count > 0; 
}

void game_loop(const struct Dictionary *dict) { 
    int displayInstruct = 0;  

    int key[26] = {0};

    
    while (1) {
        printf("Show instructions? (1 = yes, 0 = no): ");

        if (scanf("%d", &displayInstruct) != 1) {
            // user typed something not a number
            input_buffer();
            printf("Please enter 1 or 0.\n");
            continue;
        }

        input_buffer(); // clear the rest of the line (including newline)

        if (displayInstruct == 0 || displayInstruct == 1) {
            break;
        }

        printf("Please enter 1 or 0.\n");
    }

    if (displayInstruct == 1) {
        instructions();
    }

    char secret[WORD_LEN + 1]; 

    choose_secret(dict, secret); 
    to_lower_str(secret); 
    
    for (int guessCount = 1; guessCount <= MAX_TRIES; guessCount++) { 
        char userGuess[WORD_LEN + 1];
        printf("Guess #%d, Enter word: ", guessCount); 
        scanf("%5s", userGuess); 
        input_buffer();

        while (!check_guess(userGuess, dict)) { 
            printf("Invalid guess. Enter a real %d-letter word: ", WORD_LEN);
            scanf("%5s", userGuess);
            input_buffer(); 
        }

        printf("\n"); 
        print_feedback(userGuess, secret); 
        printf("\n"); 
        print_and_update_keyboard(userGuess, secret, key); 
        printf("\n");

        if (strcmp(userGuess, secret) == 0) { 
            printf("Correct! You win! The wordle was %s\n", secret);
            return; 
        } else { 
            printf("Incorrect! Try Again\n"); 
            printf("\n"); 

        }

    }

    printf("Out of tries! The word was %s\n", secret); 
}

int check_guess(char guess[WORD_LEN + 1], const struct Dictionary *dict) { 
    size_t length = strlen(guess); 
    
    if (length != WORD_LEN) { 
        return 0; 
    }

    for (int i = 0; i < WORD_LEN; i++) { 
        if(!isalpha((unsigned char)guess[i])) { 
            return 0; 
        }
    }

    to_lower_str(guess);

    for (int i = 0; i < dict->count; i++) { 
        if (strcmp(dict->words[i], guess) == 0) { 
            return 1; 
        }
    }

    return 0; 
}

void print_feedback(char guess[WORD_LEN + 1 ], char secret[WORD_LEN + 1 ]) {
    static char historyGuesses[MAX_TRIES][WORD_LEN + 1];
    static int  historyGreen[MAX_TRIES][WORD_LEN];
    static int  historyYellow[MAX_TRIES][WORD_LEN];
    static int  numGuesses = 0;


    int isGreen[WORD_LEN] = {0}; 
    int isYellow[WORD_LEN] = {0}; 
    int usedIdx[WORD_LEN] = {0}; 


    for (int i = 0; i < WORD_LEN; i++) { 
        if (guess[i] == secret[i]) { 
            isGreen[i] = 1; 
            usedIdx[i] = 1; 
        }

    }

    for (int i = 0; i < WORD_LEN; i++) { 
        if (isGreen[i] == 1 ) { 
            continue; 
        }
        for (int j = 0; j < WORD_LEN; j++) { 
            if (usedIdx[j] != 1 && guess[i] == secret[j]) { 
                isYellow[i] = 1; 
                usedIdx[j] = 1; 
                break; 
            }
        }
    }

    if (numGuesses < MAX_TRIES) { 
        for (int i = 0; i < WORD_LEN; i++) { 
            historyGuesses[numGuesses][i] = guess[i]; 
            historyGuesses[numGuesses][WORD_LEN] = '\0'; 
        }
        for (int i = 0; i < WORD_LEN; i++) {
            historyGreen[numGuesses][i] = isGreen[i];
            historyYellow[numGuesses][i] = isYellow[i];
        }
        numGuesses++; 
    }

     printf("BOARD:\n");


   for (int row = 0; row < numGuesses; row++){ 
    for(int col = 0; col < WORD_LEN; col++){ 
        char c = (char)toupper((unsigned char)historyGuesses[row][col]); 

        if (historyGreen[row][col])       printf("[%c] ", c);
        else if (historyYellow[row][col]) printf("(%c) ", c);
        else                          printf(" %c  ", c);

    }
    printf("\n"); 
   }


    for (int row = numGuesses; row < MAX_TRIES; row++) {
        for (int col = 0; col < WORD_LEN; col++) {
            printf(" _  ");
        }
        printf("\n");
    }
    printf("\n");
}


void print_and_update_keyboard(char guess[WORD_LEN + 1], char secret[WORD_LEN + 1 ], int key[26]) { 
    int isGreen[WORD_LEN] = {0}; 
    int isYellow[WORD_LEN] = {0}; 
    int usedIdx[WORD_LEN] = {0}; 

    for (int i = 0; i < WORD_LEN; i++) { 
        if (guess[i] == secret[i]) { 
            isGreen[i] = 1; 
            usedIdx[i] = 1; 
        }

    }

    for (int i = 0; i < WORD_LEN; i++) { 
        if (isGreen[i] == 1 ) { 
            continue; 
        }
        for (int j = 0; j < WORD_LEN; j++) { 
            if (usedIdx[j] != 1 && guess[i] == secret[j]) { 
                isYellow[i] = 1; 
                usedIdx[j] = 1; 
                break; 
            }
        }
    }

    for (int i = 0; i < WORD_LEN; i++) { 
        char c = guess[i]; 

        if (c < 'a' || c > 'z') { 
            continue; 
        }
        int idx = c - 'a'; 
        int newState = 1; 
        if (isYellow[i]) newState = 2; 
        if (isGreen[i]) newState = 3; 

        if(newState > key[idx]) key[idx] = newState; 
    }

    printf("KEYBOARD:\n");

    const char *rows[] = { "QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM" };
    int indents[] = {0,1,2 };

    for (int r = 0; r < 3; r++) { 
        for (int s = 0; s < indents[r]; s++) { 
            printf(" "); 
        }

        for (int j = 0; rows[r][j] != '\0'; j++) { 
            char L = rows[r][j];
            int st = key[L - 'A'];

            if (st == 3)      printf("[%c] ", L);   // green
            else if (st == 2) printf("(%c) ", L);   // yellow
            else if (st == 1) printf(" -  ");       // gray
            else              printf(" %c  ", L);   // unknown
            
        }
        printf("\n"); 
    }
}

void choose_secret(const struct Dictionary *dict, char secret[WORD_LEN + 1 ]) { 
    int index = rand() % dict->count; 
    strcpy(secret, dict->words[index]); 
    secret[WORD_LEN] = '\0'; 
}

void to_lower_str(char *str){ 
    while (*str != '\0') { 
        *str =(char)tolower((unsigned char)*str); 
        str++; 
    }
}

void input_buffer(void) { 
    int clear; 
      while ((clear = getchar()) != '\n' && clear != EOF) {
    }
}


void instructions(void) { 
    puts(""); 
    puts(""); 
    puts("==============================================");
    puts("HOW TO PLAY:");
    puts("  - Try to guess the secret word.");
    puts("  - Each guess must be the correct length (5 letters).");
    puts("  - After each guess, you'll get feedback:");
    puts("");
    puts("    [A]  -> Letter A is in the word AND in the correct spot.");
    puts("    (A)  -> Letter A is in the word but in the WRONG spot.");
    puts("     A   -> Letter A is NOT in the word at all.");
    puts("");
    puts("EXAMPLE FEEDBACK:");
    puts("    Secret: GHOST");
    puts("    Guess : SHAPE");
    puts("    Result: (S)[H]  A   P  (E)");
    puts("");
    puts("You have 6 attempts to guess the secret word.");
    puts("Good luck and have fun!");
    puts("==============================================");
    puts(""); 
    puts(""); 
}