#include <stdio.h>

float s(r)
{ return 3.14*r*r;
}

main()
{ int r;
  scanf("%d",&r);
  printf("area is %f\n",s(r));
}
