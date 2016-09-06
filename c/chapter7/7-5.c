#include <stdio.h>
void fun(a,b)
{ printf("a=%d,b=%d\n",a,b);
}

main()
{ int m=5;
  fun(m+3, m++);
}
