/**
*
* Solution to homework task 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Nikola Totev
* @idnumber 62271
* @task 2
* @compiler VC
*
*/

#include <iostream>
#include <string>
using namespace std;
const int MATRIX_SIZE = 6;
bool CheckRow(int currentRow, int inputMatrix[MATRIX_SIZE][MATRIX_SIZE]);
bool CheckColumn(int currentColumn, int inputMatrix[MATRIX_SIZE][MATRIX_SIZE]);
void AnalyseMatrix(int inputMatrix[MATRIX_SIZE][MATRIX_SIZE], int numberToLookFor);
int CheckNumber(string currentNum, string numberToFind, int currentTimesEncountered);
int main()
{
	int masterArr[MATRIX_SIZE][MATRIX_SIZE]
	{
		{5,4,3,8,0,6},
		{9,4,5,1,0,2},
		{8,5,8,0,6,1},
		{0,9,6,8,4,2},
		{6,1,0,2,6,1},
		{2,1,8,4,2,6},
	};

	//Variation of the masterArr, for checking different numbers.
	/*int masterArr[MATRIX_SIZE][MATRIX_SIZE]
	{
		{5,4,3,2,0,5},
		{9,4,5,6,0,4},
		{8,5,2,6,6,4},
		{0,6,6,2,5,2},
		{6,1,6,1,2,1},
		{2,1,6,2,4,2},
	};*/
	int numberToFind = 0;

	cin >> numberToFind;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please input a number, not a letter!" << endl;
			cin >> numberToFind;
		}
		if (!cin.fail())
		{
			break;
		}
	}
	AnalyseMatrix(masterArr, numberToFind);
}

//Function that examines the matrix
void AnalyseMatrix(int inputMatrix[MATRIX_SIZE][MATRIX_SIZE], int numberToLookFor)
{
	//=======================================================
	//Booleans used for checking if the matrix is simplified;
	bool RowsAreValid = false;
	bool ColumnsAreValid = false;
	bool MatrixIsSimplified = false;
	//=======================================================

	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		if (CheckRow(i, inputMatrix) == false || CheckColumn(i, inputMatrix) == false)
		{
			break;
		}
		RowsAreValid = CheckRow(i, inputMatrix);
		ColumnsAreValid = CheckColumn(i, inputMatrix);
	}

	//If the matrix is simplified then the algorithm for counting the number of times the number we want to find is encountered is started
	//If the matrix isn't simplified this process is omitted.
	if (RowsAreValid && ColumnsAreValid)
	{
		string numberToLookFor_String = to_string(numberToLookFor);
		string currentNumber = "#";
		int timesFound = 0;
		for (int i = 0; i < 2; i++)
		{
			//===================================================================================================
			//First the reverse pass is executed, starting from the end of row and end of the column, for every row and column
			if (i == 0)
			{
				for (int currentRow = 0; currentRow < MATRIX_SIZE; currentRow++)
				{
					currentNumber = "#";
					for (int i = MATRIX_SIZE; i > 0; i--)
					{
						currentNumber += to_string(inputMatrix[currentRow][i - 1]);
					}
					timesFound = CheckNumber(currentNumber.substr(1), numberToLookFor_String, timesFound);
				}


				for (int currentColumn = 0; currentColumn < MATRIX_SIZE; currentColumn++)
				{
					currentNumber = "#";
					for (int i = MATRIX_SIZE; i > 0; i--)
					{
						currentNumber += to_string(inputMatrix[i][currentColumn]);
					}
					timesFound = CheckNumber(currentNumber.substr(1), numberToLookFor_String, timesFound);
				}


			}
			//===================================================================================================

			//===================================================================================================
			//After that the normal order start to end for every row and column
			else
			{
				for (int currentRow = 0; currentRow < MATRIX_SIZE; currentRow++)
				{
					currentNumber = "#";
					for (int i = 0; i < MATRIX_SIZE; i++)
					{
						currentNumber += to_string(inputMatrix[currentRow][i]);
					}
					timesFound = CheckNumber(currentNumber.substr(1), numberToLookFor_String, timesFound);
				}


				for (int currentColumn = 0; currentColumn < MATRIX_SIZE; currentColumn++)
				{
					currentNumber = "#";
					for (int i = 0; i < MATRIX_SIZE; i++)
					{
						currentNumber += to_string(inputMatrix[i][currentColumn]);
					}
					timesFound = CheckNumber(currentNumber.substr(1), numberToLookFor_String, timesFound);
				}
			}
			//===================================================================================================

		}
		//Output of the times the element is found.
		cout << timesFound;
	}
	else
	{
		cout << "Can't find number, given matrix is not simplified.";
	}


}

/*
 * Function that handles checking if the number we are looking for is in the current row or column that we are examining.
 * The rows and columns are stored in a string and a loop checks if the sequence of numbers is present in the string.
 * If it is that means we have encountered the number and the counter is advanced with one.
 */
int CheckNumber(string currentNum, string numberToFind, int currentTimesEncountered)
{
	int startPoint = 0;
	for (int i = 0; i < currentNum.length(); i++)
	{
		if (currentNum.substr(startPoint, numberToFind.length()) == numberToFind)
		{
			currentTimesEncountered++;
		}
		startPoint++;
	}
	return currentTimesEncountered;
}

//Handles checking if a given row is simplified.
bool CheckRow(int currentRow, int inputMatrix[MATRIX_SIZE][MATRIX_SIZE])
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		if (inputMatrix[currentRow][i] < 0 && inputMatrix[currentRow][i] > 9)
		{
			return false;
		}
	}
	return true;
}

//Handles checking if a column row is simplified.
bool CheckColumn(int currentColumn, int inputMatrix[MATRIX_SIZE][MATRIX_SIZE])
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		if (inputMatrix[i][currentColumn] < 0 && inputMatrix[i][currentColumn] > 9)
		{
			return false;
		}
	}
	return true;
}

