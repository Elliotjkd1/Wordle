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
        }

        if (strcmp(userGuess, secret) == 0) { 
            printf("Correct! You win! The wordle was %s\n", secret);
            return; 
        } else { 
            printf("Incorrect! Try Again\n"); 
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