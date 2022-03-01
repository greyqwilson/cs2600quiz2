//This file is meant to serve as a supplementary file for Quiz 2 in Prof. Davarpanah's CS2600 class
//Author: Greyson Wilson
//Problem 2: Number guessing game - Interactive number guessing game with menu 
//Inputs: Menu selection as int, guessed number as int
//Outputs: Return whether or not the guess was true

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void printMenu(){
    printf("\t\t---- Guess-A-Number Game ----\n");
    printf("(1) - Play a game\n");
    printf("(2) - Change the max number\n");
    printf("(3) - Quit\n\n");
    printf("Please choose an option from the menu above.\n");
}

void playGame(){
    int guess = 0;
    printf("Please enter a number: \n");
    scanf("%i", &guess);
    
}

void changeMaxNumber(){
    
}

int main(){

    int menuOption = -1;
    int maxNumber = 100;
    while (menuOption != 3){

        printMenu();
        scanf("%i", &menuOption);
        
        switch (menuOption) {

            // Play a game
            case 1:
            {
                playGame();
                break;
            }

            //change the max number
            case 2:
            {
                printf("Please enter a new max number:\n");
                scanf("%i", maxNumber);
                break;
            }

            // Quit
            case 3:
            {

                break;
            }

            //Keep menu up
            default:
                menuOption = -1;
        }
    }

    return 0;
}