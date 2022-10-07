/*
#include <iostream>
using namespace std;
void newval(double&, double&);  
int main()
{  
  double firstnum, secnum;  
  cout << "Enter two numbers: ";  
  cin  >> firstnum >> secnum;  
  cout << "\nThe value in firstnum is: " << firstnum << endl;  
  cout << "The value in secnum is: " << secnum << "\n\n";  
  newval(firstnum, secnum);     
  cout << "The value in firstnum is now: " << firstnum << endl;  
  cout << "The value in secnum is now: " << secnum << endl;  
  return 0;
  }
void newval(double& xnum, double& ynum)
{  
  cout << "The value in xnum is: " << xnum << endl;  
  cout << "The value in ynum is: " << ynum << "\n\n";  xnum = 89.5;  ynum = 99.5;  
  return;}
*/


//page 340 for reference
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

//double time(int& seconds, int& minutes, int& hours);
void time(int, int&, int&, int&);
double second;
double min;
double hour;

int main()
{
int seconds;
int min = 1/60;
int hour = 1/3600;
int second;
  
cout << "Enter time in second: " << endl;
cin >> seconds;

cout << "You entered " << seconds << " in Seconds" << endl;
time(seconds, second, min, hour);
  
return 0;
}

void time(int seconds, int& xsec, int& xminute, int& xhour)
{
cout << "The value of seconds is seconds" << endl;
cout << xsec << endl;
cout << "the value of seconds in minutes" << endl;
cout << xminute << endl;

return;

  
}
