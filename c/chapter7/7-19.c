#include <stdio.h>

void sub(int a,int b)
{ int c;
  a=a+b;
  b=a+b;
  c=b-a;
  printf("sub:\ta=%d,b=%d,c=%d\n",a,b,c);
}

main()
{ int a=1,b=1,c=1;
  printf("main:\ta=%d,b=%d,c=%d\n",a,b,c);
  sub(a,b);
  printf("main:\ta=%d,b=%d,c=%d\n",a,b,c);
  { int a=2,b=2;
    printf("comp:\ta=%d,b=%d,c=%d\n",a,b,c);
  }
  printf("main:\ta=%d,b=%d,c=%d\n",a,b,c);
}
