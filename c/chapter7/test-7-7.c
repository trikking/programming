#include <stdio.h>
#include <math.h>
float func(float x,int n)
{ float r;
  if(n>1)
    r=sqrt(n+func(x,n-1));
  else r=sqrt(1+x);
  return r;
}

main()
{ float x;
  int n;
  printf("Input x,n:");
  scanf("%f,%d",&x,&n);
  printf("f(%f,%d)=%f\n",x,n,func(x,n));
}
