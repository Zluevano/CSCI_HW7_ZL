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