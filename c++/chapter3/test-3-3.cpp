#include <iostream>
int main()
{
  using namespace std;
  cout << "Enter a latitude in degrees, minutes, and seconds:\n";
  double degrees, minutes, seconds;
  cout << "First, enter the degrees: ";
  cin >> degrees;
  cout << "Next, enter the minutes of arc: ";
  cin >> minutes;
  cout << "Finally, enter the seconds of arc: ";
  cin >> seconds;
  cout << degrees << " degrees, " << minutes << " minutes, " 
       << seconds << " seconds = " 
       << degrees + minutes / 60 + seconds / 60 / 60  << " degrees\n";
  return 0;
}
