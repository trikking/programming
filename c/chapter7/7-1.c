#include <stdio.h>

int cube(int x)
{ return (x*x*x); }

main()
{ int f, a;
  printf("Enter a integer number:");
  scanf("%d", &a);
  f = cube(a);
  printf("%d*%d*%d=%d\n", a,a,a,f);
}
