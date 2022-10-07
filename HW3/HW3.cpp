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