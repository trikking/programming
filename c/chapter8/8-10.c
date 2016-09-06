#include <stdio.h>
#include <string.h>
main()
{ char c[80],*str1,*str2="Hello!";
  str1=c;
  strcpy(str1,str2);
  puts(str1);
  puts(c);
}
