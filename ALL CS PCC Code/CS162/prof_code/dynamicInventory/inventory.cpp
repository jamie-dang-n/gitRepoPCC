/* ClassExample
 * Function Implementation file.
 * Robert Martin, Su23
 */
#include "inventory.h"
#include "item.h"
#include "main.h"

// Default constructor. It sets itemCount to zero.
InventoryType::InventoryType() {
    itemCount = 0;
    // open the file.
}

InventoryType::~InventoryType() {
    
    // close the file.
}

// add Inventory Item.
// Arguments: the InventoryType class and the new item to add.
// Returns: result, true if successfully added, false otherwise.
bool InventoryType::addInvItem(InvItem & item) {
    bool result = false;
    int index = 0;
    index = getIndex(item);
    result = shiftUpAndInsert(item, index);
    return result; // One return statement, at the end.
}

bool InventoryType::shiftUpAndInsert(InvItem & item, int index) {
    bool result = false;
    if(itemCount >= arrSize) { // No more room, return result = false.
        result = false;
    }
    else if (itemCount == 0) {
        items[0] = item;      // If the list is empty, place item at index 0.
        itemCount++;
    }
    else {
        result = true;
        for(int i = itemCount; i > index; i--) {
            items[i] = items[i - 1];
        }
        items[index] = item;  // Insert the new item.
        itemCount++;          // count the new item.
    }
    return result;
}

// Get the index of the location in the array so that item can be inserted sorted.
// Arguments: the new item to be added.
// Return: the index where the item should be placed in the array, as an int.
int InventoryType::getIndex(const InvItem & item) {
    int index = 0;
    for(index = 0; index < itemCount; index++) {
        if(strcmp(items[index].getName(), item.getName()) >= 0) {
            // We found where the item should go at index.
            break;
        }
    }
    return index; // Where the new item should go.
}

// getter for itemCount.
int InventoryType::getItemCount() {
    return itemCount;
}


// Print the items in Inventory.
// Argument: the inventory class, which contains an array of items.
void InventoryType::printInventory() {
    char nameCopy[strSize]; // To be used with the copy version of getName(char * destination)

    std::cout << std::setprecision(2) << std::fixed << std::showpoint; // dollars and cents.
    if(itemCount == 0) {
        std::cout << "There are no items in inventory." << std::endl;
    }
    else {
        for(int i = 0; i < itemCount; i++) {
            std::cout << i + 1 << ": " << std::left << std::setw(15);
            
            items[i].getName(nameCopy, strSize); // Version 2 of getName, that takes arguments.
            std::cout << nameCopy;
            std::cout << "count: " << std::right << std::setw(5) << items[i].getCount(); 
            std::cout << std::left << "  price: " << std::right << std::setw(5) <<
                items[i].getPrice() << std::endl;
        }
        std::cout << std::endl;
    }
}


// Load all the inventory items from a file.
// Arguements: the inventory class and a fileName cstring.
// Return: result, true if items successfully loaded, false otherwise.
bool InventoryType::loadInventory(char fileName[]) {
    std::ifstream inFile(fileName);
    char  numberStr[strSize];
    bool result = false, stillRoom = true;
    char tempName[strSize];
    int tempCount;
    double tempPrice;

    if(inFile.is_open()) {
        do{ // stillRoom will be false if array is full.
            if(itemCount >= arrSize) {
                std::cout << "Array is full." << std::endl;
                stillRoom = false;
            }
            else {
                inFile.getline(tempName, strSize, ';');
                inFile.getline(numberStr, strSize, ';');
                tempCount = atoi(numberStr);
                inFile.getline(numberStr, strSize);
                tempPrice = atof(numberStr);
                InvItem tempItem(tempName, tempCount, tempPrice); // invoking the constructor.
                            // tempItem is now created and stores the loaded data.
                addInvItem(tempItem);
                            // the data in tempItem has now been added to the item array.
            }
            // ...,maintenance\n-1
            inFile.peek();  // Check for eof marker.
        } while(!inFile.eof() && stillRoom);
        result = true; // Indicate file was successfully read.
    }
    inFile.close();
    return result;
}

// getItem, return an item from the item list in the inventory.
// Argument: the index of the item to return.
// returns: the item at the index.
// Throws: an integer.
InvItem InventoryType::getItem(int index) {
    if(!(index < itemCount && index >= 0)) {
        throw 1; // execution is terminated if we throw.
    }
    return items[index];
}
