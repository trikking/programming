#include <stdio.h>
#include <math.h>

main()
{ float root(float (*fun)(float));
  float f1(float x);
  float f2(float x);
  printf("roof of x*x*x-5*x*x+6*x-30=0 is %8.4f\n",root(f1));
  printf("roof of 2*x*x*x-4*x*x+3*x-6=0 is %8.4f\n",root(f2));
}

float f1(float x)
{ return (x*x*x-5*x*x+6*x-30);
}

float f2(float x)
{ return (2*x*x*x-4*x*x+3*x-6);
}

float root(float (*fun)(float))
{ float x,x1,x2,y,y1,y2;
  do
  { printf("Input x1,x2:");
    scanf("%f,%f",&x1,&x2);
    y1=(*fun)(x1);
    y2=(*fun)(x2);
  } while(y1*y2>0);
  do
  { x=(x1*y2-x2*y1)/(y2-y1);
    y=(*fun)(x);
    if(y*y1>0)
    { x1=x;
      y1=y;
    }
    else
    { x2=x;
      y2=y;
    }
  }while(fabs(y)>=0.0001);
  return x;
}
