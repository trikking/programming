#include <stdio.h>

#define FORM "%d\t%d\t%d\n"

int a=5;

void func(int x,int y)
{ int b,c;
  b=a+x;
  c=a-y;
  printf(FORM,a,b,c);
}

main()
{ int b=6,c=7;
  func(b,c);
  printf(FORM,a,b,c);
  { int a=9,b=8;
    printf(FORM,a,b,c);
    { c=10;
      printf(FORM,a,b,c);
    }
    printf(FORM,a,b,c);
  }
  printf(FORM,a,b,c);
}
