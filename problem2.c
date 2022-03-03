//This file is meant to serve as a supplementary file for Quiz 2 in Prof. Davarpanah's CS2600 class
//Author: Greyson Wilson
//Problem 2: Number guessing game - Interactive number guessing game with menu 
//Inputs: Menu selection as int, guessed number as int
//Outputs: Return whether or not the guess was true

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int guesses = 0;
int wins = 0;

void printMenu(){
    printf("\t\t---- Guess-A-Number Game ----\n");
    printf("(1) - Play a game\n");
    printf("(2) - Change the max number\n");
    printf("(3) - Quit\n\n");
    printf("Please choose an option from the menu above.\n");
}

void playGame(int maxN){
    int guess = 0;
    int answer;
    char stringGuess[maxN];
    int playing = 1;
    srand(time(NULL));
    answer = rand() % maxN;

    while (playing == 1){
        scanf("");
        printf("Please enter a number between 0 and %i: \n", maxN);
        scanf("%s", stringGuess);
        //Check if q was entered instead of a number. If so, return to main menu
        if (stringGuess[0] == 'q')
            return;

        guesses++;
        guess = strtol(stringGuess, NULL, 10);
        //Check if number is within bounds
        if (guess > maxN || guess < 0)
            continue;

        if (answer == guess){
            printf("Congratulations! You guessed the correct answer!\n");
            wins++;
            return;
        }
        else{
            if (guess > answer){
                printf("You were over the number.\n");
            }
            else{
                printf("You were below the number.\n");
            }
        }
    }
    return;
}


int main(){

    int menuOption = -1;
    const int MAXNUMBER = 100;
    int currentMaxNumber = 100;
    while (menuOption != 3){

        scanf("");
        printMenu();
        scanf("%i", &menuOption);
        
        switch (menuOption) {

            // Play a game
            case 1:
            {
                playGame(currentMaxNumber);
                break;
            }

            //change the max number
            case 2:
            {
                do {
                    scanf("");
                    printf("Please enter a new max number between 1 and %i:\n", MAXNUMBER);
                    printf("Current max is: %i \n", currentMaxNumber);
                    scanf("%i", &currentMaxNumber);
                }
                while (currentMaxNumber <= 1 && currentMaxNumber > MAXNUMBER);
                printf("New max number is now %i \n", currentMaxNumber);

                break;
            }

            // Quit
            case 3:
            {
                printf("Thank you for playing!\n");
                printf("You made %i guesses and won %i times. \n", guesses, wins);

                break;
            }

            //Keep menu up
            default:
                menuOption = -1;
        }
    }

    return 0;
}