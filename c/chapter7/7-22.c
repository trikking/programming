#include <stdio.h>

static int b=0;

main()
{ int a=2,i;
  for(i=0;i<3;i++)
    printf("%4d",f(a));
  printf("\n");
}

int f(a)
{ static int c=3;
  b++;c++;
  return (a+b+c);
}
