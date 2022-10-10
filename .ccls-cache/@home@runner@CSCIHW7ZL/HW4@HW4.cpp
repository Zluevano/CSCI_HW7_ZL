/*
Programmer: Zachary Luevano
Date: October 9th, 2022
Description: This one was a little hard as I had no idea how to find the lowest amount and correleate it with being picked first, some group work was done. However, the functions works by inputing a number of days and is then passed along to another function that has an input SJ based on n times. The first result is always going to be 0 so setting another variable to -1 to get that as the function for the for loop cannot = -1 is used that first value is also saved as MSJ. Further inputs are processed to determine if  they are lower than whatever the value that set the ans to 0 is lower than it, if it isn't it is ignored and repeated for another input, if the input for SJ is lower than the old value of MSJ it saves that i interval for the final answer.
*/

#include <iostream>
using namespace std;

void CSPJ(int n);
int main() 
{
  int n; // Set Days to n
  
  cin >> n; // Input of Days
  
  CSPJ (n);
}
/////////////////////
  void CSPJ(int n)
{
  int SJ; // amount of space junk on a given day
  int ans; // result of day, initalize variable.
  int MSJ = -1; // Set to -1 for minimum result as otherwise the first occurence is also = to 0 this was solved after just throwing different things at this.
  
  for (int i = 0; i < n; i++) {
    cin >> SJ; // Input of space junk for day;

//Because MSJ is equal to -1 then it will default to i = 0 for the first answer. This also sets the current input to MSJ and if the next number i numbers along is smaller than that then it will save that i.
    if ((MSJ == -1) || (SJ < MSJ))
    {
      MSJ = SJ;
      ans = i;
    }
  }
  cout << ans << endl;
  return;
}