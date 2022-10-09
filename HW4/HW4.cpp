#include <iostream>
using namespace std;

void CSPJ(int n);

int main() 
{
  int n; // Set Days to n
  
  cin >> n; // Input of Days
  
  CSPJ (n);
}


  void CSPJ(int n)
{
  int SJ; // amount of space junk on a given day
  int ans; // result of day.
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