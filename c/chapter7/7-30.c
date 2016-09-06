#include <stdio.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
main()
{ int a,b,m,n;
  printf("Input a,b,m,n:");
  scanf("%d,%d,%d,%d",&a,&b,&m,&n);
  printf("MAX(%d,%d)=%d\n",a,b,MAX(a,b));
  printf("MAX(%d+%d,%d+%d)=%d\n",a,m,b,n,MAX(a+m,b+n));
}
