/**
*
* Solution to homework task 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Nikola Totev
* @idnumber 62271
* @task 4
* @compiler VC
*
*/


// Ex 4 - Drawing a square that is rotated 45*. Side length and symbol with which to draw are set by the user.
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	//Setting default character as "o"
	char charToUse = 'o';
	int sideLength = 0;
	int columnOffset = 0;
	int distanceFromCenter = 0;

	int numberOfTotalRows = 0;
	int columnOffsetBeforeMiddle = 0;
	int columnOffsetAfterMiddle = 0;
	const int correctionINDEX = 20;
	int correctedSide = 0;

	cout << "Please input the side of the square and the character you want to use" << endl;
	cin >> sideLength >> charToUse;

	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please input a number!" << endl;
			cin >> sideLength >> charToUse;
		}
		if (!cin.fail())
		{
			break;
		}
	}

	numberOfTotalRows = (sideLength * 2) - 1;
	correctedSide = sideLength + correctionINDEX;

	if (numberOfTotalRows <= 25)
	{
		//First for loop is for looping through all the rows.
		for (int currentRow = 1; currentRow <= numberOfTotalRows; currentRow++)
		{
			if (currentRow <= sideLength)
			{
				columnOffset = currentRow - 1;
			}
			else
			{
				distanceFromCenter++;
				columnOffset = (sideLength - distanceFromCenter) - 1;
			}

			//Offsets used for columns. These are used for printing 
			columnOffsetBeforeMiddle = correctedSide - columnOffset;
			columnOffsetAfterMiddle = correctedSide + columnOffset;

			if (currentRow != 1)
			{
				cout << endl;
			}

			//Second loop if for printing out the columns in every row.
			for (int collumn = 1; collumn <= numberOfTotalRows + correctionINDEX; collumn++)
			{
				if (collumn >= columnOffsetBeforeMiddle && collumn <= columnOffsetAfterMiddle || collumn == correctedSide)
				{
					cout << setw(2) << charToUse;
				}
				else
				{
					cout << "  ";
				}
			}
		}
	}
	else
	{
		cout << "The length of the side is outside of the allowed limit (13)" << endl;
	}
}




