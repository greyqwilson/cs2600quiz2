//This file is meant to serve as the main file for Quiz 2 in Prof. Davarpanah's CS2600 class
//Author: Greyson Wilson
//Quiz 2: Problem 1 Restuarant Bill - Computes the tax and tip of a restaurant bill
//Inputs: Tax amount and tip (as percentages) through main()
//Outputs: Tax amount, tip amount, and total price of meal


#include <stdio.h>
#include <string.h>     //For use of strtof
#include <stdlib.h>     //For use of rand, srand
#include <time.h>       //For use in RNG

struct menuItem {
    char name[20];
    float price;
};

int main(int argc, char *argv[]){

    float taxPct;
    float taxAmount;
    float tipPct;
    float tipAmount;
    float totalCost;
    struct menuItem menu[4];
    int menuSelection = 0;
    
    //Check that both inputs were entered, if not then quit and leave message
    if (argc < 3){
        printf("Values for tax percent and tip percent were not given.\nTry again.\n");
        return -1;
    }

    taxPct = strtof(argv[1], NULL);
    taxPct = taxPct / 100;
    tipPct = strtof(argv[2], NULL);
    tipPct = tipPct / 100;

    //Set all item names and prices on the menu
    strcpy(menu[0].name, "Salad"); menu[0].price = 9.95;
    strcpy(menu[1].name, "Soup"); menu[1].price = 4.55;
    strcpy(menu[2].name, "Sandwich"); menu[2].price = 13.25;
    strcpy(menu[3].name, "Pizza"); menu[3].price = 22.35;
    
    //Randomly select a menu item from menu
    srand(time(NULL));
    menuSelection = rand()%4;
    
    //Calculate tip amount, tax amount, and total
    taxAmount = menu[menuSelection].price * taxPct;
    tipAmount = menu[menuSelection].price * tipPct;
    totalCost = taxAmount + tipAmount + menu[menuSelection].price;

    //Print order and price breakdown
    printf("Menu item ordered: %s $%.2f \n", menu[menuSelection].name, menu[menuSelection].price);
    printf("Tax amount: $%.2f \n", taxAmount);
    printf("Tip amount: $%.2f \n", tipAmount);
    printf("Total cost: $%.2f \n\n", totalCost);

    return 0;
}