/**
*
* Solution to homework assignment 3
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
#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;
void printWord(char l1[], char l2[], char l3[], char l4[], char l5[]);
void addSpacing(int frontSpacing, int y);

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int main()
{
	char l1[] = { 'H', ' ', ' ',' ', 'H', ' ', ' ', ' ', 'E' , 'E', 'E' , 'E', 'E', ' ', ' ', ' ', 'L', ' ', ' ', ' ', ' ', ' ',' ', ' ', 'L', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ','O', ' ',' ' };
	char l2[] = { 'H', ' ', ' ',' ', 'H', ' ', ' ', ' ', 'E' , ' ', ' ' , ' ', ' ', ' ', ' ', ' ', 'L', ' ', ' ', ' ', ' ', ' ',' ', ' ', 'L', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', 'O',' ', 'O',' ' };
	char l3[] = { 'H', 'H', 'H','H', 'H', ' ', ' ', ' ', 'E' , 'E', 'E' , 'E', 'E', ' ', ' ', ' ', 'L', ' ', ' ', ' ', ' ', ' ',' ', ' ', 'L', ' ', ' ', ' ', ' ', ' ',' ', ' ', 'O', ' ',' ', ' ','O' };
	char l4[] = { 'H', ' ', ' ',' ', 'H', ' ', ' ', ' ', 'E' , ' ', ' ' , ' ', ' ', ' ', ' ', ' ', 'L', ' ', ' ', ' ', ' ', ' ',' ', ' ', 'L', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', 'O',' ', 'O',' ' };
	char l5[] = { 'H', ' ', ' ',' ', 'H', ' ', ' ', ' ', 'E' , 'E', 'E' , 'E', 'E', ' ', ' ', ' ', 'L', 'L', 'L', 'L', 'L', ' ',' ', ' ', 'L', 'L', 'L', 'L', 'L', ' ',' ', ' ', ' ', ' ','O', ' ',' ' };
	int frontSpacing = 0;
	while (true)
	{
		system("CLS");

		addSpacing(frontSpacing, 0+ 10);
		for (int i = 0; i < sizeof(l1); i++)
		{
			cout << l1[i];
		}
		cout << endl;

		addSpacing(frontSpacing, 1+ 10);
		for (int i = 0; i < sizeof(l2); i++)
		{
			cout << l2[i];
		}
		cout << endl;

		addSpacing(frontSpacing, 2+ 10);
		for (int i = 0; i < sizeof(l3); i++)
		{
			cout << l3[i];
		}
		cout << endl;

		addSpacing(frontSpacing, 3+ 10);
		for (int i = 0; i < sizeof(l4); i++)
		{
			cout << l4[i];
		}
		cout << endl;

		addSpacing(frontSpacing, 4+ 10);
		for (int i = 0; i < sizeof(l5); i++)
		{
			cout << l5[i];
		}
		cout << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(15));

		if(frontSpacing > 100)
		{
			frontSpacing = 0;
		}
		frontSpacing++;
	}
	
}

void addSpacing(int frontSpacing, int y)
{
	CursorPosition.X = frontSpacing;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}


void printWord(char l1[], char l2[], char l3[], char l4[], char l5[])
{	
	for (int i = 0; i < sizeof(l1); i++)
	{
		cout << l1[i];
	}
	cout << endl;

	for (int i = 0; i < sizeof(l2); i++)
	{
		cout << l2[i];
	}
	cout << endl;

	for (int i = 0; i < sizeof(l3); i++)
	{
		cout << l3[i];
	}
	cout << endl;

	for (int i = 0; i < sizeof(l4); i++)
	{
		cout << l4[i];
	}
	cout << endl;

	for (int i = 0; i < sizeof(l5); i++)
	{
		cout << l5[i];
	}
	cout << endl;

}
