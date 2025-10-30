// global varibales 
#define WORDLEN 6 
#define MAXWORDS 6000


// function prototypes 
void feedback_function(char secretWord[], char playerGuess[]);
void input_buffer(void); 
void instructions(void); 
void game_loop(void); 
void load_wordlist(void);
char* choose_word(void);
