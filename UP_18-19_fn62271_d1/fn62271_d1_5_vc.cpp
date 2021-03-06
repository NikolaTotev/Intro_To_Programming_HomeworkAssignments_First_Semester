/**
*
* Solution to homework task 5
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Nikola Totev
* @idnumber 62271
* @task 5
* @compiler VC
*
*/


// Ex 5 - Finding colors at given coordinates.
#include <iostream>
using namespace std;

#pragma region Function declarations
//Declaring the functions responsible for the mathematical calculations.
double calcInputRadius(double);
double calcXY(double, double, bool);

//Declaring the functions for checking position of the points.
bool pointInSmallCircle(double, double, double, bool);
bool pointInMediumCircle(double, double, double, bool);
bool pointInBigCircle(double, double, double, bool);
bool pointIsUndefined(double, double, double, bool);
bool pointInOrOnMainCircle(double, double, double);

//Declaring the functions for outputting the results.
void sayPointIsWhite();
void sayPointIsBlack();
void sayPointIsUndefined();
void sayPointIsOutside();
#pragma  endregion 

int main()
{
#pragma region Program constants definitions
	//Defining radii of circles present in the drawing.
	const double SMALL_RADIUS = 2;
	const double MEDIUM_RADIUS = 3;
	const double LARGE_RADIUS = 6;
#pragma endregion 

	//Defining variables to store input of the point the user chooses.
	double coord_X = 0;
	double coord_Y = 0;

	int inputValidatorIndex = 1;
	//If this were a program for a user the following lines of code with "cin<<" would help the user to input the correct variables
	cout << "Please input your X coordinate" << endl;
	cin >> coord_X;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please input a number!" << endl;
			cin >> coord_X;
		}
		if (!cin.fail())
		{
			break;
		}

	}

	cout << "Please input your Y coordinate" << endl;
	cin >> coord_Y;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please input a number!" << endl;
			cin >> coord_Y;
		}
		if (!cin.fail())
		{
			break;
		}

	}


	//Boleans that check weather or not the point is at an undefined color i.e. at the border of a circle.
	bool undefinedForSmall = pointIsUndefined(coord_X, coord_Y, SMALL_RADIUS, true);
	bool undefinedForMedium = pointIsUndefined(coord_X, coord_Y, MEDIUM_RADIUS, true);
	bool undefinedForLarge = pointIsUndefined(coord_X, coord_Y, LARGE_RADIUS, false);
	bool edgeCaseZeroZero = (coord_Y == 0 && coord_X == 0);

	/*First check is weather or not the point is inside the biggest circle, if it's not,
	 * then logically it's not in the other circles inside the big one.
	 * Therefore if it's not inside the big circle the program directly outputs "Outside" and does not do any other checks
	 * If the point is inside the big circle the program executes the other checks.
	 */

	if (pointInOrOnMainCircle(coord_X, coord_Y, LARGE_RADIUS))
	{
#pragma region Edge case checks
		//The first checks are for specific edge cases.
		//They require different checks from other cases.
#pragma region Edge Case 1
		//Edge Case 1. If both X and Y are 0. In this case the point is at an undefined color.
		if (edgeCaseZeroZero)
		{
			sayPointIsUndefined();
		}

		/*Edge Case 2. If Y is 0.
		By looking at the given diagram we can easily see that:
		When Y = 0 if:
		X is positive - Black,
		X is negative - White,
		X == 6 or -6 Undefined
		X > 6 or  < -6 its Outside
		*/
#pragma endregion 
#pragma  region Edge Case 2
		else if (coord_Y == 0)
		{
			if (coord_X > 0)
			{
				sayPointIsBlack();
			}
			else
			{
				sayPointIsWhite();
			}


		}
#pragma endregion 
#pragma  region Edge Case 3
		/*

		Edge Case 2. If X is 0.
		By looking at the given diagram we can easily see that:
		When X = 0 if:

		For Postitive Y's   For Negative Y's
		0 < Y < 2 : White	0 > Y > -2 : Black
		2 < Y < 4 : Black	-2 > Y > -4 : White
		4 < Y < 6 : White	-4 > Y > -6 : Black
		Y == 6 : Undefined	Y == -6 : Undefined
		Y > 6 : Outside		Y < -6 : Outside

		*/
		else if (coord_X == 0)
		{
			//Boleans for checking if when X is zero Y is within small or medium circle bounds. 
			//The main formula is not used here because it is considered one of the edge cases.
			bool inBlackSmallCircleBounds = (coord_Y > SMALL_RADIUS && coord_Y < SMALL_RADIUS * 2);
			bool inWhiteSmallCircleBounds = (coord_Y < -SMALL_RADIUS && coord_Y > -SMALL_RADIUS * 2);

			bool inWhiteMediumCircleBounds = (coord_Y > 0 && coord_Y < SMALL_RADIUS || coord_Y > SMALL_RADIUS * 2 && coord_Y <= 6);
			bool inBlackMediumCircleBounds = (coord_Y < 0 && coord_Y > -SMALL_RADIUS || coord_Y < -SMALL_RADIUS * 2 && coord_Y >= -6);

			//Booleans for checking if point is undefined at the borders of the small medium and big circles.
			bool unDefAtSmall = (coord_Y == SMALL_RADIUS || coord_Y == -SMALL_RADIUS);
			bool unDefAtDoubleSmall = (coord_Y == SMALL_RADIUS * 2 || coord_Y == -SMALL_RADIUS * 2);
			bool unDefAtLarge = (coord_Y == LARGE_RADIUS || coord_Y == -LARGE_RADIUS);

			//First check is weather or not the point is even defined in one of the three circles.
			if (unDefAtSmall || unDefAtDoubleSmall || unDefAtLarge)
			{
				sayPointIsUndefined();
			}
			//If the point is defined, the next checks are executed to determine exact color.
			else
			{
				if (inWhiteSmallCircleBounds)
				{
					sayPointIsWhite();
				}
				else if (inBlackSmallCircleBounds)
				{
					sayPointIsBlack();
				}
				else if (inBlackMediumCircleBounds)
				{
					sayPointIsBlack();
				}
				else
				{
					sayPointIsWhite();
				}
			}
#pragma endregion 
#pragma endregion 
		}
#pragma region  Standard Checks
		//First standard check is to determine weather or not the point is undefined for any of the three circles
		else if (undefinedForSmall || undefinedForMedium || undefinedForLarge)
		{
			sayPointIsUndefined();
		}
		//Second standard check is to determine if the point is in one of the smallest circles. 
		//If Y > 0 its in the top one, if Y < 0 its in the bottom one.
		else if (pointInSmallCircle(coord_X, coord_Y, SMALL_RADIUS, true))
		{
			if (coord_Y > 0)
			{
				sayPointIsBlack();
			}
			else
			{
				sayPointIsWhite();
			}
		}
		//Second standard check is to determine if the point is in one of the middle circles. 
		//If Y > 0 its in the top one, if Y < 0 its in the bottom one.
		else if (pointInMediumCircle(coord_X, coord_Y, MEDIUM_RADIUS, true))
		{
			if (coord_Y > 0)
			{
				sayPointIsWhite();
			}
			else
			{
				sayPointIsBlack();
			}
		}
		//Second standard check is to determine if the point is in the areas not covered by the small and big circles.
		//In this case if X < 0 its in the left side of the big circle and on the right side if X > 0
		else if (pointInBigCircle(coord_X, coord_Y, LARGE_RADIUS, false))
		{
			if (coord_X > 0)
			{
				sayPointIsBlack();
			}
			else
			{
				sayPointIsWhite();
			}
		}
	}
#pragma  endregion 
	//If the point is not in the biggest circle it means it must be outside of it.
	else
	{
		sayPointIsOutside();
	}
	return 0;
}

#pragma region Output functoins
/*Functions that handle outputting the correct result.
 * These cout statements have been put in separate functions to avoid code repetition.
 */
void sayPointIsWhite()
{
	cout << "White";
}

void sayPointIsBlack()
{
	cout << "Black";
}

void sayPointIsUndefined()
{
	cout << "Undefined";
}

void sayPointIsOutside()
{
	cout << "Outside";
}
#pragma  endregion  

#pragma region Point check functions
/*Functions that check where the point is located. Each function uses the following formula:
 *                          x^2 + y^2 = radiusOfCircle^2
 *
 *If the sum of X squared and Y squared is equal to the radius squared then the point is considered on the circle,
 *therefore an undefined color.
 *
 *If the sum of X squared and Y squared is more than the radius of the circle then the point is outside of it.
 *
 *If the sum of X squared and Y squared is less than that radius of the circle then the point is inside of it.
 */

 //Checks if point is in the small circle. Requires useCalcCorrection to be true.
bool pointInSmallCircle(double inputX, double inputY, double inputRadius, bool useCalcCorrection)
{
	if (calcXY(inputX, inputY, useCalcCorrection) < calcInputRadius(inputRadius))
	{
		return true;
	}

	return false;

}

//Checks if point is in the small circle. Requires useCalcCorrection to be true.
bool pointInMediumCircle(double inputX, double inputY, double inputRadius, bool useCalcCorrection)
{
	if (calcXY(inputX, inputY, useCalcCorrection) < calcInputRadius(inputRadius))
	{
		return true;
	}

	return false;

}

//Checks if point is in the small circle. Requires useCalcCorrection to be false.
bool pointInBigCircle(double inputX, double inputY, double inputRadius, bool useCalcCorrection)
{
	if (calcXY(inputX, inputY, useCalcCorrection) < calcInputRadius(inputRadius))
	{
		return true;
	}

	return false;

}

//Checks if point is in the small circle. Requires useCalcCorrection to be true base on inputRadius. 
bool pointIsUndefined(double inputX, double inputY, double inputRadius, bool useCalcCorrection)
{
	if (calcXY(inputX, inputY, useCalcCorrection) == calcInputRadius(inputRadius))
	{
		return true;
	}

	return false;

}

//Checks if the point is inside or on the perimiter of the big circle. This is used as the major check in the Main function.
bool pointInOrOnMainCircle(double inputX, double inputY, double largeRad)
{
	bool inLarge = pointInBigCircle(inputX, inputY, largeRad, false);
	bool onLarge = pointIsUndefined(inputX, inputY, largeRad, false);

	if (inLarge)
	{
		return true;
	}
	if (onLarge)
	{
		return  true;
	}

	return false;

}
#pragma endregion 

#pragma  region Math calculation functions
/*Functions responsible for handling the mathematical calculations.
 * This is again done in order to reduce code repetition.
 */

 //Calculates the square of the radius.
double calcInputRadius(double inputRadius)
{
	double inputRadiusSquared = pow(inputRadius, 2);
	return inputRadiusSquared;
}

//Calculates the left-hand side of the mathematical formula mentioned above.
//								 x^2 + y^2		
/*

Since the above mentioned formula is used when the center of the circle is at 0,0 of the coordinate system,
a calculation correction is required to "center" the small and medium circles. From the provided graphic,
we can see the the centers of the circles are offset from (0,0) by 3, that means that the corrections should be as follows:

For Small Circle:
Y > 0 : Correction -3;
Y > 0 : Correction +3;

For Medium Circle:
Y > 0 : Correction -3;
Y > 0 : Correction +3;

For Large Circle:
No Corrections

No corrections are applied to the large circle as it is already centered.


 */
double calcXY(double inputX, double inputY, bool useCorrection)
{
	const double CALC_CORRECTION = 3;
	if (useCorrection && inputX > 0)
	{
		if (inputX > 0)
		{
			double Xs_Plus_Ys = pow(inputX, 2) + pow(inputY - CALC_CORRECTION, 2);
			return Xs_Plus_Ys;
		}
		else
		{
			double Xs_Plus_Ys = pow(inputX, 2) + pow(inputY + CALC_CORRECTION, 2);
			return Xs_Plus_Ys;
		}

	}

	double Xs_Plus_Ys = pow(inputX, 2) + pow(inputY, 2);
	return Xs_Plus_Ys;
}
#pragma endregion