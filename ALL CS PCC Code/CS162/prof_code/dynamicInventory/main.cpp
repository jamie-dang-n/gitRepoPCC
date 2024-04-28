/* Summer '23 CS162 Struct Example
   Database of inventory items.
   
   main.cpp, main function file.
   Robert Martin
*/
#include "inventory.h"
#include "item.h"
#include "main.h"

int main() { // stack frame
    InventoryType inventory; // creating inventory invokes the constructor.
    InvItem item;
    int index = 0;
    char tempStr[strSize];
    bool success = false;
    char fileName[strSize];
    char menuChoice = ' ';
    std::ifstream file;

    { // create "inner" scope
        InvItem otherItem;
    } // any items created inside go out of scope at closing curly brace (destroyed).

    std::cout << "Welcome to the inventory program. What is the database file name? ";
    std::cin.getline(fileName, strSize);
    // If loadInventory is successful, then the inventory was loaded.
    if(!inventory.loadInventory(fileName)) {
        std::cout << "Couldn't load the inventory file. Exiting the program." << std::endl;
    }
    else {
        std::cout << inventory.getItemCount() << " items loaded from the file." << std::endl;
        do {
            menuChoice = getMenuChoice();
            switch (menuChoice) {
                case 'A':
                    item.loadItem();  // objects use dot notation to get to members.
                    success = inventory.addInvItem(item);
                    if(success) {
                        std::cout << item.getName() << " successfully added to inventory." << std::endl;
                    }
                    break;
                case 'L':
                    inventory.printInventory(); // object notation, dot.
                    break;
                case 'G':
                    std::cout << "Which index would you like? ";
                    std::cin >> index;
                    break;
                case 'Q':
                    std::cout << "Good bye, thanks for using the program." << std::endl;
                    break;
                default:
                    ; // Should not happen, data validation in getMenuChoice().
            }
        } while(menuChoice != 'Q');
    }
    return 0;
}

// Get the menu choice: L, Q, or A (list, quit or add).
// returns: the menu choice as a char.
char getMenuChoice() {
    char choice = ' ';
    bool success = false;

    std::cout << "What would you like to do?\n";
    std::cout << "L: List the inventory,\n";
    std::cout << "A: Add an item to the inventory,\n";
    std::cout << "G: Get an item,\n";
    std::cout << "Q: Quit.\n";
    do {
        std::cout << "Please enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(strSize, '\n');
        choice = toupper(choice);
        // If choice is not (!) equal to L, Q, or A.
        if(!(choice == 'L' || choice == 'Q' || choice == 'A' || choice == 'G')) {
            std::cout << "Sorry, invalid choice. Try again." << std::endl;
        }
        else {
            success = true;
        }
    }while (!success);  // while not success.

    return choice;
}

// Get a valid integer.
// Returns; a positive integer.
// The function uses atoi() to make sure the number from the user is an int
// and is positive. A do-while loop is used to keep asking for valid data.
int validInt() {
    int value = 0;
    char numberStr[strSize];
    do {
        std::cin.getline(numberStr, strSize);
        value = atoi(numberStr); // Hello
        if(value <= 0) {
            std::cout << "The count must be positive." << std::endl;
        }
    }while(value <= 0);
    return value;
}

// Get a valid double.
// Returns; a positive double.
// The function uses atof() to make sure the number from the user is a double
// and is positive. A do-while loop is used to keep asking for valid data.
double validDouble() {
    double value = 0.0;
    char numberStr[strSize];
    do {
        std::cin.getline(numberStr, strSize);
        value = atof(numberStr);
        if(value <= 0.0) {
            std::cout << "The price must be positive." << std::endl;
        }
    }while(value <= 0.0);
    return value;
}
