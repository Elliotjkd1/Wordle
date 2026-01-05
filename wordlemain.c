#include "wordle.h"


int main() { 
    struct Dictionary full_dict; 
    struct Dictionary filtered_dict; 
    int word_len = WORD_LEN; 
    int playAgain = 1; 

    srand((unsigned) time(NULL));

    int loaded = load_dictionary("dictionary.txt", &full_dict); 

    if (!loaded) { 
        printf("Error: could not load dictionary.\n"); 
        return 1; 
    }

    int filtered = filter_dictionary(&full_dict, &filtered_dict, word_len); 

    if (!filtered) { 
        printf("Error: could not filter dictionary.\n"); 
        return 1; 
    }
    
    printf("Welcome to C-Wordle!\n"); 

    do {
    game_loop(&filtered_dict); 
    printf("Do you want to play again? (Yes = 1, No = 0): ");
    scanf("%d", &playAgain);
    } while (playAgain != 0);
    
    return 0; 
}


