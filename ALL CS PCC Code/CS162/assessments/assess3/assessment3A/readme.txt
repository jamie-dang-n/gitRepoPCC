Assessment 3 version A, CS162 Summer 2023, Portland Community College
Instructor: Robert Martin

These are the instructions for the third assessment for cs162, Summer 2023

Step 1: Compile the code in this directory using the command: make
        After the make command there will be a new executable in the directory.
        The executable will be called: program
Step 2: Run the program to make sure it works. Type ./program to run it.
        You should see that the program successfully loaded and printed 8
        grocery items placed in a shopping cart. The price is for each 1 item
        in the cart. The count value is how many of each item is in the cart.
Step 3: Open the code files and the header files in vim or vi, and add
        the following functions to the GroceryList class:
          
        Item GroceryList::getMaxPriceItem();
          // Create the member function to find the highest priced item in the cart.
          // You will have to traverse the list to find the item in the list that
          // has the highest price. Once you find the item, return it. The assignment
          // operator is overloaded (to make a deep copy), so you can assign items
          // in the nodes to a local Item, and use an Item created in main to store
          // the return value. Remember, one strategy for finding the max item is to
          // set an item to the first item in the list, and then replace it if you
          // find an item in the list that has a higher price.
        void GroceryList::addSecond();
          // Ask the user for the name, price and count of a grocery Item, create a
          // new Node, set the item data in the new node using the data provided, and
          // then add the new node to the linked list as the second node. Put another
          // way, add the new node to the list after the node at which head is pointing.
          // There is a constructor for Item that takes arguments, a copy constructor,
          // and the overloaded assignment operator, so you can use those to make it
          // easier to set up the item in the new node. Also, add 1 to itemCount.

        Add the member function prototypes to the header file and the function
        definitions to the code file. Add the following five statements (or some
        approximation) to the main.cpp file where it says to "fill in the code":
          maxItem = shoppingCart.getMaxPriceItem();
          cout << "\nThe item with the max price is:\n" << maxItem << endl << endl;
          shoppingCart.addSecond();
          cout << "\nThe shopping cart with the new item is:" << endl << endl;
          shoppingCart.printItems();

        The overloaded insertion operator (<<) is already set up for Item, so you
        can just send the maxItem to cout. After adding these five statements,
        the output might look like:
            Welcome to the shopping cart program.
            Successfully loaded 8 items.
            The items in the cart are:

            Name             Price     Count
            ----             -----     -----
            1. apple       $  0.99         4
            2. banana      $  0.69         5
            3. cookie      $  0.50         2
            4. donut       $  1.50         3
            5. egg         $  3.88         1
            6. fish        $  8.88         2
            7. milk        $  4.99         4
            8. yogurt      $  6.38         2

            The item with the max price is:
            fish        $  8.88         2

            What is the new item name?: Orange
            What is the item count?: 3
            What is the item price?: 3.45
            The shopping cart with the new item is:

            Name             Price     Count
            ----             -----     -----
            1. apple       $  0.99         4
            2. Orange      $  3.45         3
            3. banana      $  0.69         5
            4. cookie      $  0.50         2
            5. donut       $  1.00         3
            6. egg         $  3.88         1
            7. fish        $  5.88         2
            8. milk        $  2.99         4
            9. yogurt      $  6.38         2

    Use valgrind to make sure there are no memory errors in your code.

Step 4: Submit your assessment.
        In order to submit your files you type:

~robert.martin4/bin/turnin submit prof=robert.martin4 course=cs162 file1 file2 file3 ...

        This will submit file1, file2, file3 (and any more files you specify) to the
        turnin depository for me (robert.martin4) and for the specified
        course. Make sure you send me the header files (item.h, main.h, and groceryList.h)
        and the code files(3 of them: item.cpp, groceryList.cpp, and main.cpp).
        The turnin program will give you a "receipt" identifier that you can keep if
        you want to have a record of turning in the file(s).

        **** Please submit all of the files in the directory, including the .txt file ****

        If you have multiple files to turn in you can either call turnin with multiple
        files listed on the command line, or use zip or tar to create a single bundle and
        turn that in. Either way is fine. You can zip an entire director with the -r option.
        If your directory is called assessment3A, you can go to the parent directory and type:
        zip -r myNameAssessment3.zip assessment3A
        It's not important, but you should probably replace myName with your actual name.

        You can call this command as many times as you want. Each subsequent call does
        not overwrite the previous one.
