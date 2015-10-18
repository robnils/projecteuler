// ProjectEuler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int SumOfAllNumbersBelow1000(); 
int main()
{
	std::cout << "*** Results ***\n";
	std::cout << "Problem 1: " << SumOfAllNumbersBelow1000() << std::endl;
    return 0;
}

// Problem 1
// Find the sum of all the multiples of 3 or 5 below 1000.
int SumOfAllNumbersBelow1000()
{
	int sum = 0;

	for (size_t multiple = 0; multiple < 1000; multiple++)
	{
		if ((multiple % 3 == 0) || (multiple % 5 == 0))
		{
			sum += multiple;
		}
	}
	return sum;
}

