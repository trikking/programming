#include <stdio.h>
#include <string.h>
main()
{ int i,found=0;
  char s[80];
  char *city[]={"Beijing","Shanghai","Tianjin","chongqing"};
  gets(s);
  for(i=0;i<4 && !found;i++)
    if(strcmp(s,city[i])==0)
      found=1;
  if(found)
    printf("found,index is%d\n",i);
  else
    printf("not found!\n");
}
