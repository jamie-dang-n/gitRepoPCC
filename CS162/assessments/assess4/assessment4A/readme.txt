Assessment 4 version A, CS162 Summer 2023, Portland Community College
Instructor: Robert Martin

These are the instructions for the fourth assessment for cs162, Summer 2023

Step 1: Compile the code in this directory using the command: make
        After the make command there will be a new executable in the directory.
        The executable will be called: program
Step 2: Run the program to make sure it works. Type ./program to run it.
        You should see that the program successfully loaded and printed 8
        grocery items placed in a shopping cart. The price is for each 1 item
        in the cart. The count value is how many of each item is in the cart.
Step 3: Open the code files and the header files in vim or vi, and add
        the following functions to the GroceryList class:
         
        void GroceryList::removeFirst();
        // Remove the first Node from the linked list.
        // Don't forget to subtract 1 from itemCount.

        void GroceryList::lastToFirst();
        // Locate the last Node in the linked list, remove it from the end,
        // and then make it the first node. Put another way, move the last
        // Node to the beginning of the list, so that it is the first Node.
        // One way to find the last node in a linked list is to check whether
        // the next field of the current node is equal to nullptr.
        // If not then move down the list.
        
        Add the member function prototypes to the header file and the function
        definitions to the code file. Add the following statements (or some
        approximation) to the main.cpp file where it says to "fill in the code":
          cout << "\nModifying the list." << endl;
          shoppingCart.removeFirst();
          shoppingCart.lastToFirst();
          cout << "The revised list is:" << endl;
          shoppingCart.printItems();

        **** Call removeFirst() before calling lastToFirst() ****
        After adding these statements, the output might look like:
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

            Modifying the list.
            The revised list is:
            Name             Price     Count
            ----             -----     -----
            1. yogurt      $  6.38         2
            2. banana      $  0.69         5
            3. cookie      $  0.50         2
            4. donut       $  1.50         3
            5. egg         $  3.88         1
            6. fish        $  8.88         2
            7. milk        $  4.99         4

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

        **** PLEASE submit all of the files in the directory, including the .txt file ****

        If you have multiple files to turn in you can either call turnin with multiple
        files listed on the command line, or use zip or tar to create a single bundle and
        turn that in. Either way is fine. You can zip an entire director with the -r option.
        If your directory is called assessment4A, you can go to the parent directory and type:
        zip -r myNameAssessment4.zip assessment4A
        It's not important, but you should probably replace myName with your actual name.

        You can call this command as many times as you want. Each subsequent call does
        not overwrite the previous one.
