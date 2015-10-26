// ProjectEuler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

size_t SumOfAllNumbersBelow1000();
size_t SumOfEvenTermsInFibonacciSequenceLessThan4Million();
bool is_prime(unsigned long long int number);
unsigned long long int LargestPrimeFactorOf(unsigned long long int number);
bool is_pallindrome(size_t number);
size_t LargestPallindromeProductOfTwo3DigitNumbers();
int SmallestPositiveNumberEvenlyDivisibleByAllNumbers1To20();
int DifferenceBetweenSumOfSquaresOfFirst100NaturalNumbersAndSquareOfSum();
int PrimeNumber10001(bool display_output);
int ProductOf13AdjacentDigitsWithLargestProduct();

int main()
{	
	using namespace std;
	cout << "*** Results ***\n";
	cout << "Choose a problem (1-8): ";
	string user_choice = "";
	cin >> user_choice;
	int choice = atoi(user_choice.c_str());
	cout << endl;

	switch (choice)
	{
	case 1:
		cout << "Problem 1: " << SumOfAllNumbersBelow1000() << endl;
		break;
	case 2:
		cout << "Problem 2: " << SumOfEvenTermsInFibonacciSequenceLessThan4Million() << endl;
		break;
	case 3:
		cout << "Problem 3: " << LargestPrimeFactorOf(600851475143) << endl;
		break;
	case 4:
		cout << "Problem 4: " << LargestPallindromeProductOfTwo3DigitNumbers() << endl;
		break;
	case 5:
		cout << "Problem 5: " << SmallestPositiveNumberEvenlyDivisibleByAllNumbers1To20() << endl;;
		break;
	case 6:
		cout << "Problem 6: " << DifferenceBetweenSumOfSquaresOfFirst100NaturalNumbersAndSquareOfSum() << endl;;
		break;
	case 7:
		cout << "Problem 7: " << PrimeNumber10001(false) << endl;;
		break;
	case 8:
		cout << "Problem 8: " << ProductOf13AdjacentDigitsWithLargestProduct() << endl;;
		break;
	default:
		cout << "Invalid choice. Aborting...";
		break;
	}

	return 0;
}

// Problem 1
// Find the sum of all the multiples of 3 or 5 below 1000.

size_t SumOfAllNumbersBelow1000()
{
	size_t sum = 0;

	for (size_t multiple = 0; multiple < 1000; multiple++)
	{
		if ((multiple % 3 == 0) || (multiple % 5 == 0))
		{
			sum += multiple;
		}
	}
	return sum;
}

/*** End of Problem 1 **/

// Problem 2
// Each new term in the Fibonacci sequence is generated by adding the previous two terms. 
// By starting with 1 and 2, the first 10 terms will be:
// 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
// By considering the terms in the Fibonacci sequence whose values do not exceed four million, 
// find the sum of the even - valued terms.

size_t SumOfEvenTermsInFibonacciSequenceLessThan4Million()
{
	size_t x_prev = 1, x = 2, x_next = x;
	size_t upper_limit = 4000000;

	size_t sum = 0;

	while (x_next < upper_limit)
	{
		// Calculate sum of even-valued Fibonacci Sequence
		if ((x % 2) == 0)
		{
			sum += x;
		}

		// Calculate terms of Fiibonacci Sequence
		x_next = x + x_prev;
		x_prev = x;
		x = x_next;
	}
	return sum;
}

/*** End of Problem 2 ***/

// Problem 3
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

// Tests whether "number" is prime or not. 
bool is_prime(unsigned long long int  number)
{
	bool is_prime = true;
	for (unsigned long long int i = 2; i < number; i++)
	{
		if ((number % i) == 0)
		{
			is_prime = false;
			break;
		}
	}
	return is_prime;
}

unsigned long long int LargestPrimeFactorOf(unsigned long long int number)
{
	// Test prime
	//size_t number = 12;
	unsigned long long int factor_1 = 1;
	unsigned long long int factor_2 = 1;

	unsigned long long int p_factor_1 = 1;
	unsigned long long int p_factor_2 = 1;

	unsigned long long int largest_prime_factor = 1;
	std::string prime_yes = "prime";
	std::string prime_no = "not prime";

	// Get factors 
	for (unsigned long long int i = 2; i < number; i++)
	{
		// Display something to show the program is working
		if (i % 10000000 == 0)
		{
			std::cout << "Testing " << i << "..." << std::endl;
		}
		// If number is a factor
		if ((number % i) == 0)
		{
			unsigned long long int factor_1 = i;
			unsigned long long int factor_2 = (number / i);

			std::cout << "Current factor: " << factor_1;
			bool res1 = is_prime(factor_1);
			p_factor_1 = (res1) ? factor_1 : p_factor_1;
			std::cout << "\t" << ((res1) ? prime_yes : prime_no);

			std::cout << "\nCurrent factor: " << factor_2;
			bool res2 = is_prime(factor_2);
			p_factor_2 = (res2) ? factor_2 : p_factor_2;
			std::cout << "\t" << ((res2) ? prime_yes : prime_no);

			// If prime factor is the current largest
			largest_prime_factor = (p_factor_1 > largest_prime_factor) ? p_factor_1 : largest_prime_factor;
			largest_prime_factor = (p_factor_2 > largest_prime_factor) ? p_factor_2 : largest_prime_factor;

			std::cout << "\nLargest: " << largest_prime_factor << std::endl << std::endl;
		}
	}
	return largest_prime_factor;
}

/*** End of Problem 3 **/

// Problem 4
// A palindromic number reads the same both ways.The largest palindrome made from the
// product of two 2 - digit numbers is 9009 = 91 � 99.
// Find the largest palindrome made from the product of two 3 - digit numbers.

bool is_pallindrome(size_t number)
{
	std::string s = std::to_string(number);
	int len = s.length();

	// The upper bound of the loop below is the middle point of the 
	// string. The if-condition takes care of the middle value (irrelevant for our purposes)
	// in the event of an odd number.
	size_t upper_bound = (len % 2 == 0) ? len / 2 : (len - 1) / 2;

	bool is_pallindrome = true;
	for (size_t i = 0; i < upper_bound; i++)
	{
		if (s[i] != s[len - i - 1])
		{
			is_pallindrome = false;
			break;
		}
	}
	return is_pallindrome;
}

size_t LargestPallindromeProductOfTwo3DigitNumbers()
{
	std::ofstream log;
	log.open("problem_4.txt");
	
	size_t digit_1 = 999, digit_2 = 999, largest_pallindrome = 1;

	// Note: products on integers is commutative; hence,x*y=y*x.
	// Also, we start at the maximum bound; 999*998 as it is the 
	// largest pallindrome we seek. This is far faster than starting at 1.
	for (size_t i = 999; i > 99; i--)
	{
		for (size_t j = 999; j > 99; j--)
		{
			size_t product = i*j;
						
			if (is_pallindrome(product))
			{
				if (product > largest_pallindrome)
				{
					largest_pallindrome = product;
					std::cout << product << "...Yes!\n";
					log << product << "...Yes!\n";
				}
			}
		}
	}
	log.close();
	return largest_pallindrome;
}

/*** End of Problem 4 **/

// Problem 5
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ?

int SmallestPositiveNumberEvenlyDivisibleByAllNumbers1To20()
{
	bool found = true;
	int num = 2520;

	while (true)
	{	
		found = true;
		for (size_t i = 1; i <= 20; i++)
		{
			if (num % i != 0)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			break;
		}
		num++;
	}

	return num;
}

/*** End of Problem 5 **/

// Problem 6
// Find the difference between the sum of the squares of the 
// first one hundred natural numbers and the square of the sum.

// Note: The question is phrased differently to the example given. 
// The order given gives a negative answer whereas a positive result is expected.

int DifferenceBetweenSumOfSquaresOfFirst100NaturalNumbersAndSquareOfSum()
{
	int sum_squares = 0;
	int square_sum = 0;

	for (int i = 1; i <= 100; i++)
	{
		sum_squares += i*i;
		square_sum += i;
	}
	square_sum = square_sum*square_sum;
	int diff = square_sum - sum_squares;

	return diff;
}

/*** End of Problem 6 **/

// Problem 7
// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
// What is the 10 001st prime number ?

int PrimeNumber10001(bool display_output)
{
	int prime_count = 0;
	int i = 2;
	while (true)
	{
		if (is_prime(i))
		{
			prime_count++;
			if (display_output)
			{
				std::cout << "Prime [" << prime_count << "]: " << i << "\n";
			}			
		}

		if (prime_count == 10001)
		{
			break;
		}
		i++;
	}

	return i;
}

/*** End of Problem 7 **/


// Problem 8
/*

The four adjacent digits in the 1000 - digit number that have the greatest product are 9 � 9 � 8 � 9 = 5832.

73167176531330624919225119674426574742355349194934
96983520312774506326239578318016984801869478851843
85861560789112949495459501737958331952853208805511
12540698747158523863050715693290963295227443043557
66896648950445244523161731856403098711121722383113
62229893423380308135336276614282806444486645238749
30358907296290491560440772390713810515859307960866
70172427121883998797908792274921901699720888093776
65727333001053367881220235421809751254540594752243
52584907711670556013604839586446706324415722155397
53697817977846174064955149290862569321978468622482
83972241375657056057490261407972968652414535100474
82166370484403199890008895243450658541227588666881
16427171479924442928230863465674813919123162824586
17866458359124566529476545682848912883142607690042
24219022671055626321111109370544217506941658960408
07198403850962455444362981230987879927244284909188
84580156166097919133875499200524063689912560717606
05886116467109405077541002256983155200055935729725
71636269561882670428252483600823257530420752963450

Find the thirteen adjacent digits in the 1000 - digit number that have the greatest product.
What is the value of this product ?
*/

int ProductOf13AdjacentDigitsWithLargestProduct()
{
	// Read in number as an array of ints 
	// Test product of array[(i)]*array[(i+1)]*array[(i+2)]*array[(i+3)] 
	// for i = 0 -> length of array of array
	
	return 1;
}
/*** End of Problem 8 **/