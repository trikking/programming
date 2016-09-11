#include <iostream>
int main()
{
  using namespace std;
  long long population_world, population_us;
  cout << "Enter the world's population: ";
  cin >> population_world;
  cout << "Enter the population of the US: ";
  cin >> population_us;
  cout << "The population of the US is " 
       << population_us * 1.0 / population_world * 100 
       << "% of the world population.\n";
  return 0;
}
