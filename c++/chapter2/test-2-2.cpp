#include <iostream>
int furlong_to_yard(int);
int main()
{ 
  using namespace std;
  int furlongs, yards;
  cout << "Enter a distance in furlongs: ";
  cin >> furlongs;
  yards = furlong_to_yard(furlongs);
  cout << furlongs << " furlongs = ";
  cout << yards << " yards." << endl;
  return 0;
}

int furlong_to_yard(int furlongs)
{
  return 220 * furlongs;
}
