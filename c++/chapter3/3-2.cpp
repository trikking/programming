// exceed.cpp -- exceeding some integer limits
#include <iostream>
#define ZERO 0
#include <climits>
int main()
{
  using namespace std;
  short sam = SHRT_MAX;      // initialize a variable to max value
  unsigned short sue = sam;  // okey if variable sam already defined

  cout << "Sam has " << sam << " dollors and Sue has " << sue;
  cout << " dollors deposited." << endl
       << "Add $1 to each accounnt." << endl << "Now ";
  sam = sam + 1;
  sue = sue + 1;
  cout << "Sam has " << sam << " dollors and Sue has " << sue;
  cout << " dollors deposited.\nPoor Sam!" << endl;
  sam = ZERO;
  sue = ZERO;
  cout << "Sam has " << sam << " dollors and Sue has " << sue;
  cout << " dollors deposited." << endl;
  cout << "Take $1 from each accout." << endl << "Now ";
  sam = sam - 1;
  sue = sue - 1;
  cout << "Sam has " << sam << " dollors and Sue has " << sue;
  cout << " dollors deposited." << endl << "Lucky Sue!" << endl;
  return 0;
}
