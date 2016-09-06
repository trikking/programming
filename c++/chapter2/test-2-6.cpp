#include <iostream>
double light_year_to_astronomical(double);
int main()
{
  using namespace std;
  cout << "Enter the number of light year: ";
  double light_year;
  cin >> light_year;
  cout << light_year << " light years = "
       << light_year_to_astronomical(light_year)
       << " astronomical units." << endl;
  return 0;
}

double light_year_to_astronomical(double light_year)
{
  return light_year * 63240;
}
