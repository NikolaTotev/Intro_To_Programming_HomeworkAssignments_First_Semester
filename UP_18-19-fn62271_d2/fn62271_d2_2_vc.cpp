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
void CheckLength(string inputString_B, string inputString_C);
int main()
{
	//String B is the string in which we will look for the longest substring that is created from repeating the String C
	string inputString_B = "acbcbcbbbcbcbcalk";

	//String C is the string that the substring in B should be made of.
	string inputString_C = "bc";

	//======= Input Handling =========
	cin >> inputString_B;
	while (1)
	{
		if (inputString_B.length() > 100)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> inputString_B;
		}
		if (inputString_B.length() <= 100)
		{
			break;
		}
	}
	cin >> inputString_C;

	CheckLength(inputString_B, inputString_C);
}

void CheckLength(string inputString_B, string inputString_C)
{
	//============================================================================================================

//The Following 2 variables are used in determining the longest substring in B made by repeating the string C

//startVal is used as the position from which the check for the substring should start.
	int startVal = 0;
	//lengthOf_C is used to store the length of the string C.
	int lengthOf_C = inputString_C.length();

	//============================================================================================================


	//============================================================================================================

	//The following variables are used to store information about the length of the longest substring 
	//and the index it starts from

	//Stores the length of the current substring that is generated.
	int subStringLength_temp = 0;

	//Stores the current max length of the substring. 
	//It is given the value of subStringLength_temp every time subStringLength_temp larger than the current value. 
	int currentMaxStringLength = 0;

	//currentIndex is used to temp store the index from which the longest substring starts from
	int currentIndex = -1;

	//currentIndexWithLongestString is used to temp store the index from which the longest substring starts from
	int currentIndexWithLongestString = -1;

	//============================================================================================================

	/*
	 * How the algorithm for finding the longest substring works:
	 * The for loop iterates n times (n = inputString_B.length()/inputString_C.length()) through the string, each time
	 * a substring of the String B is taken and compared to the string C, if it is equal then we can say that the length of the
	 * substring comprised of the string C is equal to the subStringLength_temp + the length of C. At the same time the index at which the substring
	 * started is recorded.
	 * Once  the substring ends, or the loop is finished the length of the substring is set to max if the current substring length is longer than the current max,
	 * and it is ignored otherwise.
	 *
	 * Example
	 * String B = acbcbcbbbcbcbcalk
	 * String C = bc
	 *
	 * ===================================================================================================================================
	 * Iteration 1:
	 * startVal = 0;
	 * lengthOf_C = 2;
	 *
	 * inputString_B.substr(startVal, lengthOf_C) = ac
	 * inputString_B.substr(startVal, lengthOf_C) != inputString_C
	 *
	 * Moving on. There is no use advanced with the length of C because if it is advanced with 1 then bcbc would not be a valid substring.
	 *
	 * ===================================================================================================================================
	 * Iteration 2:
	 * startVal = 2;
	 * lengthOf_C = 2;
	 *
	 * inputString_B.substr(startVal, lengthOf_C) = bc
	 * inputString_B.substr(startVal, lengthOf_C) == inputString_C
	 *
	 * Current max length  = 2
	 *
	 * Moving on.
	 * ===================================================================================================================================
	 * Iteration 3:
	 * startVal = 4;
	 * lengthOf_C = 2;
	 *
	 * inputString_B.substr(startVal, lengthOf_C) = bc
	 * inputString_B.substr(startVal, lengthOf_C) == inputString_C
	 *
	 * Current max length  = 3
	 *
	 * Moving on.
	 *
	 * ===================================================================================================================================
	 *
	 * et cetera, this is repeated until the end of the string is reached.
	 *
	 */
	for (int numberOfItterations = 0; numberOfItterations <= (inputString_B.length() / inputString_C.length()); numberOfItterations++)
	{
		if (inputString_B.substr(startVal, lengthOf_C) == inputString_C)
		{
			subStringLength_temp += 1 * inputString_C.length();

			if (currentIndex == -1)
			{
				currentIndex = startVal;
			}

		}
		else
		{
			if (subStringLength_temp > currentMaxStringLength)
			{
				currentMaxStringLength = subStringLength_temp;
				currentIndexWithLongestString = currentIndex;
			}
			subStringLength_temp = 0;
			currentIndex = -1;
		}
		startVal += inputString_C.length();
	}

	//Once the algorithm is finished the max length of the substring are printed and the index is starts from are printed to the console.
	cout << "Index: " << currentIndexWithLongestString << endl;
	cout << "Length: " << currentMaxStringLength << endl;
}
