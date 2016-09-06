#include <stdio.h>
void outstr(char **p,int n)
{ int i;
  for(i=0;i<4;i++)
    printf("%s\n",*p++);
}

main()
{ char *s[4]={"Beijing","Shanghai","Tianjin","Chongqing"};
  outstr(s,4);
}
