#include <stdio.h>
union ulong
{ unsigned int a[2];
  unsigned long c;
};
main()
{ union ulong u1;
  printf("input a long int number:");
  scanf("%lu",&u1.c);
  printf("c=%x\n",u1.c);
  printf("前半部分:%d,后半部分:%d\n",u1.a[0],u1.a[1]);
  u1.a[0]=222;
  u1.a[1]=333;
  printf("c=%ld\n",u1.c);
}
