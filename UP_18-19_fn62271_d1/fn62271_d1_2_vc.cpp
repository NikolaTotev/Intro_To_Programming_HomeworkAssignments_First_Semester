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

// Ex 2 - Finds how many times a given number is repeated in a given number.

#include <iostream>
using namespace std;

bool inputIsValid(long, long, long);
int numberFrequencyChecker(long inputNumber, int numberToLookFor);

int main()
{
	const long LIMIT = pow(2, 31);
	const long TOP_LIMIT = LIMIT - 1;
	const long BOTTOM_LIMIT = -LIMIT;

	long inputNumber = 0;
	int numberToLookFor = 0;

	cout << "Please input a number and the number that you are looking for:" << endl;
	cin >> inputNumber >> numberToLookFor;
	while (1)
	{

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please input a valid number!" << endl;

			cin >> inputNumber >> numberToLookFor;

		}
		if (!cin.fail() && inputIsValid(inputNumber, TOP_LIMIT, BOTTOM_LIMIT))
		{
			break;
		}
	}

	cout << numberFrequencyChecker(inputNumber, numberToLookFor);

}

int numberFrequencyChecker(long inputNumber, int numberToLookFor)
{
	int tracker = 0;

	long absInputNumber = (inputNumber < 0) ? -inputNumber : inputNumber;
	while (absInputNumber > 0)
	{
		if (absInputNumber % 10 == numberToLookFor)
		{
			tracker++;
		}
		absInputNumber = absInputNumber / 10;
	}
	return tracker;
}

bool inputIsValid(long inputNumber, long topLimit, long bottomLimit)
{
	if (inputNumber <= topLimit && inputNumber >= bottomLimit)
	{
		return true;
	}

	return false;
}


