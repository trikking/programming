#include <stdio.h>
main()
{ char s[][15]={"Illegal month", "January", "February", "March", "April", "May", "June",
              "July", "August", "September", "October", "November", "December"};
  int m;
  printf("input month:");
  scanf("%d",&m);
  printf("%s\n",(m<1 || m>12)?s[0]:s[m]);
}
