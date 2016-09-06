#include <stdio.h>
//#include "file2.c"
//#include "file3.c"

main()
{ void f1(),f2(),f3();
  f1();
  f2();
  f3();
}

static void f1()
{ printf("1f1\n");
}
