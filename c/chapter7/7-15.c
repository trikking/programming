#include <stdio.h>

main()
{ int n=3;
  printf("%d\n",sub1(n));
}

int sub1(int n)
{ int i,a=0;
  for(i=n;i>0;i--)
    a+=sub2(i);
  return a;
}

int sub2(int n)
{ return n+1;}
