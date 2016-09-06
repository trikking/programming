#include <stdio.h>

max(x,y)
{ int z;
  z=x>y?x:y;
  return (z);
}

main()
{ int a,b,c;
  scanf("%d%d",&a,&b);
  c=max(a,b);
  printf("max is %d\n",c);
}
