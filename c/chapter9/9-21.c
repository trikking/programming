#include <stdio.h>
struct node
{ char *name;
  int age;
};
typedef struct node sn;
main()
{ sn stu;
  stu.name="xiaoming";
  stu.age=20;
  printf("%s,%d\n",stu.name,stu.age);
}
