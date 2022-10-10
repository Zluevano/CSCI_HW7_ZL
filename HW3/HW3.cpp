/*
Programmer: Zachary Luevano
Date: October 9th, 2022
Description: Simple book problem that shows tthat a global function isn't always what is shown, for example when you first set firstnum to =10 in the main function you get 10, when you do the same in another function where it isn't it displays the global value.
*/
#include <iostream>
using namespace std;

int firstnum = 10;
void display ();

int main()
{
int firstnum = 20;
cout << "The value of first num is " << firstnum;

display ();
return 0;
}

void display()
{
cout << endl;
cout << "The value of first sum is the global as it's outside of the main function is " << firstnum << endl;
  
return;  
}