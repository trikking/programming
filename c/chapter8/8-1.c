#include <stdio.h>
main()
{ int a,b,*p1,*p2,*p;
  p1=&a;
  p2=&b;
  printf("Input a,b:");
  scanf("%d,%d",p1,p2);
  if(*p1<*p2)
  {p=p1;p1=p2;p2=p;}
  printf("a=%d,b=%d\n",a,b);
  printf("max=%d,min=%d\n",*p1,*p2);
}
