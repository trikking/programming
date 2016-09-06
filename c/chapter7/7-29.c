#include <stdio.h>
#define PI     3.1415926
#define S      PI*r*r
#define V      4*S*r/3
main()
{ float r;
  printf("\nInput r:");
  scanf("%f",&r);
  printf("S=%0.2f  V=%0.2f\n",S,V);
}
