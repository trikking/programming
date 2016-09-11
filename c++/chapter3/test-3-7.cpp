#include <iostream>
int main()
{
  using namespace std;
  const float miles_per_100km = 62.14;
  const float liters_per_gallon = 3.875;
  double liters_per_100km;
  cout << "Enter liters per 100 km: ";
  cin >> liters_per_100km;
  double _100kms_per_liter = 1 / liters_per_100km;
  double miles_per_gallon = _100kms_per_liter * miles_per_100km
         / (1 / liters_per_gallon) ;
  cout << liters_per_100km << " liters per 100km is " 
       << miles_per_gallon << " miles per gallon.\n";
  return 0;
}
