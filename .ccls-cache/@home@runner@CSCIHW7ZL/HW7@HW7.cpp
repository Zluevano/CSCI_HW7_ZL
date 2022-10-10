/*
Programmer: Zachary Luevano
Date: October 9th, 2022
Description: Another book problem that focused on solving a math problem using a for loop and arrays. I feel like this problem really cemented what is possible atleast in the mathmatical sense with Arrays. Anyhow this works by having a set array (resistance) being used for later calculations but defined at the start. A later loop of currenty is entered into a for loop for another 5 variables and take the square of each and reinput them into the array. After that it takes these two to create another array (power) through multiplication. In that final loop it outputs a set of variables from each part that is used to create a graph. Outside of the loop near the end it calculates the totals for them as defined in the final loop.
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
int resistance[5] {16, 27, 39, 56, 81};
int current[5];
int power[5];
int sumR = 0;
int sumC = 0;
int sumP = 0;

cout << "Enter five currents: " << endl;
for (int i = 0; i < 5; i++)
{
cin >> current[i];
current[i] = pow(current[i],2);
}


cout << "Resistance" << setw(11) << "Current" << setw(10) << "Power" << endl;;
for (int i = 0; i < 5; i++)
{
power[i] = (resistance [i] * current[i]);
//power[i] = (resistance [i] * pow(current[i],2));
cout << resistance [i] << setw(16) << current[i] << setw(12) << power[i] << endl;  
//cout << resistance [i] << setw(16) << current[i] << setw(12) << (resistance [i] * pow(current[i],2)) << endl;  
sumC = sumC+current[i];
sumR = sumR+resistance[i];
sumP = sumP+power[i];
}
cout << "Totals: " << endl;
cout << sumR << setw(15) << sumC << setw(12) << sumP;


return 0; 
}