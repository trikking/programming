#include <stdio.h>
void main(int argc, char *argv[])
{ int i,max;
  if(argc>1)
  { max=atoi(*++argv);
    for(i=2;i<argc;i++)
      if(max<atoi(*++argv))
        max=atoi(*argv);
    printf("max=%d\n",max);
  }
}
