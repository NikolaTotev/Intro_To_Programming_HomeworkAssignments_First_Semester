/**
*
* Solution to homework assignment 3
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
#include  <array>
using namespace std;


const size_t MATRIX_SIZE = 3;
void transpMatrix(double inputMatrix[MATRIX_SIZE][MATRIX_SIZE], double(&output_matr)[MATRIX_SIZE][MATRIX_SIZE]);
void multiplyMatrixByNumber(double inputMatrix[MATRIX_SIZE][MATRIX_SIZE], double numberToMultiplyBy, double(&output_matr)[MATRIX_SIZE][MATRIX_SIZE]);
void multiplyMatrixByMatrix(double matrix_Left[MATRIX_SIZE][MATRIX_SIZE], double matrix_Right[MATRIX_SIZE][MATRIX_SIZE], double(&output_matr)[MATRIX_SIZE][MATRIX_SIZE]);
void matrixAddition(double matrix_Left[MATRIX_SIZE][MATRIX_SIZE], double matrix_Right[MATRIX_SIZE][MATRIX_SIZE], double(&output_matr)[MATRIX_SIZE][MATRIX_SIZE]);
void matrixSimplification(double matrix_Left[MATRIX_SIZE][MATRIX_SIZE], double matrix_Right[MATRIX_SIZE][MATRIX_SIZE], double(&outputMatr)[MATRIX_SIZE][MATRIX_SIZE]);
void print(double inputMatrix[3][3]);
int main()
{
	double matrix_A[MATRIX_SIZE][MATRIX_SIZE];
	double matrix_C[MATRIX_SIZE][MATRIX_SIZE];
	matrix_A[0][0] = -4;
	matrix_A[0][1] = 1;
	matrix_A[0][2] = 1;

	matrix_A[1][0] = 1;
	matrix_A[1][1] = -3;
	matrix_A[1][2] = 2;

	matrix_A[2][0] = 1;
	matrix_A[2][1] = 2;
	matrix_A[2][2] = -4;

	matrix_C[0][0] = -1;
	matrix_C[0][1] = -2;
	matrix_C[0][2] = -2;

	matrix_C[1][0] = -1;
	matrix_C[1][1] = -3;
	matrix_C[1][2] = -4;

	matrix_C[2][0] = -1;
	matrix_C[2][1] = -3;
	matrix_C[2][2] = -5;

	//matrix_C[0][0] = 1;
	//matrix_C[0][1] = 0;
	//matrix_C[0][2] = 0;

	//matrix_C[1][0] = 0;
	//matrix_C[1][1] = 1;
	//matrix_C[1][2] = 0;

	//matrix_C[2][0] = 0;
	//matrix_C[2][1] = 0;
	//matrix_C[2][2] = 1;



	double matrix_D[MATRIX_SIZE][MATRIX_SIZE];
	double matrix_A_Transp[MATRIX_SIZE][MATRIX_SIZE];
	transpMatrix(matrix_A, matrix_A_Transp);

	multiplyMatrixByMatrix(matrix_A_Transp, matrix_C, matrix_D);

	multiplyMatrixByNumber(matrix_D, -3, matrix_D);

	double matrix_G[MATRIX_SIZE][MATRIX_SIZE];
	double Five_E[MATRIX_SIZE][MATRIX_SIZE];

	Five_E[0][0] = 1;
	Five_E[0][1] = 0;
	Five_E[0][2] = 0;

	Five_E[1][0] = 0;
	Five_E[1][1] = 1;
	Five_E[1][2] = 0;

	Five_E[2][0] = 0;
	Five_E[2][1] = 0;
	Five_E[2][2] = 1;

	multiplyMatrixByNumber(Five_E, 5, Five_E);
	matrixAddition(matrix_A, Five_E, matrix_G);

	double E[MATRIX_SIZE][MATRIX_SIZE];

	E[0][0] = 1;
	E[0][1] = 0;
	E[0][2] = 0;

	E[1][0] = 0;
	E[1][1] = 1;
	E[1][2] = 0;

	E[2][0] = 0;
	E[2][1] = 0;
	E[2][2] = 1;

	double matrix_G_Rev[MATRIX_SIZE][MATRIX_SIZE];
	matrixSimplification(matrix_G, E, matrix_G_Rev);
	double result[MATRIX_SIZE][MATRIX_SIZE];

	multiplyMatrixByMatrix(matrix_D, matrix_G_Rev, result);

	print(result);

}
void checkMatrixRank()
{
	//TODO Code for finding the rank of a matrix.	
}

void print(double inputMatrix[3][3])
{
	cout << "OUPUT" << endl;
	cout << inputMatrix[0][0] << " ";
	cout << inputMatrix[0][1] << " ";
	cout << inputMatrix[0][2] << endl;

	cout << inputMatrix[1][0] << " ";
	cout << inputMatrix[1][1] << " ";
	cout << inputMatrix[1][2] << endl;

	cout << inputMatrix[2][0] << " ";
	cout << inputMatrix[2][1] << " ";
	cout << inputMatrix[2][2] << endl;
	cout << " " << endl;
}

void transpMatrix(double inputMatrix[MATRIX_SIZE][MATRIX_SIZE], double(&output_matr)[MATRIX_SIZE][MATRIX_SIZE])
{
	double transposedMatrix[MATRIX_SIZE][MATRIX_SIZE];

	for (int inputRow = 0; inputRow < MATRIX_SIZE; inputRow++)
	{
		for (int inputCol = 0; inputCol < MATRIX_SIZE; inputCol++)
		{
			transposedMatrix[inputCol][inputRow] = inputMatrix[inputRow][inputCol];
		}
	}

	for (int inputRow = 0; inputRow < MATRIX_SIZE; inputRow++)
	{
		for (int inputCol = 0; inputCol < MATRIX_SIZE; inputCol++)
		{
			output_matr[inputRow][inputCol] = transposedMatrix[inputRow][inputCol];
		}
	}
}

void multiplyMatrixByNumber(double inputMatrix[MATRIX_SIZE][MATRIX_SIZE], double numberToMultiplyBy, double(&output_matr)[MATRIX_SIZE][MATRIX_SIZE])
{
	double outputMatrix[MATRIX_SIZE][MATRIX_SIZE];

	for (int inputRow = 0; inputRow < MATRIX_SIZE; inputRow++)
	{
		for (int inputCol = 0; inputCol < MATRIX_SIZE; inputCol++)
		{
			outputMatrix[inputRow][inputCol] = inputMatrix[inputRow][inputCol] * numberToMultiplyBy;
		}
	}

	for (int inputRow = 0; inputRow < MATRIX_SIZE; inputRow++)
	{
		for (int inputCol = 0; inputCol < MATRIX_SIZE; inputCol++)
		{
			output_matr[inputRow][inputCol] = outputMatrix[inputRow][inputCol];
		}
	}
}

void multiplyMatrixByMatrix(double matrix_Left[MATRIX_SIZE][MATRIX_SIZE], double matrix_Right[MATRIX_SIZE][MATRIX_SIZE], double(&output_matr)[MATRIX_SIZE][MATRIX_SIZE])
{
	double outputMatrix[MATRIX_SIZE][MATRIX_SIZE];

	for (int inputRow = 0; inputRow < MATRIX_SIZE; inputRow++)
	{
		for (int inputCol = 0; inputCol < MATRIX_SIZE; inputCol++)
		{
			outputMatrix[inputCol][inputRow] = 0;
		}
	}

	for (int inputRow = 0; inputRow < MATRIX_SIZE; inputRow++)
	{
		for (int inputCol = 0; inputCol < MATRIX_SIZE; inputCol++)
		{
			for (int row = 0; row < MATRIX_SIZE; row++)
			{
				outputMatrix[inputRow][inputCol] += (matrix_Left[inputRow][row] * matrix_Right[row][inputCol]);
			}
		}
	}

	for (int inputRow = 0; inputRow < MATRIX_SIZE; inputRow++)
	{
		for (int inputCol = 0; inputCol < MATRIX_SIZE; inputCol++)
		{
			output_matr[inputRow][inputCol] = outputMatrix[inputRow][inputCol];
		}
	}
}

void matrixAddition(double matrix_Left[MATRIX_SIZE][MATRIX_SIZE], double matrix_Right[MATRIX_SIZE][MATRIX_SIZE], double(&output_matr)[MATRIX_SIZE][MATRIX_SIZE])
{
	double** outputMatrix = new double*[MATRIX_SIZE];

	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		outputMatrix[i] = new double[MATRIX_SIZE];
	}

	for (int inputRow = 0; inputRow < MATRIX_SIZE; inputRow++)
	{
		for (int inputCol = 0; inputCol < MATRIX_SIZE; inputCol++)
		{
			outputMatrix[inputRow][inputCol] = matrix_Left[inputRow][inputCol] + matrix_Right[inputRow][inputCol];
		}
	}

	for (int inputRow = 0; inputRow < MATRIX_SIZE; inputRow++)
	{
		for (int inputCol = 0; inputCol < MATRIX_SIZE; inputCol++)
		{
			output_matr[inputRow][inputCol] = outputMatrix[inputRow][inputCol];
		}
	}
}

void matrixSimplification(double matrix_Left[MATRIX_SIZE][MATRIX_SIZE], double matrix_Right[MATRIX_SIZE][MATRIX_SIZE], double(&output_matr)[MATRIX_SIZE][MATRIX_SIZE])
{
	double outputMatrix[MATRIX_SIZE][MATRIX_SIZE];

	double L_Matrix[MATRIX_SIZE][MATRIX_SIZE];

	for (int inputRow = 0; inputRow < MATRIX_SIZE; inputRow++)
	{
		for (int inputCol = 0; inputCol < MATRIX_SIZE; inputCol++)
		{
			outputMatrix[inputRow][inputCol] = matrix_Right[inputRow][inputCol];
			L_Matrix[inputRow][inputCol] = matrix_Left[inputRow][inputCol];
		}
	}
	double masterElement_L = 0;
	double masterElement_R = 0;
	double multiplier = 0;

	//For second row simplification
	double multiplier_Top = 0;
	double multiplier_Bottom = 0;

	for (int masterIndex = 0; masterIndex < MATRIX_SIZE; masterIndex++)
	{
		masterElement_L = L_Matrix[masterIndex][masterIndex];

		switch (masterIndex)
		{
		case 0:
			for (int rowUnderMaster = 1; rowUnderMaster < MATRIX_SIZE; rowUnderMaster++)
			{
				masterElement_L = L_Matrix[masterIndex][masterIndex];
				multiplier = -(L_Matrix[rowUnderMaster][masterIndex] / masterElement_L);
				for (int columInRowUnderMaster = 0; columInRowUnderMaster < MATRIX_SIZE; columInRowUnderMaster++)
				{
					masterElement_L = L_Matrix[masterIndex][columInRowUnderMaster];
					masterElement_R = outputMatrix[masterIndex][columInRowUnderMaster];
					L_Matrix[rowUnderMaster][columInRowUnderMaster] += (multiplier*masterElement_L);
					outputMatrix[rowUnderMaster][columInRowUnderMaster] += (multiplier*masterElement_R);
				}
			}

			break;

		case 1:
			masterElement_L = L_Matrix[masterIndex][masterIndex];
			multiplier_Top = -(L_Matrix[masterIndex - 1][masterIndex] / masterElement_L);
			multiplier_Bottom = -(L_Matrix[masterIndex + 1][masterIndex] / masterElement_L);



			for (int columInRowUnderMaster = 0; columInRowUnderMaster < MATRIX_SIZE; columInRowUnderMaster++)
			{
				masterElement_L = L_Matrix[masterIndex][columInRowUnderMaster];
				masterElement_R = outputMatrix[masterIndex][columInRowUnderMaster];

				L_Matrix[masterIndex - 1][columInRowUnderMaster] += (multiplier_Top*masterElement_L);
				L_Matrix[masterIndex + 1][columInRowUnderMaster] += (multiplier_Bottom*masterElement_L);

				outputMatrix[masterIndex - 1][columInRowUnderMaster] += (multiplier_Top*masterElement_R);
				outputMatrix[masterIndex + 1][columInRowUnderMaster] += (multiplier_Bottom*masterElement_R);
			}

			break;

		case 2:
			masterElement_L = L_Matrix[masterIndex][masterIndex];
			for (int rowAboveMaster = MATRIX_SIZE - 2; rowAboveMaster >= 0; rowAboveMaster--)
			{

				multiplier = -(L_Matrix[rowAboveMaster][masterIndex] / masterElement_L);

				for (int columnInRowAboveMaster = 0; columnInRowAboveMaster < MATRIX_SIZE; columnInRowAboveMaster++)
				{
					masterElement_L = L_Matrix[masterIndex][columnInRowAboveMaster];
					masterElement_R = outputMatrix[masterIndex][columnInRowAboveMaster];
					L_Matrix[rowAboveMaster][columnInRowAboveMaster] += (multiplier*masterElement_L);
					outputMatrix[rowAboveMaster][columnInRowAboveMaster] += (multiplier*masterElement_R);
				}
			}

			break;
		}

		double divider = (1 / L_Matrix[masterIndex][masterIndex]);

		for (int columnInRow = 0; columnInRow < MATRIX_SIZE; columnInRow++)
		{

			L_Matrix[masterIndex][columnInRow] *= divider;
			outputMatrix[masterIndex][columnInRow] *= divider;
		}

	}

	for (int inputRow = 0; inputRow < MATRIX_SIZE; inputRow++)
	{
		for (int inputCol = 0; inputCol < MATRIX_SIZE; inputCol++)
		{
			output_matr[inputRow][inputCol] = outputMatrix[inputRow][inputCol];
		}
	}

}