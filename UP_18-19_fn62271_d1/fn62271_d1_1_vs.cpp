/**
*
* Solution to homework task 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Nikola Totev
* @idnumber 62271
* @task 1
* @compiler VC
*
*/

#include <iostream>
using namespace  std;

void inputHandler();
bool inputIsValid(int inputNumber, int maxLimit);
void calculate(int currentMAX, int currentMIN);
int main()
{
	inputHandler();
	return 0;
}
void inputHandler()
{
	const int MAX_NUMBER = pow(2, 16);

	int inputNumber = 0;

	int currentMaximum = 0;
	int currentMinimum = 0;
	int inputAmountTracker = 0;

	while (inputNumber >= 0)
	{
		cout << "Please input a number" << endl;
		cin >> inputNumber;
		//This while loop handles checking if the input is a number.
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please input a number, not a letter!" << endl;
				cin >> inputNumber;
			}
			if (!cin.fail())
			{
				break;
			}
		}

		//This if checks if the number is within the limits.
		if (inputIsValid(inputNumber, MAX_NUMBER))
		{
			if (inputAmountTracker == 0)
			{
				currentMaximum = inputNumber;
				currentMinimum = inputNumber;
				inputAmountTracker++;
			}
			if (inputNumber > currentMaximum)
			{
				currentMaximum = inputNumber;
				inputAmountTracker++;
			}
			if (inputNumber < currentMinimum && inputNumber >= 0)
			{
				currentMinimum = inputNumber;
				inputAmountTracker++;
				;
			}
		}
		else
		{
			cout << "Please input a valid number" << endl;
		}
	}

	if (inputAmountTracker >= 2)
	{
		calculate(currentMaximum, currentMinimum);
	}
	else
	{
		cout << "Please input more than 2 numbers" << endl;
	}
}

//Function that handles checking if the input is withing the limits.
bool inputIsValid(int inputNumber, int maxLimit)
{
	if (inputNumber < maxLimit)
	{
		return true;
	}

	return false;
}

void calculate(int currentMAX, int currentMIN)
{
	int result = 0;
	result = abs(currentMAX - currentMIN);
	cout << "The result is:" << endl;
	cout << result;
}


