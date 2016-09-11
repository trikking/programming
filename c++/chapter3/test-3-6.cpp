#include <iostream>
int main()
{ 
  using namespace std;
  double kilometers, liters;
  cout << "Enter the kilometers you have driven: ";
  cin >> kilometers;
  cout << "Enter the liters of gasoline you have used: ";
  cin >> liters;
  cout << liters / kilometers * 100 << " liters per 100 km\n";
  return 0;
}
