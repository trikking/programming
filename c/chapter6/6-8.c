#include <stdio.h>
main()
{ char c1[10],c2[26];
  int i;
  for(i=0;i<10;i++)
    c1[i]=i+'0';
  for(i=0;i<26;i++)
    c2[i]=i+'A';
  for(i=0;i<10;i++)
    printf("%c",c1[i]);
  printf("\n");
  for(i=0;i<26;i++)
    printf("%c",c2[i]);
  printf("\n");
}
