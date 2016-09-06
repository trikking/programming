#include <stdio.h>
main()
{ int a[]={10,20,30,40,50},*p1,*p2;
  float x[]={1.1,2.2,3.3,4.4,5.5},*p3;
  p1=p2=a;
  p3=x;
  printf("p1=%u,*p2=%d\n",p2,*p2);
  printf("p3=%u,*p3=%3.1f\n",p3,*p3);
  p2+=3;
  p3++;
  printf("p2=%u,*p2=%d\n",p2,*p2);
  printf("p3=%u,*p3=%3.1f\n",p3,*p3);
  printf("p2-p1=%d\n",p2-p1);
}
