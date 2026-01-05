#ifndef WORDLE_H
#define WORDLE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

/* wordle */
#define MAX_WORDS 45333
#define WORD_LEN 5 
#define MAX_WORD_LEN 20 
#define MAX_TRIES 6 

/* types */
struct Dictionary { 
    char words[MAX_WORDS][MAX_WORD_LEN + 1]; 
    int count; 
}; 

/* functions */

void game_loop(const struct Dictionary *dict); 
void instructions(void); 
void input_buffer(void); 
int check_guess(char guess[WORD_LEN + 1], const struct Dictionary *dict); 
void choose_secret(const struct Dictionary *dict, char secret[WORD_LEN +1]); 
int load_dictionary(const char *filename, struct Dictionary *dict);     
int filter_dictionary(const struct Dictionary *fullDict, struct Dictionary *filteredDict, int word_len); 
void to_lower_str(char *str); 

#endif