#include <stdio.h>

int a=5;

void func(int x,int y)
{ int b,c;
  b=a+x;
  c=a-y;
  printf("%d\t%d\t%d\n",a,b,c);
}

main()
{ int b=6,c=7;
  func(b,c);
  printf("%d\t%d\t%d\n",a,b,c);
  { int a=9,b=8;
    printf("%d\t%d\t%d\n",a,b,c);
    { c=10;
      printf("%d\t%d\t%d\n",a,b,c);
    }
    printf("%d\t%d\t%d\n",a,b,c);
  }
  printf("%d\t%d\t%d\n",a,b,c);
}
