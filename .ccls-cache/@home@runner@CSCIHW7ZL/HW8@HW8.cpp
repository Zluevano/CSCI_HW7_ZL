#include <iostream>
#include "MyArrayFunctions.h"
using namespace std;

int main()
{
int n;
int freq;

cout << "Array Size" << endl;
cin >> n;

cout << endl; //Gap for console

int list[n];
int counted[n];


//Fill Array with values
cout << "Input values for array:" << endl;
for (int i = 0; i < n; i++)
{
cin >> list[i];
}

cout << endl; //Gap for console

//Selection function made in class, rewritten so code is shorter
selectionSort(list, n);

cout << "Now inputting array in order" << endl;
for (int i = 0; i < n; i++)
{
cout << list[i] << " ";
}

cout << endl; //Gap for console


//Set all of counted[i] to false for later occurence
for (int i = 0; i <n; i++)
{
counted[i] = false;
}

cout << endl; //Gap for console
  
cout << "Verify its all 0 that is counted[n]" << endl;
printArray(counted, n);

cout << endl; //Gap for console

  
cout << "Now listing them by occurence" << endl;
for(int i = 0; i < n; i++){ 
  //Skips if true
  if(counted[i] == true) //See line 65-66 one the i+1 is set to 1 it will skip that part and move on to (i+1) +1.
  continue; // Skips to next iteration that is i+1 this is done to avoid duplicates.
  
  // counts frequency, if value for list[i] = the value for list [j] which is the next of i or i+1 
  freq = 1; // Assume every case where there is a match is = 1 atleast for the start.
  for (int j = i + 1; j < n; j++){ //Checks next number from original i.
    //If list[i] lets say i(1) = 1, and that same list but [i+1] so i(2) also = 1 then set counted[j] for (i+1) = 1 for one
    // occurence and add the freq by 1 which will be associated with list[i] as its outside second for loop.
    if (list[i] == list[j]){ 
      counted[j] = true; // Once this is set to 1 or true and the loop repeats it will not repeat a second time as given by the first for loop.
      freq++;    
      }  
    }  
    cout << endl;
    cout << list[i]<< " occurs "<< freq << " times "<< endl;
  } 

  cout << endl;
  cout << "for the prior counted[j] the first 0 is 1 = 1 for the second, and this sets counted[2] to 1. and so on..." << endl;
  cout << "This was mainly done to avoid it repeating itself over and over for list[i], keeps track of duplicates." << endl;
  printArray(counted, n);
  cout << "Otherwise it looks like this\n" << endl;

for (int i = 0; i <n; i++)
{
counted[i] = false;
}
  cout << "Now listing them by occurence" << endl;
for(int i = 0; i < n; i++){ 
  //Skips if true
  if(counted[i] == true)
  continue; // Skips to next iteration that is i+1 this is done to avoid duplicates.
  
  // counts frequency, if value for list[i] = the value for list [j] which is the next of i or i+1 
  freq = 1; // Assume every case where there is a match is = 1 atleast for the start.
  for (int j = i + 1; j < n; j++){ //Checks next number from original i.
    //If list[i] lets say i(1) = 1, and that same list but [i+1] so i(2) also = 1 then set counted[j] for (i+1) = 1 for one
    // occurence and add the freq by 1 which will be associated with list[i] as its outside second for loop.
    if (list[i] == list[j]){ 
      freq++;    
      }  
    }  
    cout << endl;
    cout << list[i]<< " occurs "<< freq << " times "<< endl;
  } 

}