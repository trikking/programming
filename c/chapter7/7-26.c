#include <stdio.h>

main()
{ register int i;
  long int sum=0;
  for(i=1;i<=1000;i++)
    sum+=i;
  printf("sum=%ld\n",sum);
}
