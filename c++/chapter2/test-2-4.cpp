#include <iostream>
int age_in_month(int);
int main()
{
  using namespace std;
  cout << "Enter your age: ";
  int age;
  cin >> age;
  cout << "Your age in months is " << age_in_month(age) << "." << endl;
  return 0;
}

int age_in_month(int age)
{ 
  return 12 * age;
}
