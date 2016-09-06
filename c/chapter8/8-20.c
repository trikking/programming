#include <stdio.h>
void copystr(char *c,char *p);
main()
{ char c[80],*p="I am a student!";
  copystr(c,p);
  puts(c);
}
void copystr(char *c,char *p)
{  while(*c++=*p++);
}
