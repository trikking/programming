#include <iostream>
double Celsius_to_Fahrenheit(double Celsius);
int main()
{
  using namespace std;
  double Celsius;
  cout << "Please enter a Celsius value: ";
  cin >> Celsius;
  cout << Celsius << " degrees Celsius is " 
       << Celsius_to_Fahrenheit(Celsius) 
       << " degrees Fahrenheit." << endl;
  return 0;
}
double Celsius_to_Fahrenheit(double Celsius)
{
  return 1.8 * Celsius + 32.0;
}
