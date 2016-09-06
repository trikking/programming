#include <stdio.h>

int f(int m)
{ return m;
}

main()
{ auto int a=3;
  char b='A';
  printf("a=%d\n",a);
  printf("f=%d\n",f(b));
}
