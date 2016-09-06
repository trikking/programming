#include <stdio.h>
#include <string.h>
#include <strlwr.h>
#include <strupr.h>
main()
{ char str[]="China";
  printf("%d\n",strlen(str));
  printf("%s\n",strlwr(str));
  printf("%s\n",strupr(str));
}
