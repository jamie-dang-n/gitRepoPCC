//This is the client file or the driver file
#include "chicks.h"
#include "tools.h"
//main
int main()
{
    ChickType chicks[CAP], returnList[CAP];
    int size = 0;
	  int nums = 0, option = 0;
    readInput(chicks, size);
    outputData(chicks, size);
	do
	{
		mainMenu();
		option = readOption();
		exeOption(option, chicks, size);
		outputData(chicks, size);
	}while(option != 4);
	
	outputData(returnList, nums);
  	cout << "Thank you for using my chicks program!" << endl;
	return 0;
}

