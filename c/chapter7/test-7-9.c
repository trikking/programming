#include <stdio.h>
#include <math.h>
#define F(x) ((x)*(x)-5*(x)+4)

main()
{ float a,y1,y2,y3;
  printf("Input x:");
  scanf("%f",&a);
  y1=F(a);
  y2=F(a+15);
  y3=F(sin(a));
  printf("y1=%f,y2=%f,y3=%f\n",y1,y2,y3);
}
