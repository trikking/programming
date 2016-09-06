#include <stdio.h>
main()
{ char *name[]={"Zhang","Wang","Li",""};
  char **pp=name;
  while(**pp!='\0')
    printf("%s\n",*pp++);
}
