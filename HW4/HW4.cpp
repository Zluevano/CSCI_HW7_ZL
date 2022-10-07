#include <iostream>
using namespace std;

int main() {

int n;
int val;
int val2;
int d = 0;
int a;
  
cin >> n; 
cin >> val2; 

  
for (int i = 0; i < n; i++)
{
cin >> val;
cin >> val2; 
  
if (val < val2){
d = i;
val = val2;
}
}
  cout << d << endl;
}


/*
#include <iostream>
using namespace std;

int main() {
int n;
cin >> n;
int d = 0;
int val;
cin >> val;
    
  
  for (int x = 1, a; x < n; x++) {
  cin >> a;
  if (a < val) {
  d = x;
  val = a;
        }
    }
    cout << d;
    return 0;
  }
*/