#include <stdio.h>

main()
{ int a=2,i;
  for(i=0;i<3;i++)
    printf("%4d",f(a));
  printf("\n");
}

int f(a)
{ int b=0,c=3;
  b++;c++;
  return (a+b+c);
}
