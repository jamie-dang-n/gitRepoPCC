//*****************************************************************************
// Author:           Jamie Dang
// Assignment:       Assignment 1
// Date:             4/7/2023
// Description:      This program reads in a number of assignments from the
//                   user. It then reads the assignment scores, the midterm and
//                   final exam scores. It’ll calculate the average assignment
//                   scores and then calculate the final numeric score using the
//                   average of assignments, the midterm score and final exam score.
//                   The final letter grade is given by the final numberic score.
// Input:            int userInt (in readInt()), double num (in readScore())
//                   double midtermScore and finalExamScore (both in getInput())
// Output:           double finalNumScore, char finalLetterGrade (both in main())
// Sources:          n/a
//*****************************************************************************

#include <iomanip>
#include <iostream>
#include <limits> //for cin.ingore()
#include <string>
using namespace std;

// Constants
const double EXAM_WEIGHT = 0.2;
const double ASSIGN_WEIGHT = 0.6;

// Function Prototypes
int readInt(string prompt);
void readScore(string prompt, double &num);
double assignAverage(int numAssigns);
void getInput(double &midtermScore, double &finalExamScore);
double calcFinalScore(double assignAvg, double midtermScore, double finalScore);
void calcLetterGrade(double finalScore, char &letter);
void printWelcInstructions();

// Main function
int main() {
	// Variables
	double finalNumScore = 0.0;
	char finalLetterGrade;
	int numAssignments = 0;
	double assignAvg = 0.0;
	double midtermScore = 0.0;
	double finalExamScore = 0.0;
	
	// Input
	printWelcInstructions();
	numAssignments = readInt("Enter the number of assignments (0 to 10): ");
	assignAvg = assignAverage(numAssignments);
	cout << endl; // blank line
	getInput(midtermScore, finalExamScore);
	cout << endl; //blank line
	finalNumScore = calcFinalScore(assignAvg, midtermScore, finalExamScore);
	calcLetterGrade(finalNumScore, finalLetterGrade);

	// Output
	cout << endl; // blank line
	cout << fixed << setprecision(1);
	cout << "Your Final Numeric score is " << finalNumScore << endl;
	cout << "Your Final Grade is " << finalLetterGrade << endl;
	cout << endl; // blank line
	cout << "Thank you for using my Grade Calculator!" << endl;

	return 0;
}

// Name:   printWelcInstructions()
// Desc:   This function prints the welcome message and instructions to the suer
// Input:  none
// Output: The welcome message
// Return: none
void printWelcInstructions(){
	cout << "Welcome to my Final Grade Calculator!" << endl;
	cout << "Please enter the following information and I will calculate your\nFinal Numerical Grade and Letter Grade for you!" << endl;
	cout << "The number of assignments must be between 0 and 10." << endl;
	cout << "All scores must be between 0 and 4." << endl;
	cout << endl; // blank line
}

// Name:   readInt()
// Desc:   This function reads an integer from the user and returns it
// Input:  None
// Output: Maybe an Error message, the prompt
// Return: int userInt 
int readInt(string prompt) {
	int userInt;
	cout << prompt;
	cin >> userInt;
	while(cin.fail() || cin.peek() != '\n'|| (userInt < 0 || userInt > 10)) {
		cout << "Illegal Value! Please try again!!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << prompt;
		cin >> userInt;
	}
	return userInt;
}

// Name:   readScore(string prompt, double &num)
// Desc:   This function reads in assignment scores from the user to the double variable num by reference
// Input:  double num by reference
// Output: Maybe an error message, the prompt
// Return: None
void readScore(string prompt, double &num) {
	cout << prompt;
	cin >> num;
	while(cin.fail() || cin.peek() != '\n' || (num < 0 || num > 4)) {
		cout << "Illegal Score! Please try again!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << prompt;
		cin >> num;
	}
}

// Name:   assignAverage(int numAssigns)
// Desc:   this function takes the number of assignments and calculatees the assignment average
// input:  int numAssigns
// Output: "Enter score" prompt
// return: double assignAvg
double assignAverage(int numAssigns) {
	string prompt;
	double assignScore = 0.0;
	double assignSum = 0.0;
	double assignAvg = 0.0;
	for (int i = 0; i < numAssigns; i++) {
		prompt = "Enter score " + to_string(i + 1) + ": ";
		readScore(prompt, assignScore);
		assignSum += assignScore;	
	}
	assignAvg = assignSum / numAssigns;
	return assignAvg;
}

// Name:   getInput(double &midtermScore, double &finalExamScore)
// Desc:   This function gets input from the user to record their final exam and midterm scores
// Input:  double midtermScore, double finalExamScore, both by reference
// Output: Prompts for midtermScore and finalExamScore
// Return: none
void getInput(double &midtermScore, double &finalExamScore) {
	string midtermPrompt = "Enter your midterm exam score: ";
	string finalPrompt = "Enter your final exam score: ";
	readScore(midtermPrompt, midtermScore);
	readScore(finalPrompt, finalExamScore);
}

// Name:   calcFinalScore(double assignAvg, double midtermScore, double finalScore)
// Desc:   This function calculates the final numeric grade of the student from their 
// 	   assignment average, midterm score, and final exam score (weighted)
// Input:  double assignAvg, double midtermScore, double finalScore
// Output: None
// Return: double finalNumScore
double calcFinalScore(double assignAvg, double midtermScore, double finalScore) {
	double finalNumScore = 0.0;
	finalNumScore = (finalScore * EXAM_WEIGHT) + (midtermScore * EXAM_WEIGHT) + (assignAvg * ASSIGN_WEIGHT);
	return finalNumScore;
}


// Name:   calcLetterGrade(double finalScore, char &letter) 
// Desc:   This function calculates the final letter grade based on the given table,
// 	   using the finalScore of the student from calcFinalScore()
// Input:  double finalScore, char letter by reference
// Output: None
// Return: None
void calcLetterGrade(double finalScore, char &letter) {
	if (finalScore >= 3.3) {
		letter = 'A';
	} else if (finalScore >= 2.8) {
		letter = 'B';
	} else if (finalScore >= 2.0) {
		letter = 'C';
	} else if (finalScore >= 1.2) {
		letter = 'D';
	} else {
		letter = 'F';
	}
}






