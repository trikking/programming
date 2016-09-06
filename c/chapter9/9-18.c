#include <stdio.h>
union u
{ char u1;
  int u2;
};
main()
{ union u a={0x9741};
  printf("1.%c %x\n",a.u1,a.u2);
  a.u1='a';
  printf("2.%c %x\n",a.u1,a.u2);
}
