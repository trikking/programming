#include <stdio.h>
struct mon
{ int no;
  char name[20];
  int days;
};
main()
{ struct mon month[12]={{1,"January",31},{2,"February",28},
                    {3,"March",31},{4,"April",30},
                    {5,"May",31},{6,"June",30},
                    {7,"July",31},{8,"August",31},
                    {9,"September",30},{10,"October",31},
                    {11,"November",30},{12,"December",31}};
  int i;
  printf("no\tname\t\tdays\n");
  for(i=0;i<12;i++)
    printf("%d\t%s\t\t\%d\n",month[i].no,month[i].name,month[i].days);
}
