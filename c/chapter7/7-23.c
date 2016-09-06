#include <stdio.h>

int fact(int n)
{ static int f=1;
  f*=n;
  return f;
}

main()
{ int i;
  for(i=1;i<=5;i++)
    printf("%d!=%d    ",i,fact(i));
  printf("\n");
}
