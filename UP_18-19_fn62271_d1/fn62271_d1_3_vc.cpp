/**
*
* Solution to homework task 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Nikola Totev
* @idnumber 62271
* @task 3
* @compiler VC
*
*/


//Four bit calculator.
#include <iostream>
using namespace std;
#include <iomanip>
void Addition(int, int);
void Subtraction(int, int);
void Multiplication(int, int);
void Division(int, int);
void getOperation(int, int, int);
void validateInput(int inputOne, int inputTwo, int operationNumber, int numLimit, int opLimit);
void getInput(int NUM_LIMIT, int OP_LIMIT);
void printInfoMessage();
int main()
{

	const int NUMBER_LIMIT = 15;
	const int OP_LIMIT = 3;
	getInput(NUMBER_LIMIT, OP_LIMIT);
}

//Prints the initial info message for the user.
void printInfoMessage()
{
	cout
		<< " -------------------------" << endl
		<< " Allowed numbers - 0 to 15" << endl
		<< " -------------------------" << endl
		<< " Available operations" << endl
		<< " 0 - Addition" << endl
		<< " 1 - Subtraction" << endl
		<< " 2 - Multiplication" << endl
		<< " 3 - Division" << endl
		<< " -------------------------" << endl
		<< " Input sequence: <Input Number One> <Input Number Two> <Number of desired operation" << endl;
}

//Handles getting the input from the user and validating that its actually numbers.
void getInput(int NUM_LIMIT, int OP_LIMIT)
{
	int inputOne = 0;
	int inputTwo = 0;
	int opeationNumber = 0;

	printInfoMessage();
	cin >> inputOne >> inputTwo >> opeationNumber;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please input a number!" << endl;
			printInfoMessage();
			cin >> inputOne >> inputTwo >> opeationNumber;
		}
		if (!cin.fail())
		{
			validateInput(inputOne, inputTwo, opeationNumber, NUM_LIMIT, OP_LIMIT);
			break;
		}
	}
}
//Checks if the input that has been give is within the allowed limits.
void validateInput(int inputOne, int inputTwo, int operationNumber, int numLimit, int opLimit)
{
	bool inputOneInLimit = (inputOne > 0 && inputOne <= numLimit);
	bool inputTwoInLimit(inputTwo > 0 && inputTwo <= numLimit);
	bool opNumberInLimit(operationNumber >= 0 && operationNumber <= opLimit);

	if (inputOneInLimit && inputTwoInLimit)
	{
		if (opNumberInLimit)
		{
			getOperation(operationNumber, inputOne, inputTwo);
		}
		else
		{
			cout << "Please enter a valid operation number" << endl;
			getInput(numLimit, opLimit);
		}
	}
	else
	{
		cout << "Wrong Input" << endl;
		getInput(numLimit, opLimit);
	}
}

//Handles calling the desired operation based on the input from the user.
void getOperation(int opNumber, int inputOne, int inputTwo)
{
	switch (opNumber)
	{
	case(0):
		Addition(inputOne, inputTwo);
		break;
	case(1):
		Subtraction(inputOne, inputTwo);
		break;
	case(2):
		Multiplication(inputOne, inputTwo);
		break;
	case(3):
		Division(inputOne, inputTwo);
		break;
	}
}

//Handles Addition
void Addition(int inputOne, int inputTwo)
{
	cout << "The result is: " << (inputOne + inputTwo) % 16;
}

//Handles Subtraction
void Subtraction(int inputOne, int inputTwo)
{
	int result = (inputOne - inputTwo);

	if (result > 0)
	{
		cout << "The result is: " << result % 16;

	}
	else
	{
		cout << "The result is: " << 16 - (abs(result) % 16);

	}
}
//Handles Multiplication
void Multiplication(int inputOne, int inputTwo)
{
	cout << "The result is: " << (inputOne * inputTwo) % 16;
}
//Handles Division
void Division(int inputOne, int inputTwo)
{
	cout << "The result is: " << (inputOne / inputTwo) % 16;
}