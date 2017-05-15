// SingleAccessFunctionRetByRef.cpp : Defines the entry point for the console application.
//
/*
create safe array - index array checked before access
uses one access() function for both put and get

*/
#include "stdafx.h"
#include <iostream>
#include <process.h> // for exit()

const int LIMIT = 100; //array size

class SafeArray
{
	int arr[LIMIT];
public:
	int& access(int n) // note: return by reference
	{
		if (n < 0 || n >= LIMIT)
		{
			std::cout << "\nIndex out of bounds";
			exit(1);
		}
		return arr[n];
	}
};

int main()
{
	SafeArray sa1;

	for (int j = 0; j < LIMIT; j++) // insert elements
	{
		sa1.access(j) = j * 10; // LEFT side of equal sign
	}
	for (int j = 0; j < LIMIT; j++) // display elements
	{
		int temp = sa1.access(j); // RIGHT side of eaqul sign
		std::cout << "Element " << j << " is " << temp << std::endl;
	}

	system("pause");
    return 0;
}

