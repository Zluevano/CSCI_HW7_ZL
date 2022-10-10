/*
Programmer: Zachary Luevano
Date: October 9th, 2022
Description: This one was a little hard as I had no idea how to find the lowest amount and correleate it with being picked first, some group work was done. However, the functions works by inputing a number of days and is then passed along to another function that has an input SJ based on n times. The first result is always going to be 0 so setting another variable to -1 to get that as the function for the for loop cannot = -1 is used that first value is also saved as MSJ. Further inputs are processed to determine if  they are lower than whatever the value that set the ans to 0 is lower than it, if it isn't it is ignored and repeated for another input, if the input for SJ is lower than the old value of MSJ it saves that i interval for the final answer.
*/
#include <iostream>
using namespace std;

int main()
{
int voltages[10] {89, 75, 82, 93, 78, 95, 81, 88, 77, 82};
for (int i = 0; i < 10; i++)
{
cout << i << " = " << voltages[i] << " ";
}

cout << endl;
cout << endl;
  
double slopes[5] {11.62, 13.89, 18.45, 12.68, 14.76};
for (int i = 0; i < 5; i++)
{
cout << i << " = " << slopes[i] << " ";
}

cout << endl;
cout << endl;

double distances[100] {11.62, 13.98, 18.45, 12.68, 14.76};
//Verifing 6 of that array is infact 
  
for (int i = 0; i < 100; i++)
{
cout << i << " = " <<distances[i] << " ";  
}

cout << endl;
cout << endl;
  
double temps[64] {78.2, 69.6, 68.5, 83.9, 55.4, 67.0, 49.8, 58.3, 62.5, 71.6};

for (int i = 0; i < 64; i++)
{
  cout << i << " = " << temps[i] << " ";
}

cout << endl;
cout << endl;
  
char codes[15] {'f', 'j', 'm', 'q', 't', 'w', 'z'};

for (int i = 0; i < 15; i++)
{
  cout << i << " = " << codes[i] << " ";
}
return 0;
}