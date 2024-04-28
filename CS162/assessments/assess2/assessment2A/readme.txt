Assessment 2 version A, CS162 Summer 2023, Portland Community College
Instructor: Robert Martin

These are the instructions for the first assessment for cs162, Summer 2023

Step 1: Compile the code in this directory using the command: make
        After the make command there will be a new executable in the directory.
        The executable will be called: program
Step 2: Run the program to make sure it works. Type ./program to run it.
        You should see that the program successfully loaded and printed 8
        grocery items placed in a shopping cart. The price is for each 1 item
        in the cart. The count value is how many of each item is in the cart.
Step 3: Open the code files and the header files in vim or vi, and add
        the following functions to the GroceryList class and/or Item class:

        Item::Item(const Item & otherItem);
          // Create the copy constructor for the Item class. The argument otherItem
          // will contain a price, count, and a name. The price and count can be
          // copied directly. To make a deep copy of the name, find the length of
          // otherItem.name. Then allocate just the right amount of characters,
          // and don't forget +1 for the null terminator.
          
        void GroceryList::addItem();
          // Create the addItem member function for GroceryList. addItem() should
          // ask the user for the name, the price, and the count. You can get
          // some hints from GroceryList::loadItems(). Create a local item so
          // that it can be used to pass to your new copy constructor. Suppose you
          // have a local item called toAdd. Then you can use the setters
          // (toAdd.setCount(), etc.) to set it up. When it comes time to add it
          // to the array, use it as the argument for the copy constructor:
          //  items[itemCount] = new Item(toAdd);
          // Don't use the setters with items[itemCount], only the copy constructor.
          // Don't forget to call grow() after incrementing itemCount if
          // itemCount >= capacity.
        
        Add the member function prototypes to the header files and the function
        definitions to the code files. Add the following two calls to the
        main.cpp file where it says to "fill in the code":
        shoppingCart.addItem();
        shoppingCart.printItems();
        After adding these two statements, the output might look like:
            Welcome to the shopping cart program.
            Successfully loaded 8 items.
            The items in the cart are:

            Name             Price     Count
            ----             -----     -----
            1. apple       $  0.99         4
            2. banana      $  0.69         5
            3. cookie      $  0.50         2
            4. donut       $  1.00         3
            5. egg         $  3.88         1
            6. fish        $  5.88         2
            7. milk        $  2.99         4
            8. yogurt      $  6.38         2
            
            What is the new item name?: Orange
            What is the item count?: 3
            What is the item price?: 3.45

            Name             Price     Count
            ----             -----     -----
            1. apple       $  0.99         4
            2. banana      $  0.69         5
            3. cookie      $  0.50         2
            4. donut       $  1.00         3
            5. egg         $  3.88         1
            6. fish        $  5.88         2
            7. milk        $  2.99         4
            8. yogurt      $  6.38         2
            9. Orange      $  3.45         3

    Use valgrind to make sure there are no memory errors in your code.

Step 4: Submit your assessment.
        In order to submit your files you type:

~robert.martin4/bin/turnin submit prof=robert.martin4 course=cs162 file1 file2 file3 ...

        This will submit file1, file2, file3 (and any more files you specify) to the
        turnin depository for me (robert.martin4) and for the specified
        course. Make sure you send me the header files (item.h and groceryList.h) and the
        code files(3 of them: item.cpp, groceryList.cpp, and main.cpp). The turnin program
        will give you a "receipt" identifier that you can keep if you want
        to have a record of turning in the file(s).

        If you have multiple files to turn in you can either call turnin with multiple
        files listed on the command line, or use zip or tar to create a single bundle and
        turn that in. Either way is fine. You can zip an entire director with the -r option.
        If your directory is called assessment2A, you can go to the parent directory and type:
        zip -r myNameAssessment2.zip assessment2A
        It's not important, but you should probably replace myName with your actual name.

        You can call this command as many times as you want. Each subsequent call does
        not overwrite the previous one.
