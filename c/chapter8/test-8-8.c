#include <stdio.h>
#include <string.h>
void main(int argc,char **argv)
{ char *max=argv[1];
  argc--;
  argv++;
  while(--argc)
    if(strcmp(max,*(++argv))<0)
      max=*argv;
  puts(max);
}
