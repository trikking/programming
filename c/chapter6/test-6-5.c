#include <stdio.h>
#include <string.h>
main()
{ char s1[]="abcd",s2[]="abc";
  int m=strcmp(s1,s2);
  if(m==0)
    printf("s1=s2\n");
  else if(m<0)
    printf("s1<s2\n");
  else 
    printf("s1>s2\n");
}
