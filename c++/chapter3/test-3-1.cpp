#include <iostream>
int main()
{
  using namespace std;
  int height;
  cout << "Enter your height in inches: ________\b\b\b\b\b\b\b\b";
  cin >> height;
  cout << "Your height is " << height / 12 << " feet, "
       << height % 12 << " inches." << endl;
  return 0;
}
