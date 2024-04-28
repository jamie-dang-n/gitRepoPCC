Assessment 1 version B, CS162 Summer 2023, Portland Community College
Instructor: Robert Martin

These are the instructions for the first assessment for cs162, Summer 2023

Step 1: Compile the code in this directory using the command: make
        After the make command there will be a new executable in the directory.
        The executable will be called: program
Step 2: Run the program to make sure it works. Type ./program to run it.
        You should see that the program successfully loaded and printed 9
        cars on the car dealership lot. The list price is the selling price of
        the car to the customer. The dealer cost is how much was paid by the
        dealership to buy the car.
Step 3: Open the code files and the header files in vim or vi, and add
        the following functions to the CarLot class and/or Car class:

        double Car::calculateRevenue() const;
          // This function will calculate the revenue by selling a car.
          // Subtract the dealerCost from the listPrice to get total revenue.
          // For example, the difference between dealerCost and listPrice for
          // the Honda Pilot is: 37976 - 32433 = 5543.

        double CarLot::totalRevenue() const;
          // This function will calculate the total potential revenue of all
          // cars on the lot, if all the cars were sold. Use the
          // Car::calculateRevenue() function to get all the potential
          // revenue for each car, and then add those values together.
          // I would suggest a loop with a running total.
        
        Add the member function prototypes to the header files and the function
        definitions to the code files. Add the necessary calls to your new member
        functions in carLot.cpp and main.cpp files.
Step 4: Submit your assessment.
        In order to submit your files you type:

~/robert.martin4/bin/turnin submit prof=robert.martin4 course=cs162 file1 file2 file3 ...

        This will submit file1, file2, file3 (and any more files you specify) to the
        turnin depository for me (robert.martin4) and for the specified
        course. It will give you a "receipt" identifier that you can keep if you want
        to have a record of turning in the file(s).

        You can call this command as many times as you want. Each subsequent call does
        not overwrite the previous one.

        If you have multiple files to turn in you can either call turnin with multiple
        files listed on the command line, or use zip or tar to create a single bundle
        and turn that in. Either way is fine. 

