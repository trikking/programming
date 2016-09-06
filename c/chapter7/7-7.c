#include <stdio.h>

int iabs(x)
{ x=x>=0?x:-x;
  return (x);
}

main()
{ int a,c;
  scanf("%d",&a);
  c=iabs(a);
  printf("The absolute value is %d.\n", c);
}
