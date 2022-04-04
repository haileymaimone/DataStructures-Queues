////////////////////////////////////////////////////////////////////////////////////////
//
//  Assign4 - Queue Class - CSC-328
//  Group Members:  Hailey Maimone, Ricky Peddicord, Kelli Huff, Michael Mickey
//
//  PROGRAM SYNOPSIS:  This program demonstrates the queue class. It reads in
//  	values from an input file named "input.txt".  The line is read in as
//		a string, checked to be a number, converted to an integer, and then
//		finally checked to be within the range of 0-32000.  If the data meets
//		this criteria, it is added to the queue using the enqueue member function.
//		The values are then each removed from the queue, and the program
//		then checks the queue to be empty, and if it is, prints that it is empty.
//
////////////////////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue.h"
#include <string>
#include <cctype>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void printArr(int *arr, int size) 			// function to print array of integers
{
	int linebreak = 0;			// integer to determine when to end the line
	cout << "---------------------------------------------------" << endl;
	for (int i = 0; i < size; i++) 			// loop through the array
	{
		linebreak++;			// increment linebreak
		cout << arr[i];			// print current array value
		if (linebreak % 5 == 0) 		// if 5 numbers are on the line
		{
			cout << endl;		// end the line
		} 
		else 
		{
			cout << setw(10);	// otherwise add some spacing
		}
	}
	cout << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "" << endl;
	cout << "" << endl;
}

int maxVal(int *arr, int size) 	// function to return the biggest number in an array of integers
{
	int max = arr[0]; 				// set first array to initial max
	for (int i = 1; i < size; i++)  // loop through the array
	{
		if (arr[i] > max) 			// if current array value is greater than the current max
		{
			max = arr[i];			// then set max to be the current array value
		}
	}
	return max;						// return max
}

int getNum(int num, int i) 		// function to return the numbers (num) digit based on the position provided (i)
{
	return int(num / pow(10, i)) % 10;	// return the number
}

int digitCount(int num) 			// function to return the number of digits in a number
{
	int count = 0;					// intiialize count to 0
	while (num != 0) 				// while the number isn't 0
	{
		num = num / 10;				// divide the number by 10
		count++;					// increment count
	}
	return count;					// return the digit count
}

void reCombine(int *arr, Queue arrQ[], int size) 			// function to dequeue sorted values back to the original array
{
	bool empty = false;										// initialize empty boolean to false
		int i = 0;											// intiialize i to 0
		int j = 0;											// intialize j to 0
		while (i < size) 			// while i is less than the array size
		{
			while (!empty)  		// while the current queue is not empty
			{
				if (arrQ[j].queueFront() != - 1) 	// if the current queue is not empty
				{
					arr[i] = arrQ[j].dequeue();				// then dequeue current value from jth queue to ith array
					i++;									// increment array to next index
				} 
				else 
				{
					empty = true;							// if queue is empty, set boolean to true
					j++;									// increment j to move to next queue
				}
			}
			empty = false;									// set empty to false for loop reentry
		}
}

void sortNums(int *arr, Queue arrQ[], int size, int pos) 	//  function to 
{
	for (int i = 0; i < size; i++) 
	{
		int num = getNum(arr[i], pos);			// get the passed number's digit at the passed position
		arrQ[num].enqueue(arr[i]);				// enqueue that number to the queue represented by the position
												// for example 171 and 0th (1's) place would return 1, so
												// we would enqueue the number to the queue reprsentings 1's
	}
}

void radixSort(int *arr, Queue arrQ[], int size) 	// function implementing radix sort
{
	int max = maxVal(arr, size);			// get the maximum number from the array
	int maxDigits = digitCount(max);		// get the digit count of the maximum number
	for (int k = 0; k < maxDigits; k++) 	// loop the number of times equal to the maximum number of digits
	{
		sortNums(arr, arrQ, size, k);		// sort the numbers
		reCombine(arr, arrQ, size);			// recombine into the original array
	}
}


int main() 
{
	ifstream inputFile;		// INPUT FILE VARIABLE
	Queue queue;			// INSTANCE OF QUEUE CLASS
	Queue queueArr[10];
	int val;				// INT VALUE TO ADD TO QUEUE
	int invalid_data=0;		// INT VALUE TO HOLD INVALID DATA
	string line;			// VARIABLE FOR READING IN DATA AS A STRING

	int count = 0;			// size for dynamic array
	int *arr;				// declare dynamic array
	
	
	cout << "Opening file...\n" << endl;
	inputFile.open("input.txt");		// opens input file bank.txt
	
	
		if(inputFile.is_open())				// if file is opened
		{
			while(!inputFile.eof())			// while not at end of file
			{
				getline(inputFile, line);		// reads line from file as string
				invalid_data=line.find_first_not_of("0123456789");		// checks line for any values not equal to a number
				if(invalid_data==-1)			// if -1 is returned, bad data was not found
				{
					val=atoi(line.c_str());		// converts line to an int value
					if(val >= 0 && val <= 32000)	// checks if int value is between specified range of 0-32000
					{
						count++;					// increment count (to determine dynamic arrays size)
						queue.enqueue(val);			// value is added to queue
					}
				}
			}
		}
		inputFile.close();

		arr = new int[count];			// initialize dynamic array to the size of count

		for (int i = 0; i < count; i++) 
		{
			arr[i] = queue.dequeue();			// dequeue all values into the array
		}
		
		radixSort(arr, queueArr, count);		// perform radix sort on the array
		printArr(arr, count);					// print the array
		
		delete[] arr;			// free up the memory from the dynamic array

		return 0;
}
