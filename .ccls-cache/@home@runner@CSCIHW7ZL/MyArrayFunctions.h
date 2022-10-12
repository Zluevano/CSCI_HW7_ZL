/****************************************************
MyArrayFunctions.h contains functions to help process 1-D arrays more easily.
Many of these functions are also described in Malik Chapter 8. Last Modified by:
Dr. M Date: 10/22
******************************************************/
// To use the functions here this requires....
#include <iostream>
using namespace std;

/*****************************************************
***************** INTEGER ARRAY FUNCTIONS ************
*****************************************************/

/* This function prints the elements of an integer array as a single row.
  Parameters: list[] is the array
              listSize is the size of the array */
void printArray(const int list[], int listSize) {
  int index;

  for (index = 0; index < listSize; index++)
    cout << list[index] << " ";

  cout << endl;
  return;
}

/* This function initializes an integer array to be a constant
  Parameters: list[] is the array
              listSize is the size of the array
              myConst is the constant */
void initializeArray2Const(int list[], int listSize, int myConst) {
  int index;

  for (index = 0; index < listSize; index++)
    list[index] = myConst;

  return;
}

/* This function reads and stores data in an integer array from the console.
  Parameters: list[] is the size of the array to be filled
              sizeList is the size of the array */
void fillArray(int list[], int listSize) {

  cout << "Enter " << listSize << " integers: "; // comment out for kattis

  int index;

  for (index = 0; index < listSize; index++) {
    cin >> list[index];
  }

  return;
}

/* This function finds the sum of all elements in an integer array. 
  Parameters: list[] is the array
              listSize is the size of the array */
int sumArray(const int list[], int listSize){
  int index;
  int sum = 0;

  for (index = 0; index<listSize; index++)
    sum = sum + list[index];

  return sum;
}

// This finds and returns the index for the larget value in an int array
// parameters:    list[] is the array
//                listSize is the size or length of the array
int indexLargestElement(const int list[],int listSize)
{
int maxIndex = 0; //default assumption, assume largest value is in first spot.
for (int index = 0; index < listSize; index++)
{
  if (list[maxIndex] < list[index])
    maxIndex = index;
}
return maxIndex;
}

// sequentially search through an int array to find the index of a value.
// parameters:       list[] is the array we want to search
//                   listSize is the size of the array.
//                     int 
int seqSearch(const int list[], int listSize, int searchItem)
{
int loc = 0; // start with 1st spot.
bool found = false; // we have not found it
  
while ((loc < listSize) && (!found))
{
if ((list[loc]) == searchItem)
  found = true;
  else
    loc++;
}
  if (found)
    return loc;
  else{
    cout << "Item not found." << endl;
    return -1;
  }
}


// This function copies some or lal elements from one int array to another
// Parameters:
// list1[] is the array we want to copy from.
// list2[] is the array we want to copy to.
// numOfElements is the total number of elements to be copied.
// src is the specific starting position in list1.
// tar is the specific starting position for list2.
void copyArray(int list1[], int list2[], int src, int tar, int numOfElements)
{
  
for (int index = 0; index < (src + numOfElements); index++)
  {
  list2[tar] = list1[index];
  tar++;
  }
  return;
}


// This function sorts a list by size by smallest to largest
//Parameters:
// list[] is the array.
// length is the size of the array (listsize was also used for the same in here).
// if the first value is larger than the second one, save the index of that first value 
// 10 - 1 - 5 - 3 - 8, is 10 smaller than 1, smaller than 5 smaller than 3, smaller than 8?
// Then is 1 smaller than 5, smaller than 3, smaller than 3, smaller than 8?
// Then is 5 smaller than 3, smaller than 8, etc...
// When it encounteres one where it is smaller it swaps.
// At first assume the first spot is the smallest just for the start and then check it.
void selectionSort(int list[], int length)
{
int index;
int smallestIndex;
int temp;
  
// Length-1 is done because for the last block on an array it has nothing to compare to see line 147 for further reasoning.
// Increment through main array
for (index = 0; index < length-1; index++)
  {
  smallestIndex = index;
    //Additional for loop to check next line and compare to first at one earlier line 142.
    // Increment for new smallest index.
    for (int loc = 1; loc < length; loc++)
      {
        if (list[loc] < list[smallestIndex])
        smallestIndex = loc; // Location of new smallest index.
      }
    // Make the swap:
    temp = list[smallestIndex];
    list[smallestIndex] = list[index];
    list[index] = temp;
  }
return;
}
