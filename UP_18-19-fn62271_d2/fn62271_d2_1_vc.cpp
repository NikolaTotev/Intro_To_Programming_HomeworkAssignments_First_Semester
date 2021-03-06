/**
*
* Solution to homework assignment 2
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

// fn62271_d2_1_vc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
using namespace std;
void printError();
const int ARR_LENGTH = 5;
void Shift(int inputArray[ARR_LENGTH], int length, int shiftAmount);
void printArray(int inputArray[]);
int main()
{
	int numArray[ARR_LENGTH] = { 6, 5, 6, 0, 3 };
	int arrayLength = ARR_LENGTH;
	int shiftAmount;

	cin >> shiftAmount;
	//This while loop handles checking if the input is a number.
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> shiftAmount;
		}
		if (!cin.fail())
		{
			break;
		}
	}

	Shift(numArray, arrayLength, shiftAmount);
}

// Handles shifting the array  either to the right or the left.
void Shift(int inputArray[ARR_LENGTH], int length, int shiftAmount)
{
	//Temp element used to store the values of the elements at the end of the array.
	int tempStorage = 0;

	//Checks if the value of shiftAmount complies with the requirement |shiftAmount| being less than length.
	if (abs(shiftAmount) < length)
	{
		//If it is zero it doesn't have to shift anything so it just prints out the array. 
		if (shiftAmount == 0)
		{
			printArray(inputArray);
			return;
		}

		//If shiftAmount is more than zero the array is shifted to the right.
		if (shiftAmount > 0)
		{
			/*
			 * The algorithm for shifting the array to the left is as follows:
			 * The temp variable is given assigned the value of the last element in the array.
			 * For each element in the array the element at position [i-1] is given the value of the element at [i-2].
			 * This is repeated for each element. Once it is finished the last element of the array is given the value of temp.
			 * This is repeated n times n = numberOfShifts.
			 */
			for (int numberOfShifts = shiftAmount; numberOfShifts > 0; numberOfShifts--)
			{
				int tempStorage = inputArray[ARR_LENGTH - 1];
				for (int i = ARR_LENGTH; i > 0; i--)
				{
					inputArray[i - 1] = inputArray[i - 2];
				}
				inputArray[0] = tempStorage;
			}
			printArray(inputArray);
		}

		//If shiftAmount is less than zero the array is shifted to the left.
		if (shiftAmount < 0)
		{
			/*
			 * The algorithm for shifting the array to the left is as follows:
			 * The temp variable is given assigned the value of the first element in the array.
			 * For each element in the array the element at position [i] is given the value of the element at [i+1].
			 * This is repeated for each element. Once it is finished the last element of the array is given the value of temp.
			 * This is repeated n times n = numberOfShifts.
			 */
			for (int numberOfShifts = shiftAmount; numberOfShifts < 0; numberOfShifts++)
			{
				tempStorage = inputArray[0];
				for (int i = 0; i < ARR_LENGTH - 1; i++)
				{
					inputArray[i] = inputArray[i + 1];
				}

				inputArray[ARR_LENGTH - 1] = tempStorage;
			}
			printArray(inputArray);
		}
	}
	else
	{
		printError();
	}
}

//Handles printing the array it is given. 
//This code was put into a separate function because it was repeated multiple times in the code above.
void printArray(int inputArray[])
{
	for (int i = 0; i < ARR_LENGTH; i++)
	{
		cout << inputArray[i];
	}
}

//Handles printing the error message.
void printError()
{
	cout << "Error!";
}
