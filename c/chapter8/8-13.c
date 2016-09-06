#include <stdio.h>
main()
{ char *weekday[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
  int week;
  printf("Input week:");
  scanf("%d",&week);
  if(week>0 && week<7)
    printf("%s\n",weekday[week]);
}
