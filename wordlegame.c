#include <stdio.h> // "Standard Input/Output Header" -- printf(), scanf(), etc. 
#include <string.h> // Provides String functions -- strlen(), strcpy(), strcat(), etc. 
#include <time.h> // time(null)
#include <stdlib.h> // rand()
#include <ctype.h> // toLower()
#include "headers.h" 





int main() {
    srand(time(NULL)); // everytime you run the program the time changes so it will set a different seed for rand
    load_wordlist(); 
    int userChoice = 1; 

    printf("Hi there! Welcome to Wordle!"); // Welcome statement 

    instructions(); // prints instructions 
    
    while (userChoice == 1) { 
        game_loop();
        printf("\nPlay Again? (YES: 1, NO: 0) Enter here: ");
        scanf("%d", &userChoice); 
        printf("\n"); 
        input_buffer();
    }
    return 0; 
}
