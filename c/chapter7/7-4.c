#include <stdio.h>

void swap(x, y)
{ int z;
  z=x; x=y; y=z;
  printf("x=%d,y=%d\n", x, y);
}

main()
{ int a=10, b=20;
  swap(a,b);
  printf("a=%d,b=%d\n", a, b);
}
