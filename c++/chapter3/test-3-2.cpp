#include <iostream>
int main()
{
  using namespace std;
  const float Inches_per_foot = 12;
  const float Meters_per_inch = 0.0254;
  const float Pounds_per_kilogram = 2.2;

  int height_feet, height_inches, weight_pounds;
  cout << "Enter your height in feet, inches:\n";
  cout << "First, enter your height in feet: ";
  cin >> height_feet;
  cout << "Then, enter your height in inches: ";
  cin >> height_inches;
  cout << "Enter your weight in pounds: ";
  cin >> weight_pounds;
  double height_meters = (height_feet * Inches_per_foot + height_inches) 
            * Meters_per_inch;
  double weight_kilograms = weight_pounds / Pounds_per_kilogram;
  cout << "Your body mass index(BMI) is "
       << weight_kilograms / (height_meters * height_meters) << "." << endl;
  return 0;
}
