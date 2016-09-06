#include <stdio.h>
#include <stdlib.h>
main()
{ int i,*ip;
  ip=calloc(10,sizeof(int));
  for(i=0;i<10;i++)
    scanf("%d",ip+i);
  for(i=0;i<10;i++)
    printf("%5d",*(ip+i));
  printf("\n");
}
