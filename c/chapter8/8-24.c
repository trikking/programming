#include <stdio.h>
void main(int argc,char *argv[])
{ int i=0;
  while(--argc)
    printf("%s\n",*++argv);
}
