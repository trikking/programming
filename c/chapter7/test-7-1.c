#include <stdio.h>
#include <math.h>

float f(float x)
{ return x*x-5*x+4;}

main()
{ float a,y1,y2,y3;
  printf("Input a:\n");
  scanf("%f",&a);
  y1=f(a);
  y2=f(a+15);
  y3=f(sin(a));
  printf("y1=%f,y2=%f,y3=%f\n",y1,y2,y3);
}
