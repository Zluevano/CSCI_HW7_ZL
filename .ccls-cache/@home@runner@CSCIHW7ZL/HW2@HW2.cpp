/*
Programmer: Zachary Luevano
Date: October 9th, 2022
Description: Uses a pass by reference to initalize several variables that take a time in seconds inputed that is then passed along to another function that converts it into minutes aswell as into hours. This is done via a void function as it's just returning values.
*/
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

//double time(int& seconds, int& minutes, int& hours);
void time(int seconds, int& sec, int& min, int& hour);

int main()
{
int s;
int m;
int h;
int second;
  
cout << "Enter time in second: " << endl;
cin >> second;

cout << "You entered " << second << " in Seconds" << endl;
cout << endl;
time(second, s, m, h);
  
return 0;
}

void time(int seconds, int& sec, int& mins, int& hour)
{
cout << "The value of seconds in seconds" << endl;
cout << seconds << endl;
cout << endl;
  
mins = (seconds / 60);
hour = (seconds / 3600);

cout << "the value of seconds in minutes" << endl;
cout << mins << endl;
cout << endl;

cout << "the value of seconds in hours" << endl;
cout << hour << endl;
   
return;
}
