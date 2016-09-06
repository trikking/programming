#include <stdio.h>

void dtoo(int x)
{ int m;
  m=x%8;
  x=x/8;
  if(x) dtoo(x); 
  printf("%d",m);
}

main()
{ int n;
  scanf("%d",&n);
  printf("%d=(",n);
  dtoo(n);
  printf(")8\n");
}
