#include <iostream>
int main()
{
  using namespace std;
  const int hours_per_day = 24;
  const int minutes_per_hour = 60;
  const int seconds_per_minute = 60;
  long total_seconds;
  cout << "Enter the number of seconds: ";
  cin >> total_seconds;
  long days = total_seconds / (hours_per_day * minutes_per_hour * seconds_per_minute);
  int hours = total_seconds % (hours_per_day * minutes_per_hour * seconds_per_minute) 
      / (minutes_per_hour * seconds_per_minute);
  int minutes = total_seconds % (minutes_per_hour * seconds_per_minute) / minutes_per_hour;
  int seconds = total_seconds % seconds_per_minute;
  cout << total_seconds << " seconds = " << days << " days, " << hours 
       << " hours, " << minutes << " minutes, " << seconds << " seconds" << endl; 
  return 0;
}
