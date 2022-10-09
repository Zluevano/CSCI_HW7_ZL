#include <iostream>
using namespace std;

void CSPJ(int days);

int main() {
  int n; // Set Days to n
  int SJ; // amount of space junk on a given day
  int ans; // result of day.
  int MSJ = -1; // Set to -1 for minimum result as otherwise the first occurence is also = to 0 this was solved after just throwing different things at this.

  cin >> n; // Input of Days
  
  for (int i = 0; i < n; i++) {
    cin >> SJ; // Input of space junk for day;
    
    if ((MSJ == -1) || (SJ < MSJ)) 
    {
      MSJ = SJ;
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}