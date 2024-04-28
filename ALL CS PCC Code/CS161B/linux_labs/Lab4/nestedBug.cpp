#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

int main()
{
	char board[ROWS][COLS] = {{'X', 'O', 'X'},
				  {'O', 'X', 'O'},
				  {'X', 'O', 'X'}};
	cout << "Printing the board!\n";
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			cout << board[i][j] << "\t";
		}
		cout << endl;
	}
return 0;
}
