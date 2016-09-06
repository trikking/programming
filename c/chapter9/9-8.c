#include <stdio.h>
struct code
{ int i;
  char c;
}a[]={{100,'A'},{200,'B'},{300,'C'},{400,'D'}};
main()
{ struct code *p=a;
  printf("%d\t",++p->i);    //输出101
  printf("%c\t",(++p)->c);  //输出'B'
  printf("%d\t",(p++)->i);  //输出200
  printf("%c\t",++p->c);    //输出'D'
  printf("%d\t",p->i++);    //输出300
  printf("%d\t",p->i);      //输出301
  printf("\n");
}
