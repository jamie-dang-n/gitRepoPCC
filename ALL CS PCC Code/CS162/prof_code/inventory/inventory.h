/* Inventory class example header file
 * Robert Martin, CS162 Su23
 */

#ifndef inventory_h
#define inventory_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "item.h"

// Struct to contain 1000 inventory items using InvItem.
class InventoryType {
    int arrSize;
    InvItem ** items; // items will be an array of pointers, in the coustructor.
    // InvItem * items[10];  same as InvItem **
    int itemCount;
    public:
    ~InventoryType(); // Destructor. Used to delete items array.
    InventoryType(); // Default constructor.
    bool loadInventory(char fileName[]);
    void printInventory(); // member function, method.
    bool addInvItem(InvItem & item);
    bool shiftUpAndInsert(InvItem & item, int index); 
    int getIndex(const InvItem & item);
    int getItemCount();
    InvItem getItem(int index) const;
    InvItem operator[](int index) const; // x = y, =(x, y)  operator[](int index), [index]
    void growArray();
};

#endif
